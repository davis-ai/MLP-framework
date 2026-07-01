#include <stdio.h>
#include <stdlib.h>

#define len(x) (sizeof(x) / sizeof(x[0]))


double dot ( const double[], double[], int );
double* vec_mat_mult ( int, int, const double[*], double[*][*] );
double* neural_network (  int, int, double[], double[*][*] ); 

void print( int, double*, char* );
void free_mem ( int, double* );

void backProp ( int, int, double[], double[][*] );
double* delta ( double[], double[] );


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
	double* dlt = delta( pred, output );




	
	print( layer_size, pred, "Hidden");
	print( output_size, dlt, "\nDelta");	



//	free_mem( rA, hidden );
	free( pred );


	return 0;
}






double* neural_network ( int size_input, int row_weight, double Input[], double Weight[row_weight][size_input] )
{
	double* hidden = vec_mat_mult ( size_input, row_weight, Input, Weight );

	return hidden; 
}


double dot ( const double Inp[], double Wgt[], int size) {

	double C = 0;

	for ( int i = 0; i < size; i++ )
       	    C += Inp[i] * Wgt[i];			
	
	return C;

}

double* vec_mat_mult ( int size_inp, int r_wgt, const double input[size_inp], double weight[r_wgt][size_inp] ) 
{
	double* result = calloc( r_wgt, sizeof(double) );
	
	for ( int i = 0; i < r_wgt; i++ )
	    result[i] = dot( input, weight[i], size_inp );

	return result; 

}

void backProp ( int a, int b, double A[], double B[][3] ) {

	

}

double* delta ( double prediction[], double output[] ) {

	double *pure_error = (double*) malloc(sizeof(double) * output_size );
	
	for ( int i = 0; i < output_size; i++ )
		pure_error[i] = prediction[i] - output[i];
	
	return pure_error;


}

void print( int layer_size, double* layer, char* layer_type ) {

	printf("%s Layer: \n", layer_type);

	for ( int i = 0; i < layer_size ; i++ ) 
	    printf( "%lf ", layer[i] );


	printf("\n");



}

void free_mem( int row_A, double* layer) {

	free(layer);

}
