#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>

/**
 * main - finds a file and print some of the file details
 * @ac: argument count
 * @av: argument vector
 *
 * Return: always 0
 */
int main(int ac, char *av[])
{
	struct stat s;

	if (ac != 2)
	{
		printf("Usage: _which filename\n");
		exit(-1);
	}

	if (stat(av[1], &s) == 0)
	{
		printf("Found %s with user ID %ld, group ID %ld and size of %ld bytes\n",
			av[1], (unsigned long)s.st_uid, (unsigned long)s.st_gid, 
			(unsigned long)s.st_size);
	}
	else
	{
		printf("%s not found\n", av[1]);
	}

	return (0);
}
