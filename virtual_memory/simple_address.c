#include <stdio.h>

int	x = 0;

// objdump -t ./a.out
int main(void)
{
	printf("x=%d @ %p\n", x, &x);
}