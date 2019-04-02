#include "holberton.h"
/**
 * builtin_cd - change current working directory
 * @buff_tk: tokenzied buffer
 * @env: copy of environment values
 * @buff: input string
 * @argv: program name
 * @input_count: number of commands run so far
 * @stat: exit status
 * Return: always 1
 */
int builtin_cd(char **buff_tk, listint_t **env, char *buff,
		char *argv, size_t input_count, int *stat)
{
	int check_cd, tokens = 0, free_pwd = 0;
	listint_t *temp = *env;
	char *add_str = NULL, *pwd = NULL, *str = NULL, *tmp_str = NULL;
	char home[5] = "$HOME";

	(void) buff;

	while (buff_tk[tokens])
		tokens++;
	pwd = _getenv("PWD", &temp);
	if (pwd == NULL)
	{
		free_pwd = 1;
		pwd = getcwd(pwd, 0);
		change_pwd(env, "PWD", pwd);
	}
	/* for case cd */
	if (tokens == 1 || (tokens >= 2 &&
				(buff_tk[1][0] == '~' ||
				 _strcmp(buff_tk[1], home) == 0)))
	{
		add_str = _getenv("HOME", &temp);
		check_cd = chdir(add_str);
		if (check_cd == 0)
		{
			change_pwd(env, "OLDPWD", pwd);
			change_pwd(env, "PWD", add_str);
		}
	}
	else if (tokens > 1 && buff_tk[1][0] == '-')
	{
		if (buff_tk[1][1] == '\0')
		{
			add_str = _getenv("OLDPWD", &temp);
			if (add_str == NULL)
			{
				add_str = getcwd(add_str, 0);
				change_pwd(env, "OLDPWD", add_str);
				write(STDOUT_FILENO, add_str, _strlen(add_str));
				write(STDOUT_FILENO, "\n", 1);
				free(add_str);
			}
			else if (chdir(add_str) == 0)
			{
				change_pwd(env, "OLDPWD", pwd);
				add_str = NULL;
				add_str = getcwd(add_str, 0);
				change_pwd(env, "PWD", add_str);
				write(STDOUT_FILENO, add_str, _strlen(add_str));
				write(STDOUT_FILENO, "\n", 1);
				free(add_str);
			}
		}
		else if (buff_tk[1][1] != '\0')
		{
			tmp_str = malloc(sizeof(char) * 3);
			tmp_str[0] = buff_tk[1][0];
			tmp_str[1] = buff_tk[1][1];
			tmp_str[2] = '\0';
			str = _strcat(": Illegal option ", tmp_str, "\n");
			error_message(argv, input_count, str, buff_tk);
			free(tmp_str);
			free(str);
			free(buff_tk);
			buff_tk = NULL;
			*stat = 2;
			return (1);
		}
	}
	else if (tokens > 1)
	{
		check_cd = chdir(buff_tk[1]);
		if (check_cd == 0)
		{
			add_str = getcwd(add_str, 0);
			change_pwd(env, "OLDPWD", pwd);
			change_pwd(env, "PWD", add_str);
			free(add_str);

		}
		else if (check_cd == -1)
		{
			str = _strcat(": can't cd to ", buff_tk[1], "\n");
			error_message(argv, input_count, str, buff_tk);
			free(str);
			*stat = 2;
			free(buff_tk);
			buff_tk = NULL;
			return (1);
		}
	}
	if (free_pwd == 1)
		free(pwd);
	free(buff_tk);
	return (1);
}
