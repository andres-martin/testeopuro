#include "holberton.h"
#define MAX_LEN 128
void aux_shell(void)
{
	char *pl_holder = "†Shell's Bells† ";

	signal(SIGINT, signalhandler);
	if (isatty(STDIN_FILENO))
	{
		red();
		write(STDOUT_FILENO, pl_holder, _strlen(pl_holder));
		reset();
	}
}

void rd_shell(ssize_t read, char *buff, int stat, listint_t *env_cp)
{
	if (read == -1)
	{
		free(buff);
		free_list(env_cp);
		stat > 255 ? stat /= 256 : stat;
		_exit(stat);
	}
}
void stat_helper(int stat, char *s, char **argv, char **buff_tk,
size_t in_count)
{
	stat = stat;
	error_message(*argv, in_count, s, buff_tk);
	free(buff_tk);
}


void display_splash_screen(FILE *file_ptr)
{
    char read_string[MAX_LEN];
    while(fgets(read_string,sizeof(read_string),file_ptr) != NULL)
        write(STDOUT_FILENO, read_string, _strlen(read_string));
}
/**
 * main - main shell function
 * @argc: number of parameters
 * @argv: arguments list
 * @env: environment variables
 * Return: always 0
 */
int main(int argc __attribute__((unused)), char **argv, char **env)
{
	listint_t *env_cp = NULL;
	ssize_t read;
	size_t in_count = 0, br = 0;
	int check_path = -1, stat = 0;
	char *path = NULL, *buff = NULL, *buff_tk1 = NULL, **buff_tk = NULL;
	char *filename = "welcome.txt";
    	FILE *fptr = NULL;

	if((fptr = fopen(filename,"r")) == NULL)
    	{
        fprintf(stderr,"error opening %s\n",filename);
        return 1;
   	}
    	display_splash_screen(fptr);
    	fclose(fptr);
	get_env(&env_cp, env);
	for (; 1; in_count++)
	{
		check_path = -1;
		aux_shell();
		read = _getline(&buff, &br, stdin);
		rd_shell(read, buff, stat, env_cp);
		if (buff && buff[0] == '\n')
			continue;
		buff_tk = create_arg_list(buff_tk, buff, " \t\n");
		if (!buff_tk)
			continue;
		if (get_builtin(buff_tk)(buff_tk, &env_cp, buff, argv[0], in_count, &stat))
			continue;
		if (buff_tk[0][0] == '.')
		{
			if (buff_tk[0][1] == '/' && !buff_tk[0][2])
			{ stat_helper(126, ": Permission denied\n", argv, buff_tk, in_count);
				continue; }
			else if (!buff_tk[0][1])
			{	stat = 0;
				free(buff_tk);
				continue; }	}
		if (buff_tk[0][0] == '/' || buff_tk[0][0] == '.')
		{	check_path = access(buff_tk[0], F_OK);
			if (check_path == -1)
			{ stat_helper(127, ": not found\n", argv, buff_tk, in_count);
				continue; }
			if (access(buff_tk[0], X_OK) == -1)
			{ stat_helper(126, ": Permission denied\n", argv, buff_tk, in_count);
				continue; }	}
		if (check_path == -1)
		{	path = _getenv("PATH", &env_cp);
			buff_tk1 = path_helper(path, buff_tk, argv[0], in_count, &stat);
			if (buff_tk1 == NULL)
				continue; }
		exec_command(argv[0], buff_tk, buff_tk1, buff, check_path, &stat);
	}
return (0);
}
