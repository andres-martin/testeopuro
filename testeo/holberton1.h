#ifndef DOGO
#define DOGO
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <limits.h>
/**
 * struct listint_s - linked list
 * @a: key value of environment variable
 * @b: value of environment variable
 * @next: Next node
 */
typedef struct listint_s
{
	char *a;
	char *b;
	struct listint_s *next;
} listint_t;
/**
 * struct builtin - Struct builtin
 *
 * @name: Name of builtin
 * @func: Function for the buildint
 */
typedef struct builtin
{
	char *name;
	int (*func)(char **buff_tk, listint_t **env, char *buff,
			char *argv, size_t input_count, int *stat);
} builtin_t;
void exec_command(char *argv, char **buff_tk, char *buff_tk1,
		char *buff, int check_path, int *stat);
void signalhandler(int sig);
/**
 * get_builtin - function to find builtin function
 * @argv: program name
 * @input_count: number of commands processed
 * @buff: buffer value
 * @stat: exit status
 * Return: integer
 */
int (*get_builtin(char **s))(char **buff_tk, listint_t **env,
	char *buff, char *argv, size_t input_count, int *stat);
listint_t *add_node_end(listint_t **head, char *a, char *b);
int delete_node_at_index(listint_t **head, unsigned int index);
void get_env(listint_t **head, char **env);
void free_list(listint_t *head);
char *make_key_val(char *tempstr);
int builtin_cd(char **buff_tk, listint_t **env, char *buff,
		char *argv, size_t input_count, int *stat);
int change_pwd(listint_t **env_cp, char *a, char *add);
int builtin_unsetenv(char **buff_tk, listint_t **env, char *buff,
		char *argv, size_t input_count, int *stat);
int builtin_setenv(char **buff_tk, listint_t **env, char *buff,
		char *argv, size_t input_count, int *stat);
int builtin_notfound(char **buff_tk, listint_t **env, char *buff,
		char *argv, size_t input_count, int *stat);
int builtin_env(char **buff_tk, listint_t **env, char *buff,
		char *argv, size_t input_count, int *stat);
int builtin_exit(char **buff_tk, listint_t **env, char *buff,
		char *argv, size_t input_count, int *stat);
int _strcmp(char *s1, char *s2);
char *_getenv(char *name, listint_t **env);
char *_strcat(char *dest, char *src, char *str);
char *path_helper(char *path, char **buff_tk, char *argv,
		size_t input_count, int *stat);
int _strlen(char *s);
char *num_to_str(size_t n);
int error_message(char *argv, int input_count, char *error, char **buff_tk);
int permi(char **buff_tk, char *argv, int input_count, int *stat);
int check_input(char *buff);
char *_strdup(char *str);
char **create_arg_list(char **buff_tk, char *buff, const char *delim);
/* strtok collection */
unsigned int check_match(char c, const char *str);
char *_strtok(char *str, const char *delim);
/* new prototypes*/
char *_strcpy(char *dest, const char *src);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
void aux_getline(char **p, size_t *n, char *buffer, size_t b);
ssize_t _getline(char **p, size_t *n, FILE *s);
/* colors collection */
void red(void);
void yellow(void);
void reset(void);
#endif