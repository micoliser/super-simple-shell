#include "shell.h"

/**
 * get_commands - gets a command
 * @buffer: a buffer
 * @n: size of buffer
 *
 * Return: an array of split tokens of commands
 */
char **get_commands(char *buffer, size_t n)
{
	char **arr;

	_getline(&buffer, &n, stdin);
	arr = _strtok(buffer, " ");

	free(buffer);

	return(arr);
}
