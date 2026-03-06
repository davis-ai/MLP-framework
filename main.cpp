#include <stdio.h>

#define len(x) (sizeof(x) / sizeof(x[0]))

double hidden_layer[2];

void neural_network ( int inputs[], double weights[] ) {


	double bias = 1.0;

	for ( int i = 0; i < 2; i++ )
	{
		for ( int j = 0; j < 2; j++ )
		{
			hidden_layer[i] += inputs[i] * weights[j]; 
		}

		printf("%lf ", hidden_layer[i] += bias);
	}

}

int main() {
	
	int x[] = { 1, 2 };
	double weights[] = { 1.0, 1.0 };
	
	
	neural_network( x, weights );

	printf("\n");
	
	return 0;

}
