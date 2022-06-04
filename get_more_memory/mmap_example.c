#include <sys/mman.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define PAGESIZE 4096

int main(void)
{
	u_int8_t *first = mmap(NULL, PAGESIZE, PROT_READ | PROT_WRITE,
							MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
	u_int8_t *second = mmap(NULL, PAGESIZE, PROT_READ | PROT_WRITE,
							MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
	printf("First: %p\n", first) ;
	printf("Second: %p\n", second);
}