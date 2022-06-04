#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>
#include <sys/mman.h>

#define PAGESIZE 4096

int mem = 5;

int	main(void)
{
	u_int8_t	*shared_mem = mmap(NULL, PAGESIZE,
									PROT_READ | PROT_WRITE,
									MAP_SHARED | MAP_ANONYMOUS, -1, 0);
	*shared_mem = 34;
	if (fork() == 0)
	{
		*shared_mem = 15;
		mem = 80;
	}
	else
	{
		wait(NULL);
	}
	printf("Not sahred. %i\n", mem);
	printf("Sahred. %i\n", *shared_mem);
}