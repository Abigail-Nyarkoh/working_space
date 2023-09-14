#include "main.h"

/**
 * get_builtin - Returns a function pointer to a builtin command.
 *
 * @cmd: Command name.
 *
 * Return: Function pointer of the builtin command.
 */
int (*get_builtin(char *cmd))(data_shell *)
{
    builtin_t builtin[] = {
        {"env", _env},
        {"exit", exit_shell},
        {"setenv", _setenv},
        {"unsetenv", _unsetenv},
        {"cd", cd_shell},
        {"help", get_help},
        {NULL, NULL}
    };
    int i;

    for (i = 0; builtin[i].name; i++)
    {
        if (_strcmp(builtin[i].name, cmd) == 0)
            break;
    }

    return (builtin[i].f);
}

/**
 * exit_shell - Exits the shell.
 *
 * @datash: Data relevant (status and args).
 *
 * Return: 0 on success.
 */
int exit_shell(data_shell *datash)
{
    unsigned int ustatus;
    int is_digit;
    int str_len;
    int big_number;

    if (datash->args[1] != NULL)
    {
        ustatus = _atoi(datash->args[1]);
        is_digit = _isdigit(datash->args[1]);
        str_len = _strlen(datash->args[1]);
        big_number = ustatus > (unsigned int)INT_MAX;
        if (!is_digit || str_len > 10 || big_number)
        {
            get_error(datash, 2);
            datash->status = 2;
            return (1);
        }
        datash->status = (ustatus % 256);
    }
    return (0);
}
