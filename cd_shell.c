#include "main.h"

/**
 * change_directory - changes the current directory based on user input
 *
 * @datash: data relevant
 * @dir: directory to change to
 * Return: 1 on success, -1 on error
 */
int change_directory(data_shell *datash, const char *dir)
{
    char *home = _getenv("HOME", datash->_environ);

    if (dir == NULL || _strcmp("$HOME", dir) == 0 || _strcmp("~", dir) == 0)
    {
        if (home != NULL)
            dir = home;
        else
            return -1; // Handle error: Home directory not found
    }
    else if (_strcmp("-", dir) == 0)
    {
        cd_previous(datash);
        return 1;
    }
    else if (_strcmp(".", dir) == 0 || _strcmp("..", dir) == 0)
    {
        cd_dot(datash);
        return 1;
    }

    if (chdir(dir) == -1)
        return -1; // Handle error: Directory not found or permission denied

    char *new_pwd = getcwd(NULL, 0);
    set_env("OLDPWD", _getenv("PWD", datash->_environ), datash);
    set_env("PWD", new_pwd, datash);
    free(new_pwd);

    return 1; // Success
}

