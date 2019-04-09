#include "holberton.h"
/**
 * help_help - aux function of _help
 * prints msg tp stdout
*/
void help_help(void)
{
	char *msg = "help: help\n\tSee all Shell's Bells builtin commands.\n";

	yellow();
	write(STDOUT_FILENO, msg, _strlen(msg));
	msg = "\n help [BUILTIN NAME]\n\tSee specific information on each ";
	write(STDOUT_FILENO, msg, _strlen(msg));
	msg = "built-in command.\n";
	write(STDOUT_FILENO, msg, _strlen(msg));
}
/**
 * help_all - aux function of _help
 * prints a collection of msgs to stdout
*/
void help_all(void)
{
	char *msg = "Shell's Bells\nThese shell commands are defined internally.\n";

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
/**
 * _help - function _help, prompts a quick help for built-in commands
 * @args: arguments to be prompted help feature
 * Return: Always 0
*/
int _help(char **args)
{
	char *a = "no help command found for this option\n";

	if (!args[1])
		help_all();
	else if (_strcmp(args[1], "cd") == 0)
		help_cd();
	else if (_strcmp(args[1], "exit") == 0)
		help_exit();
	else if (_strcmp(args[1], "env") == 0)
		help_env();
	else if (_strcmp(args[1], "setenv") == 0)
		help_setenv();
	else if (_strcmp(args[1], "unsetenv") == 0)
		help_unsetenv();
	else if (_strcmp(args[1], "help") == 0)
		help_help();
	else
		write(STDERR_FILENO, a, _strlen(a));
return (0);
}
