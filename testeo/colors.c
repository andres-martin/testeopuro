#include "holberton.h"
#define RED "\033[1;31m"
#define YELLOW "\033[1;33m"
#define RESET "\033[0m"
/**
 * red - adds red color to stdin
 */
void red(void)
{
	write(STDOUT_FILENO, RED, _strlen(RED));
}
/**
 * yellow - adds yellow color to stdin
 */
void yellow(void)
{
	write(STDOUT_FILENO, YELLOW, _strlen(YELLOW));
}
/**
 * reset - resets color to normal
 */
void reset(void)
{
	write(STDOUT_FILENO, RESET, _strlen(RESET));
}
