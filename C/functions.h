#ifndef FUNCTIONS_H
#define FUNCTIONS_H

typedef struct {

	double *VALUES = NULL;
	int ROWS = 1;
	int COLS = 1;
	
	size_t CAPACITY = ROWS * COLS;
	size_t SIZE = 256;

} vector;





double* neural_network ( vector INPUTS, vector WEIGHTS  )
{
	double* hidden = vec_mat_mult ( INPUTS, WEIGHTS );

	return hidden; 
}


double dot ( vector INPUTS, vector WEIGHTS, int INDEX ) {
	
	if (!(INPUTS.CAPACITY == WEIGHTS.COLS))
		return -1;


	double C = 0;

	for ( int i = 0; i < INPUTS.CAPACITY; i++ )
       	    C += INPUTS.VALUES[i] * WEIGHTS.VALUES[ INDEX * WEIGHTS.COLS + i ];			
	
	return C;

}

vector vec_mat_mult ( vector INPUT, vector WEIGHTS ) 
{
	vector RESULT;
	RESULT.VALUES = calloc( WEIGHTS.ROWS, sizeof(double) );
	
	for ( int i = 0; i < WEIGHTS.ROWS; i++ )
	{	
	    RESULT[i] = dot( INPUT, WEIGHTS, i );
	}
	
	RESULT.COLS = WEIGHT.ROWS;

	return RESULT; 

}

void backProp ( int a, int b, double A[], double B[][3] ) {

	

}

double* delta ( vector PREDICTION, vector OUTPUT) {

	double *PURE_ERROR = (double*) malloc(sizeof(double) * OUTPUT.CAPACITY);
	
	for ( int i = 0; i < OUTPUT.CAPACITY; i++ )
		PURE_ERROR[i] = PREDICTION[i] - OUTPUT[i];
	
	return PURE_ERROR;


}

double* elem_mult ( double A_VECTOR[], double B_VECTOR[], int PRODUCT_SIZE) {

	double* PRODUCT = (double*)malloc(sizeof(double) * PRODUCT_SIZE);
	for ( int i = 0; i < PRODUCT_SIZE; i++ ) PRODUCT[i] = A[i] * B[i];
	return PRODUCT;
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
