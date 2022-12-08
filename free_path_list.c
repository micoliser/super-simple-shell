#include "main.h"

/**
 * free_list - frees a path_l list
 * @head: pointer to list
 *
 * Return: void
 */
void free_list(path_l *head)
{
	path_l *temp = head, *temp2;

	if (head)
	{
		while (temp->next)
		{
			temp2 = temp;
			temp = temp->next;
			free(temp2->str);
			free(temp2);
		}

		free(temp->str);
		free(temp);
	}
}
