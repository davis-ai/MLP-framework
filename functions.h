#ifndef FUNCTIONS_H
#define FUNCTIONS_H

double* elem_mult ( const double[], double[], int );
double dot ( const double[], double[], int );
double* vec_mat_mult ( int, int, const double[*], double[*][*] );
double* neural_network (  int, int, double[], double[*][*] ); 

void print( int, double*, char* );
void free_mem ( int, double* );

void backProp ( int, int, double[], double[][*] );
double* delta ( double[], double[], int );










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

double* delta ( double prediction[], double output[], int output_size ) {

	double *pure_error = (double*) malloc(sizeof(double) * output_size );
	
	for ( int i = 0; i < output_size; i++ )
		pure_error[i] = prediction[i] - output[i];
	
	return pure_error;


}

double* elem_mult ( const double A[], double B[], int prod_size ) {

	double* prod = (double*)malloc(sizeof(double) * prod_size);
	for ( int i = 0; i < prod_size; i++ ) prod[i] = A[i] * B[i];
	return prod;
}

void print( int layer_size, double* layer, char* layer_type ) {

	printf("%s : \n", layer_type);

	for ( int i = 0; i < layer_size ; i++ ) 
	    printf( "%lf ", layer[i] );


	printf("\n");



}

void free_mem( int row_A, double* layer) {

	free(layer);

}


#endif
