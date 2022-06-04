#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <sys/stat.h>

int	main(void)
{
	int		fd;
	char	*file_in_memory;

	fd = open("test.txt", O_RDONLY, S_IRUSR | S_IWUSR);
	struct stat sb;

	if (fstat(fd, &sb) == -1)
		perror("Couldn't get file size");
	printf("file size: %ld\n", sb.st_size);

	file_in_memory = mmap(NULL, sb.st_size, PROT_READ, MAP_PRIVATE, fd, 0);

	for (int i=0; i < sb.st_size; ++i)
		printf("%c", file_in_memory[i]);
	printf("\n");

	munmap(file_in_memory, sb.st_size);
	close(fd);
}