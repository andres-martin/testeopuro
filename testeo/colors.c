#include "holberton.h"
#define RED "\033[1;31m"
#define YELLOW "\033[1;33m"
#define RESET "\033[0m"
/* red - adds red to STDIN
*/
void red ()
{
	write(STDOUT_FILENO, RED, _strlen(RED));
}
void yellow ()
{
	write(STDOUT_FILENO, YELLOW, _strlen(YELLOW));
}
void reset ()
{
	write(STDOUT_FILENO, RESET, _strlen(RESET));
}
