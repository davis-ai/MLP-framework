#include <stdio.h>
#include <stdlib.h>

#define len(x) (sizeof(x) / sizeof(x[0]))

double hidden_layer[2];

double *neural_network ( double* ,size_t, double*, size_t ); 
void print( double*, size_t );



int main() {
	
	double x[] = { 1.0, 2.0 };
	double weights[][] = { { 1.0, 1.0 }, { 1.0, 1.0} } ;
	double output_weights[][] = { {1.0}, {1.0} };	

	size_t inp_len = len(x);
	size_t w_len = len(weights);
	size_t ow_len = len(output_weights);
	
	double* hidden = neural_network( x, inp_len, weights, w_len );
	print( hidden, w_len );

	double* output = neural_network( hidden, w_len, output_weights, ow_len ); 	
	print( output, ow_len );




	free(hidden);
	free(output);	

	return 0;
}






double *neural_network ( double* inputs,size_t inputs_length, double* weights, size_t weights_length ) {

	double *layer = (double*) calloc( weights_length, sizeof(double) );
	
	double bias = 1.0;
	int i = 0;

	while ( i < weights_length )
	{
		int j = 0;

		while ( j < inputs_length ) 
		{
			layer[i] += inputs[j++] * weights[i]; 
			
		}

		layer[i++] += bias;
		
	}

	return layer;
}



void print( double* layer, size_t weights_length ) {

	for ( int i = 0; i < weights_length; i++ )
		printf("%lf ", layer[i]);

	printf("\n\n");



}
