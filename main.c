#include <stdio.h>
#include <stdlib.h>

#define len(x) (sizeof(x) / sizeof(x[0]))

double hidden_layer[2];

double *neural_network ( double* ,size_t, double**, size_t ); 
double** dot_product ( int row_A, int col_A, int col_B, double A[row_A][col_A], double B[col_A][col_B] );

void print( int row_A, int col_B, double** );
void free_mem ( int, double** );


int main() {
	
	double x[][2] = { {1.0, 2.0} };
	double weights[][2] = { { 1.0, 1.0 }, { 1.0, 1.0} } ;

	double output_weights[][2] = { {1.0, 1.0} };	

	int rA = 1, cA = 2, cB = 2;

//	size_t inp_len = len(x);
//	size_t w_len = len(weights[0]);
//	size_t ow_len = len(output_weights[0]);
	
	//double* hidden = neural_network( x, inp_len, weights, w_len );
	double** hidden = dot_product( rA, cA, cB, x, weights );
	print( rA, cB, hidden );

	// double* output = neural_network( hidden, w_len, output_weights, ow_len ); 	
	// print( output, rA, cB );




	free_mem( rA, hidden );


	return 0;
}






double *neural_network ( double* inputs,size_t inputs_length, double** weights, size_t weights_length ) {

	double *layer = (double*) calloc( weights_length, sizeof(double) );
	
	double bias = 1.0;
	int i = 0; while ( i < weights_length ) { int j = 0; while ( j < inputs_length ) {
			layer[i] += inputs[i] * weights[i][j]; 
			
		}

		layer[i++] += bias;
		
	}

	return layer;
}


double** dot_product ( int row_A, int col_A, int col_B, double A[row_A][col_A], double B[col_A][col_B] ){

	double** C = (double**) malloc( row_A * sizeof(double*) );
	for ( int i = 0; i < row_A; i++ ) C[i] = (double*) calloc( col_B, sizeof(double) );

	for ( int i = 0; i < row_A; i++ )
	{
		for ( int j = 0; j < col_B; j++ )
		{
			// C[i][j] = 0;

			for ( int k = 0; k < col_A; k++ )
				C[i][j] += A[i][k] * B[k][j];			
		}
	}
	
	return C;

}

void print( int row_A, int col_B, double** layer ) {

	for ( int i = 0; i < row_A; i++ ) 
	{
		for ( int j = 0; j < col_B; j++ )
			printf("%lf ", layer[i][j]);
		printf("\n");
	}

	printf("\n\n");



}

void free_mem( int row_A, double** layer) {

	for ( int i = 0; i < row_A; i++ )
	free( layer[i] ); free(layer);

}
