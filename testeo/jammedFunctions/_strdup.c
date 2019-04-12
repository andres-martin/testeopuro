#include "holberton.h"
/**
 * _strdup - duplicates a string
 * @str: string to duplicated
 * Return: pointer to new string
 */
char *_strdup(char *str)
{
	int org_size;
	static char *dup;
	char *dup_offset;

    /* Allocate memory for duplicate */
    org_size = _strlen(str);
    dup = (char *)malloc(sizeof(char)*org_size+1);
    if( dup == NULL)
        return( (char *)NULL);

    /* Copy string */
    dup_offset = dup;
    while(*str)
    {
        *dup_offset = *str;
        dup_offset++;
        str++;
    }
    *dup_offset = '\0';
return(dup);
}
