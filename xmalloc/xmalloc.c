#include <stdlib.h>
#include <stdio.h>

void	*xmalloc(size_t size)
{
	void	*result;

	result = malloc(size);
	if (result == NULL)
	{
		printf("error: memory exhausted\n");
		exit(1);
	}
	return (result);
}