#include "holberton.h"
#define MAX_LEN 128

void display_splash_screen(FILE *file_ptr)
{
	char read_string[MAX_LEN];
	
	while(fgets(read_string,sizeof(read_string),file_ptr) != NULL)
	       printf("%s",read_string);
}

int bart(void)
{
	char *filename = "bart.txt";
	FILE *fptr = NULL;

	if((fptr = fopen(filename,"r")) == NULL)
	{
		fprintf(stderr,"error opening %s\n",filename);
		return (1);
	}
	display_splash_screen(fptr);
	fclose(fptr);
return (0);
}
