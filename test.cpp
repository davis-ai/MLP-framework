#include <stdio.h>
#include <stdlib.h>

#define len(x) (sizeof(x) / sizeof(x[0]) )

int main () {

	double n[][1] = { {1.2}, {1.3} };
	size_t length = len(n[0]);


	printf("Length : %zu \n", length);

	return 0;

}
