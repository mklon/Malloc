#include <stdio.h>
#include "headers/malloc.h"

int main() {

	int i = 0;
	while (i <= CELLS_IN_ZONE)
	{
		malloc(1024);
		malloc(500);
		printf("%d\n", i++);
	}
	return 0;
}