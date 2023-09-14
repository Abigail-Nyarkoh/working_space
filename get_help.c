#include "main.h"

/**
 * show_help - Display help messages based on the provided command.
 *
 * @datash: Data structure (args and input).
 *
 * Return: Always returns 0.
 */
int show_help(data_shell *datash)
{
    if (datash->args[1] == NULL)
        display_general_help();
    else if (_strcmp(datash->args[1], "setenv") == 0)
        display_setenv_help();
    else if (_strcmp(datash->args[1], "env") == 0)
        display_env_help();
    else if (_strcmp(datash->args[1], "unsetenv") == 0)
        display_unsetenv_help();
    else if (_strcmp(datash->args[1], "help") == 0)
        display_help();
    else if (_strcmp(datash->args[1], "exit") == 0)
        display_exit_help();
    else if (_strcmp(datash->args[1], "cd") == 0)
        display_cd_help();
    else if (_strcmp(datash->args[1], "alias") == 0)
        display_alias_help();
    else
        write(STDERR_FILENO, datash->args[0], _strlen(datash->args[0]));

    datash->status = 0;
    return (0);
}

