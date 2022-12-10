#include "shell.h"

/**
 * loop_shell - runs the shell continously
 *
 */
void loop_shell(char **av, char **env, char **arr, pid_t child, int stat, char *line, size_t len)
{
	for (; ;)
	{
		printf("($) ");
		fflush(stdout);
		child = fork();

		if (child == 0)
		{
			arr = get_commands(line, len);
			stat = execve(arr[0], arr, env);
			if (stat == -1)
			{
				printf("(%s) %s: command not found\n", av[0], arr[0]);
				free_arr(arr);
				exit(98);
			}
			free_arr(arr);
		}
		else
		{
			wait(NULL);
		}
	}

}
/**
 * main - main body of the shell
 * @ac: command line argument count
 * @av: pointer to strings of command line arguments
 * @env: environment variables
 *
 * Return: 0 at successful exit
 */
int main(int ac, char *av[], char *env[])
{
	(void) ac;
	char *line = NULL;
	size_t len = 0;
	pid_t child;
	char **arr = NULL;
	int stat;

	loop_shell(av, env, arr, child, stat, line, len);

	return (0);
}
