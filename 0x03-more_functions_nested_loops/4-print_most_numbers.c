#include "holberton.h"
/**
 * print_most_numbers - check the code for Holberton School students.
 *
 * Return: Always 0.
 */
void print_most_numbers(void)
{
	int i;

	for (i = '0' ; i <= '9' ; i++)
	{
		if ((i >= '0' && i < '2') || (i == '3') || (i >= '5' && i <= '9'))
		_putchar (i);
	}
	_putchar (10);
}
