#include <stdio.h>
#include <string.h>
#include <stdlib.h>


char **_strtok(char *str, char *del)
{
	char **arr;
	int i, j, k, m, n, delcount, fal;

	i = j = k = m = n = delcount = fal = 0;

	while (str[i])
	{
		if (str[i] == del[j])
		{
			while (del[j])
			{
				if (str[i] != del[j])
				{
					fal = 1;
					break;
				}
				i++, j++;
			}
			if (fal == 0)
				delcount++;
		}
		i++;
		fal = 0, j = 0;
	}

	arr = malloc(sizeof(char *) * (delcount + 2));
	if (!arr)
		return (NULL);
	for (i = 0; i <= delcount; i++)
	{
		arr[i] = malloc(sizeof(char) * 100);
		if (!arr[i])
		{
			for (j = 0; j < i; j++)
				free(arr[j]);
			free(arr);
			return (NULL);
		}
	}

	i = 0, j = 0;

	while (str[i])
	{
		if (str[i] == del[j])
		{
			while (del[j])
			{
				if (str[i] != del[j])
				{
					i--;
					fal = 1;
					break;
				}
				i++, j++;
			}
			if (fal == 0)
			{
				arr[n][m] = '\0';
				n++;
				m = 0;
			}
		}
		arr[n][m] = str[i];
		i++, m++;
		fal = 0, j = 0;
	}
	arr[n][m] = '\0';
	arr[n + 1] = NULL;
	return (arr);
}

void free_arr(char **arr)
{
	int j;

	for (j = 0; arr[j] ; j++)
		free(arr[j]);
	free(arr);
}
