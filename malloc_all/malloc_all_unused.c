#include <stdio.h>
#include <stdlib.h>

#define ONEGB (1 << 30)

int main (void)
{
	int count = 0;

	while (1)
	{
		if (malloc(ONEGB) == NULL)
		{
			printf("malloc refused after %d GB\n", count);
			// malloc refused after ~131062 GB
			return (0);
		}
		printf("got %d GB\n", ++count);
	}
}