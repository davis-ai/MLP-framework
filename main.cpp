#include <stdio.h>
#include <stdlib.h>

#define len(x) (sizeof(x) / sizeof(x[0]))

double hidden_layer[2];
void print( double*);


double *neural_network ( double* inputs, double* weights ) {

	size_t layer_length = len(weights);
	size_t inputs_length = len(inputs);
	 

	double *layer = (double*) calloc( layer_length, sizeof(double) );
	
	double bias = 1.0;
	int i = 0;

	while ( i < layer_length   )
	{
		int j = 0;

		while ( j < inputs_length ) 
		{
			layer[i] += inputs[i] * weights[j++]; 
		}

		layer[i++] += bias;
	}

	return layer;
}

int main() {
	
	double x[] = { 1.0, 2.0 };
	double weights[] = { 1.0, 1.0 };
	double output_weights[] = { 1.0 };	
	
	double* hidden = neural_network( x, weights );
	print( hidden );

	double* output = neural_network( hidden, output_weights ); 	
	print( output );




	free(hidden);
	free(output);	

	return 0;
}






void print( double* layer ) {

	for ( int i = 0; i < len(layer); i++ )
		printf("%lf ", layer[i]);

	printf("\n\n");



}
