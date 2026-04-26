#include <stdio.h>
#include <stdlib.h>

#define len(x) (sizeof(x) / sizeof(x[0]))

double hidden_layer[2];

double dot_product ( const double[], double[], int );
double* vec_matrix_mult ( int, int, const double[*], double[*][*] );
double* neural_network (  int, int, double[], double[*][*] ); 

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
	print( rA, cB, hidden, "Hidden" );

	rA = 1, cA = 2, cB = 1, bias = 0.5;
	double** output = neural_network( rA, cA, cB, hidden, output_weights, bias );
	print( rA, cB, output, "Output");




	free_mem( rA, hidden );


	return 0;
}






double* neural_network ( int size_input, int row_weight, double Input[], double B[row_weight][size_input] )
{
	double* hidden = vec_mat_mul ( size_input, row_weight, Input, Weight );

	return hidden; 
}


double dot_product ( const double Inp[], double Wgt[], int size ){

	double C = 0;

	for ( int i = 0; i < size; i++ )
       	    C += Inp[i] * Wgt[i];			
	
	return C;

}

double* vec_matrix_mult ( int size_inp, int r_wgt, const double input[size_inp], double weight[r_wgt][size_inp] ) 
{
	double* result = calloc( r_wgt, sizeof(double) );
	
	for ( int i = 0; i < r_wgt; i++ )
	    result[i] = dot_product( size_inp, input, weight[i] )

	return result; 

}

void print( int row_A, int col_B, double** layer, char* layer_type ) {

	printf("%s Layer: \n", layer_type);

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
