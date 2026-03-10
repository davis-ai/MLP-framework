#include <stdio.h>
#include <stdlib.h>

double** dot_product (int row_A, int col_A, int col_B,  double A[row_A][col_A], double B[col_A][col_B] ) {

	double** C = (double**)malloc( row_A * sizeof(double*) );

	for ( int i = 0; i < row_A; i++ )
		C[i] = (double*)calloc( col_B,  sizeof(double) );


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



int main () {
	
	double Arr_a[2][2] = { {1.0, 2.0}, {3.0, 4.0}};
	double Arr_b[2][2] = { {5.0, 2.0}, {7.0, 8.0}};

	int rA = 2, cA = 2, cB = 2;

	double** result = dot_product(rA, cA, cB, Arr_a, Arr_b );

	for ( int i = 0; i < rA; i++ )
	{
		for ( int j = 0; j < cB; j++ )
			printf("%lf ", result[i][j] ); 
		printf("\n");
	}

	return 0;

}
