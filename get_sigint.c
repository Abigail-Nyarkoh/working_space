#include "main.h"

/**
 * handle_sigint - Handles the Ctrl+C signal in the prompt.
 *
 * @sig: Signal handler.
 */
void handle_sigint(int sig)
{
    (void)sig;
    write(STDOUT_FILENO, "\n^-^ ", 5);
}

