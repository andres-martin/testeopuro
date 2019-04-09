#include "holberton.h"
void help_help(void)
{
	char *msg = "help: help\n\tSee all  Shell's bells builtin commands.\n";

	write(STDOUT_FILENO, msg, _strlen(msg));
	msg = "\n help [BUILTIN NAME]\n\tSee specific information on each ";
	write(STDOUT_FILENO, msg, _strlen(msg));
	msg = "builtin command.\n";
	write(STDOUT_FILENO, msg, _strlen(msg));
}

void help_all(void)
{
	char *msg = "Shellsbells\nThese shell commands are defined internally.\n";

	write(STDOUT_FILENO, msg, _strlen(msg));
	msg = "Type 'help' to see this list.\nType 'help name' to find ";
	write(STDOUT_FILENO, msg, _strlen(msg));
	msg = "out more about the function 'name'.\n\n alias \t";
	write(STDOUT_FILENO, msg, _strlen(msg));
	msg = "alias [NAME[='VALUE'] ...]\n cd \tcd ";
	write(STDOUT_FILENO, msg, _strlen(msg));
	msg = "[DIRECTORY]\n exit \texit [STATUS]\n env \tenv";
	write(STDOUT_FILENO, msg, _strlen(msg));
	msg = "\n setenv \tsetenv [VARIABLE] [VALUE]\n unsetenv\t";
	write(STDOUT_FILENO, msg, _strlen(msg));
	msg = "unsetenv [VARIABLE]\n";
	write(STDOUT_FILENO, msg, _strlen(msg));
}

int _help(char **args)
{
	char *a;

	if (!args[0])
		help_all();
	else if (_strcmp(args[0], "cd") == 0)
		help_cd();
	else if (_strcmp(args[0], "exit") == 0)
		help_exit();
	else if (_strcmp(args[0], "env") == 0)
		help_env();
	else if (_strcmp(args[0], "setenv") == 0)
		help_setenv();
	else if (_strcmp(args[0], "unsetenv") == 0)
		help_unsetenv();
	else if (_strcmp(args[0], "help") == 0)
		help_help();
	else
		write(STDERR_FILENO, a, _strlen(a));
return (0);
}
