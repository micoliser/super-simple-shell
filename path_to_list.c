#include "main.h"

extern char **environ;

/**
 * path_to_list - creates a linked list of each directory contained in the PATH 
 * environment variable
 *
 * Return: void
 */
path_l *path_to_list(void)
{
	char path[5] = "PATH";
	int i, j, k, check;
	path_l *head = NULL;
	char *str;

	for (i = 0; environ[i]; i++)
	{
		j = 0, check = 0;
		while (environ[i][j] != '=' && path[j] != '\0')
		{
			if (environ[i][j] != path[j])
			{
				check = 1;
				break;
			}
			j++;

		}
		k = 0;
		if (check == 0)
		{
			j++;
			while(environ[i][j])
			{
				if (environ[i][j] == ':')
				{
					str[k] = '\0';
					k = 0;
					add_node_end(&head, str);
					free(str);

				}
				else
				{
					if (k == 0)
					{
						str = malloc(sizeof(char) * 150);
						if (!str)
							exit(98);
					}
					str[k] = environ[i][j];
					k++;
				}
				j++;
			}

			str[k] = '\0';
			add_node_end(&head, str);
			free(str);
			break;
		}
	}
	return (head);

}

/**
 * main - check the function
 *
 * Return: 0
 */
int main(void)
{
	path_l *list;

	list = path_to_list();
	print_list(list);

	free_list(list);

	return (0);
}
