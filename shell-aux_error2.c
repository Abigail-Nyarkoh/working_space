#include "main.h"

/**
 * error_env - error message for env in get_env.
 * @datash: data relevant (counter, arguments)
 * Return: error message.
 */
char *error_env(data_shell *datash)
{
    int length;
    char *error;
    char *ver_str;
    char *msg;

    ver_str = aux_itoa(datash->counter);
    msg = ": Unable to add/remove from environment\n";
    length = _strlen(datash->av[0]) + _strlen(ver_str);
    length += _strlen(datash->args[0]) + _strlen(msg) + 4;
    error = malloc(sizeof(char) * (length + 1));

    if (error == 0)
    {
        free(error);
        free(ver_str);
        return (NULL);
    }

    char buffer[1024];
    int pos = 0;

    pos += _strcpy(buffer + pos, datash->av[0]);
    pos += _strcpy(buffer + pos, ": ");
    pos += _strcpy(buffer + pos, ver_str);
    pos += _strcpy(buffer + pos, ": ");
    pos += _strcpy(buffer + pos, datash->args[0]);
    pos += _strcpy(buffer + pos, msg);

    pos += _strcpy(buffer + pos, "\0");
    write(STDOUT_FILENO, buffer, _strlen(buffer));
    free(ver_str);

    return (error);
}

/**
 * error_path_126 - error message for path and failure denied permission.
 * @datash: data relevant (counter, arguments).
 * Return: The error string.
 */
char *error_path_126(data_shell *datash)
{
    int length;
    char *ver_str;
    char *error;

    ver_str = aux_itoa(datash->counter);
    length = _strlen(datash->av[0]) + _strlen(ver_str);
    length += _strlen(datash->args[0]) + 24;
    error = malloc(sizeof(char) * (length + 1));

    if (error == 0)
    {
        free(error);
        free(ver_str);
        return (NULL);
    }

    char buffer[1024];
    int pos = 0;

    pos += _strcpy(buffer + pos, datash->av[0]);
    pos += _strcpy(buffer + pos, ": ");
    pos += _strcpy(buffer + pos, ver_str);
    pos += _strcpy(buffer + pos, ": ");
    pos += _strcpy(buffer + pos, datash->args[0]);
    pos += _strcpy(buffer + pos, ": Permission denied\n");

    pos += _strcpy(buffer + pos, "\0");
    write(STDOUT_FILENO, buffer, _strlen(buffer));
    free(ver_str);

    return (error);
}

