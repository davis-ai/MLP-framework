#include <stdio.h>

void mod ( int* x ) { *x = 20; }


int main () {

	int num = 10;

	mod (&num);

	printf("%d \n", num);

	return 0;

}
