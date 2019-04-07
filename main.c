#include <stdio.h>
#include "headers/malloc.h"


int main() {
	int		i = 0;
	void	*ptr;

	while (++i <= CELLS_IN_ZONE/10)
	{
		ptr = malloc(500);
		ptr = malloc(1000);
		ptr = malloc(10000);
	}
	show_alloc_mem();
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