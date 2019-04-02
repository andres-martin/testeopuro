#include "holberton.h"
/**
 * builtin_setenv - sets or updates environment variable
 * @buff_tk: tokenized buffer
 * @env: linked list of environment variable
 * @buff: input buffer
 * @argv: program name
 * @input_count: number of commands executed
 * @stat: exit code
 * Return: 0 if successful 1 otherwise
 */
int builtin_setenv(char **buff_tk, listint_t **env, char *buff,
                char *argv, size_t input_count, int *stat)
{
        listint_t *temp = *env;
        char *tempstr;
        int  tokens = 0;
        char *temp_val, *temp_key;

        (void) buff;

        while (buff_tk[tokens])
                tokens++;
        if (tokens < 3)
        {
                /* print error message and return (1) */
                *stat = 0;
                error_message(argv, input_count, ": Invalid Argument for setenv\n", buff_tk);
        }
        else
        {
                tempstr = _strcat(buff_tk[1], "=", buff_tk[2]);
                temp_val = make_key_val(tempstr);
                temp_key = tempstr;
                while (temp && _strcmp(buff_tk[1], temp->a))
                        temp = temp->next;
                if (temp)
                {
                        free(temp->a);
                        temp->a = temp_key;
                        temp->b = temp_val;
                }
                else
                {
                        *env = add_node_end(env, temp_key, temp_val);
                }
                *stat = 0;
        }
        free(buff_tk);
        return (1);
}
