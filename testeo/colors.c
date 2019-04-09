#include "holberton.h"
#define RED "\033[0;31m"
#define YELLOW "\033[1;33m"
#define BOLD_RED "\033[1;31m"
#define GREEN "\033[0;32m"
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
 * bold_red - adds bold red color to stdin
 */
void bold_red(void)
{
	write(STDOUT_FILENO, BOLD_RED, _strlen(BOLD_RED));
}
/**
 * green - adds green color to stdin
 */
void green(void)
{
	write(STDOUT_FILENO, GREEN, _strlen(GREEN));
}
/**
 * reset - resets color to normal
 */
void reset(void)
{
	write(STDOUT_FILENO, RESET, _strlen(RESET));
}
