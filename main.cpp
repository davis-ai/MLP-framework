#include <stdio.h>

int main() {
	
	int x[] = { 1, 2 };
	double weights[] = { 1.0, 1.0 };
	double bias = 1.0;
	
	double hidden_layer[2];

	for ( int i = 0; i < 2; i++ )
	{
		for ( int j = 0; j < 2; j++ )
		{
			hidden_layer[i] += x[i] * weights[j]; 
		}

		printf("%lf ", hidden_layer[i] += bias);
	}

	printf("\n");
	
	return 0;

}
