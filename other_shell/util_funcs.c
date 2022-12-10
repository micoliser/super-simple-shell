#include "shell.h"

/**
 * my_strlen - gets the length of a string
 * @str: string to count
 * Return: no of chars in the string
 */
int my_strlen(char *str)
{
	int len;

	for (len = 0; str[len] != '\0'; len++)
		;
	return (len);
}


/**
 * my_strcpy - copies a string to another
 * @destination: container to insert copy
 * @source: string to be copied
 * Return: a pointer to the destination
 */
char *my_strcpy(char *destination, char *source)
{
	int i;

	for (i = 0; source[i] != '\0'; i++)
		destination[i] = source[i];

	destination[i] = '\0';
	return (destination);
}

/**
 * my_strcat - appends source to dest
 * @destination: an existing string
 * @source: string to be appended to destination
 * Return: a pointer to the destination
 */
char *my_strcat(char *destination, char *source)
{
	int i, j;

	for (i = 0; destination[i] != '\0'; i++)
		;

	for (j = 0; source[j] != '\0'; j++, i++)
		destination[i] = source[j];

	destination[i] = '\0';
	return (destination);
}

/**
 * my_strcmp - compares two strings
 * @str1: string1
 * @str2: string 2 to compare with
 * Return: int representing if true or not
 */
int my_strcmp(char *str1, char *str2)
{
	int n, d;

	for (n = 0, d = 0; (str1[n] != '\0' || str2[n] != '\0'); n++)
	{
		d = str1[n] - str2[n];
		if (d != 0)
			break;
	}

	if (d < 0)
		return (-1);
	else if (d > 0)
		return (1);

	return (d);
}

/**
 * my_strdup - duplicates a string
 * @str: to be duplicated
 * Return: the newly created string
 */
char *my_strdup(char *str)
{
	char *dup;
	size_t len;

	len = my_strlen(str);
	dup = malloc(sizeof(char) * (len + 1));
	if (dup == NULL)
		return (NULL);
	my_memcpy(dup, str, len + 1);
	return (dup);
}

/**
 * my_isdigit - check if a string contains digits only
 * @nstr: string to be checked
 * Return: 1 if digit, 0 if not digit
 */
int my_isdigit(char *nstr)
{
	int i;

	for (i = 0; nstr[i] != '\0' ; i++)
	{
		if (nstr[i] < 48 || nstr[i] > 57)
			return (0);
	}

	return (1);
}

/**
 * my_memcpy - copies data to another pointer with casts
 * @dest: dest to paste data
 * @src: source to copy data from
 * @len: length of data to copy
 * Return: nothing
 */
void my_memcpy(void *dest, const void *src, unsigned int size)
{
	char *ptr = (char *)src;
	char *new = (char *)dest;
	unsigned int i;

	for (i = 0; i < size; i++)
		new[i] = ptr[i];
}

/**
 * reverse_str - reverses a string
 * @string: to be reversed
 * Return: a pointer to the destination
 */
void reverse_str(char *string)
{
	char temp;
	int i, j, k;

	for (i = 0; string[i] != '\0'; i++)
		;

	for (j = 0; j < (i - 1); j++)
	{
		for (k = j + 1; k > 0; k--)
		{
			temp = string[k];
			string[k] = string[k - 1];
			string[k - 1] = temp;
		}
	}
}
