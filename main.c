#include <stdio.h>
#include "headers/malloc.h"

int main() {

	int i = 0;
	char	*ptr;

	ptr = malloc(50000);
	ptr = ft_strcpy(ptr, "FUCK YEAH!!!!!");
	printf("%s", ptr);

	free(ptr + 100000);
	return 0;
}

/*
	ptr = ft_strcpy(ptr, "FUCK YEAH!!!!!");
	printf("%s", ptr);
*/


/*
while (++i <= CELLS_IN_ZONE*1000)
	{

		ptr = malloc(500);
		ptr = malloc(1000);
		ptr = malloc(10000);
		printf("%d\n", i);
	}
*/