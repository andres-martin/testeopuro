#include "holberton.h"

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
	size_t input_count = 0, br = 0;
	int check_path = -1, stat = 0;
	char *path = NULL, *buff = NULL, *buff_tk1 = NULL, **buff_tk = NULL;
	char *pl_holder = "†Shell's Bells† ";

	get_env(&env_cp, env);
	while (1)
	{
		check_path = -1;
		signal(SIGINT, signalhandler);
		if (isatty(STDIN_FILENO))
			red();
			write(STDOUT_FILENO, pl_holder, _strlen(pl_holder));
			reset();
		input_count++;
		read = _getline(&buff, &br, stdin);
		if (read == -1)
		{
			free(buff);
			free_list(env_cp);
			stat > 255 ? stat /= 256 : stat;
			_exit(stat);
		}
		if (buff && buff[0] == '\n')
			continue;
		buff_tk = create_arg_list(buff_tk, buff, " \t\n");
		if (!buff_tk)
			continue;
		if (get_builtin(buff_tk)(buff_tk, &env_cp, buff, argv[0],
					input_count, &stat))
			continue;
		if (buff_tk[0][0] == '.')
		{
			if (buff_tk[0][1] == '/' && !buff_tk[0][2])
			{	stat = 126;
				error_message(*argv, input_count,
						": Permission denied\n", buff_tk);
				free(buff_tk);
				continue; }
			else if (!buff_tk[0][1])
			{	stat = 0;
				free(buff_tk);
				continue; }
		}
		if (buff_tk[0][0] == '/' || buff_tk[0][0] == '.')
		{
			check_path = access(buff_tk[0], F_OK);
			if (check_path == -1)
			{
				stat = 127;
				error_message(*argv, input_count, ": not found\n", buff_tk);
				free(buff_tk);
				continue;
			}
			if (access(buff_tk[0], X_OK) == -1)
			{
				stat = 126;
				error_message(*argv, input_count,
						": Permission denied\n", buff_tk);
				free(buff_tk);
				continue;
			}
		}
		if (check_path == -1)
		{
			path = _getenv("PATH", &env_cp);
			buff_tk1 = path_helper(path, buff_tk, argv[0], input_count, &stat);
			if (buff_tk1 == NULL)
				continue;
		}
		exec_command(argv[0], buff_tk, buff_tk1, buff, check_path, &stat);
	}
	return (0);
}
