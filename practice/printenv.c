#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern char **environ;

/**
 * main - prints enviroments using both the environ global variable
 * and the ev variable in main
 * @ac: argument count (unused)
 * @av: argument vector (unused)
 * @ev: environment
 *
 * Return: always 0
 */
int main(int __attribute__((unused)) ac, char __attribute__((unused)) **av, char **ev)
{
	int i;

	for (i = 0; ev[i]; i++)
		printf("Env: %s\n", ev[i]);
	for (i = 0; environ[i]; i++)
		printf("Environ: %s\n", environ[i]);

	return 0;
}

