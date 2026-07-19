#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

#define len(x) (sizeof(x) / sizeof(x[0]))


int output_size = 3;

int main() {

	double x[] =  { 1.0, 2.0 };	
	double output[] = { 3.0, 1.0, 0 };

	int inp_size = 2;
	int layer_count= 3;

	double ih_wgts[][2] = { { .1, .2 }, { .3, .4 }, { .5, .2 } }; int layer_size = 3;
//	double ho_wgts[][2] = { { .3, .4 }, { .5, .2 } }; int layer_size = 2;

//	double ( *Weights[ layer_count ] )[ inp_size] = { ih_wgts, ho_wgts };


	double* pred = neural_network ( inp_size, layer_size, x, ih_wgts );
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







