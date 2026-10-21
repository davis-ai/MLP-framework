#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

#define len(x) (sizeof(x) / sizeof(x[0]))

#define IH_ROWS 3
#define IH_COLUMNS 2

#define HO_ROWS 2
#define HO_COLUMNS 2

int output_size = 3;

int main() {

	vector INPUTS, OUTPUT;
	INPUTS.COLS = 2; INPUT.VALUES =  { 1.0, 2.0 };	
	OUTPUT.COLS = 3; OUTPUT.VALUES = { 3.0, 1.0, 0 };


	vector IH_WEIGHTS,   HO_WEIGHTS;
	IH_WEIGHTS.ROWS = 3, IH_WEIGHTS.COLS = 2;
	HO_WEIGHTS.ROWS = 2, HO_WEIGHTS.COLS = 2;

	IH_WEIGHTS.VALUES = { 
		 .1, .2,
		 .3, .4, 
		 .5, .2 
			    };

	HO_WEIGHTS.VALUES = {  
		.3, .4   
		.5, .2  
			   }; 


	double* pred = neural_network ( INPUTS, IH_WEIGHTS );
	double alpha = 0.001;

	for ( int i = 0; i < 1000; i++ )
	{
		

		double* dlt = delta( pred, output, output_size );
		double* error = elem_mult(dlt, dlt, output_size);
		
		for ( int l = 0; l < layer_size; l++ )
			for ( int j = 0; j < inp_size; j++ )
				ih_wgts[l][j] -= elem_mult(dlt, x, output_size)[l] * alpha;

		pred = neural_network ( inp_size, layer_size, x, ih_wgts );
		print( layer_size, pred, "\nOutput");
		print( output_size, error, "Error");	

	}




	
	



//	free_mem( rA, hidden );
	free( pred );


	return 0;
}







