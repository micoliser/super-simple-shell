#include "shell.h"

/**
 * _getsline - gets a line of input from a file
 * @buffer: address of buffer
 * @n: pointer to size of buffer
 * @file: the file to read from
 *
 * Return: number of characters read
 */
ssize_t _getline(char **buffer, size_t *n, FILE *file)
{
	int fd;
	char *tbuf, *buf;
	long int r = 10;
	size_t size = 10, i = 0, j = 0;

	buf = malloc(sizeof(char) * size);
	if (!buf)
		return (-1);

	fd = fileno(file);
	while (r == 10)
	{
		tbuf = malloc(sizeof(char) * 10);
		r = read(fd, tbuf, 10);
		if (r < 0)
			return (-1);
		if (size > 10)
		{
			buf = realloc(buf, sizeof(char) * size);
		}
		while (tbuf[i])
		{
			if (tbuf[i] == '\n')
				break;
			buf[j] = tbuf[i];
			i++;
			j++;
		}
		i = 0;
		size += 10;
		free(tbuf);
	}
	buf[j] = '\0';
	*buffer = buf;
	*n = size;
	close(fd);
	return (r);
}
