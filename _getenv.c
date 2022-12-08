#include "main.h"

extern char **environ;

/**
 * _getenv - gets the value of an environment variable
 * @name: name of variable
 *
 * Return: pointer to the value
 */
char *_getenv(const char *name)
{
	unsigned int i;
	int n;
	char **envar;
	char *value;

	for (i = 0; environ[i]; i++)
	{
		envar = _strtok(environ[i], "=");
		if ((n = strcmp(envar[0], name)) == 0)
		{
			if (envar[1])
			{
				value = malloc(sizeof(char) * (strlen(envar[1]) + 1));
				if (!value)
					return (NULL);

				strcpy(value, envar[1]);
				free_arr(envar);
				return (value);
			}
			else
			{
				printf("No value for variable %s\n", envar[0]);
				return (NULL);
			}
		}
		free_arr(envar);
	}
	return (NULL);
}


/**
 * main - searches for the value of all environment variables and prints them
 * @ac: argument count (unused)
 * @av: argument vector (unused)
 * @env: environment
 *
 * Return: always 0
 */
int main(int __attribute__((unused)) ac, char __attribute__((unused)) *av[], char *env[])
{
	unsigned int i, j;
	char *value;
	char *str;

	for (i = 0; env[i]; i++)
	{
		j = 0;

		str = malloc(sizeof(char) * 100);
		if (!str)
			exit(98);

		while (env[i][j] != '=')
		{
			str[j] = env[i][j];
			j++;
		}
		str[j] = '\0';

		value = _getenv(str);
		if (value)
			printf("%s\n", value);

		free(value);
		free(str);
	}

	return (0);
}
