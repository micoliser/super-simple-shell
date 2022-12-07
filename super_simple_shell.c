#include "main.h"

/**
 * main - creates a simple shell
 *
 * Return: 0
 */
int main(void)
{
	char *line = NULL;
	size_t len = 0;
	pid_t child;
	char **arr;
	int stat;

	for (; ;)
	{
		printf("$micolisershell ");
		fflush(stdout);
		child = fork();

		if (child == 0)
		{
			arr = get_commands(line, len);
			stat = execve(arr[0], arr, NULL);
			if (stat == -1)
			{
				printf("Invalid command %s\n", arr[0]);
				exit(98);
			}
		}
		else
		{
			wait(NULL);
		}
	}


	return (0);
}
