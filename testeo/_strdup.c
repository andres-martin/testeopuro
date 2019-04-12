#include "holberton.h"
/**
 * _strdup - duplicates a string
 * @str: string to be duplicated
 * Return: pointer to new string
 */
char *_strdup(char *str)
{
	char *dstr;
	int size, i;

	if (!str)
		return (NULL);
	for (size = 0; str[size] != '\0'; size++)
	{
	}
	dstr = malloc(sizeof(char) * (size + 1));

	if (dstr == NULL)
		return (NULL);
	for (i = 0; i < size; i++)
	{
		dstr[i] = str[i];
	}
	dstr[i] = '\0';
return (dstr);
}

