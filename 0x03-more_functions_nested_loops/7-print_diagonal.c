#include "holberton.h"
/**
 * print_line - check the code for Holberton School students.
 * @n : check
 * Return: Always 0.
 */
void print_diagonal(int n)
{
	int i, j;
		for (i = 0 ; i < n ; i++)
		{
			if (n > 0)
			for (j = 0 ; j <= i ; j++)
				_putchar (' ');
				_putchar ('\\');
				_putchar (10);
		}
		if (n <= 0)
		_putchar (10);
}
