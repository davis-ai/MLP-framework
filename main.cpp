#include <stdio.h>
#include <stdlib.h>

#define len(x) (sizeof(x) / sizeof(x[0]))

double hidden_layer[2];

double *neural_network ( int inputs[], double weights[] ) {

	double *layer = (double*) calloc( 2, sizeof(double) );
	
	double bias = 1.0;

	for ( int i = 0; i < 2; i++ )
	{
		for ( int j = 0; j < 2; j++ )
		{
			layer[i] += inputs[i] * weights[j]; 
		}

		layer[i] += bias;
	}

	return layer;
}

int main() {
	
	int x[] = { 1, 2 };
	double weights[] = { 1.0, 1.0 };
	
	
	double* hidden = neural_network( x, weights );
	
	for ( int i = 0; i < 2; i++ )
		printf("%lf ", hidden[i]);

	printf("\n");
	
	return 0;

}
