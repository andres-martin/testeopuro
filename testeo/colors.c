#include "holberton.h"
/* red - adds red to STDIN
*/
void red ()
{
	printf("\033[1;31m");
}
void yellow ()
{
	printf("\033[1;33m");
}
void reset ()
{
	printf("\033[0m");
}
