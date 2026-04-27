#include <stdio.h>
#include <stdlib.h>

#define len(x) (sizeof(x) / sizeof(x[0]))

double hidden_layer[2];

double dot_product ( int, const double[], double[] );
double* vec_matrix_mult ( int, int, const double[*], double[*][*] );
double* neural_network (  int, int, double[], double[*][*] ); 

void print( int, double*, char* );
void free_mem ( int, double** );


int main() {
	/*
	
		inputs = [ x1, x2 ]

			
		weights = [       h1    h2
			      [ w1.x1, w1.x1],
			      [ w2.x2, w2.x2]
			  ]
	
	*/	

	double x[] =  { 1.0, 2.0 };	

	int inp_size = 2;
	int layer_count= 3;

	double ih_wgts[][3] = { { .1, .2 }, { .3, .4 }, { .5, .2 } }; int layer_size = 3;
//	double ho_wgts[][2] = { { .3, .4 }, { .5, .2 } }; int layer_size = 2;

//	double ( *Weights[ layer_count ] )[ inp_size] = { ih_wgts, ho_wgts };

	double* pred = neural_network ( inp_size, layer_size, x, ih_wgts );

	
	print( layer_size, pred, "Hidden");




//	free_mem( rA, hidden );
	free( pred );


	return 0;
}






double* neural_network ( int size_input, int row_weight, double Input[], double Weight[row_weight][size_input] )
{
	double* hidden = vec_matrix_mult ( size_input, row_weight, Input, Weight );

	return hidden; 
}


double dot_product ( int size, const double Inp[], double Wgt[] ){

	double C = 0;

	for ( int i = 0; i < size; i++ )
       	    C += Inp[i] * Wgt[i];			
	
	return C;

}

double* vec_matrix_mult ( int size_inp, int r_wgt, const double input[size_inp], double weight[r_wgt][size_inp] ) 
{
	double* result = calloc( r_wgt, sizeof(double) );
	
	for ( int i = 0; i < r_wgt; i++ )
	    result[i] = dot_product( size_inp, input, weight[i] );

	return result; 

}

void print( int layer_size, double* layer, char* layer_type ) {

	printf("%s Layer: \n", layer_type);

	for ( int i = 0; i < layer_size ; i++ ) 
	    printf( "%lf ", layer[i] );


	printf("\n");



}

void free_mem( int row_A, double** layer) {

	for ( int i = 0; i < row_A; i++ )
	free( layer[i] ); free(layer);

}
