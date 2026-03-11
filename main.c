#include <stdio.h>
#include <stdlib.h>

#define len(x) (sizeof(x) / sizeof(x[0]))

double hidden_layer[2];

double** neural_network ( int, int, int, double[*][*], double[*][*], double ); 
double** dot_product ( int, int, int, double[*][*], double[*][*] );

void print( int row_A, int col_B, double**, char* );
void free_mem ( int, double** );


int main() {
	/*
	
		inputs = [ x1, x2 ]

			
		weights = [       h1    h2
			      [ w1.x1, w1.x1],
			      [ w2.x2, w2.x2]
			  ]
	
	*/	

	double x[][2] = { {1.0, 2.0} };
	double weights[][2] = { { 1.0, 1.0 }, { 1.0, 1.0} } ;

	double output_weights[][1] = { {1.0}, {1.0} };	

	int rA = 1, cA = 2, cB = 2;
	double bias = 1.0;

	
	double** hidden = neural_network( rA, cA, cB, x, weights, bias );
	print( rA, cB, hidden, "Hidde" );

	rA = 1, cA = 2, cB = 1, bias = 0.5;
	double** output = neural_network( rA, cA, cB, hidden, output_weights, bias );
	print( rA, cB, output, "Output");




	free_mem( rA, hidden );


	return 0;
}






double** neural_network ( int row_A, int col_A, int col_B, double A[row_A][col_A], double B[col_A][col_B], double bias ) {

	double** layer = dot_product( row_A, col_A, col_B, A, B);

	for ( int i = 0; i < row_A; i++ )
		for ( int j = 0; j < col_B; j++ )
			layer[i][j] += bias;
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

void print( int row_A, int col_B, double** layer, char* layer_type ) {

	printf("%s layer \n", layer_type);

	for ( int i = 0; i < row_A; i++ ) 
	{
		for ( int j = 0; j < col_B; j++ )
			printf("%lf ", layer[i][j]);
		printf("\n");
	}

	printf("\n");



}

void free_mem( int row_A, double** layer) {

	for ( int i = 0; i < row_A; i++ )
	free( layer[i] ); free(layer);

}
