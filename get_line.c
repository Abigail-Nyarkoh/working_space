#include "main.h"

/**
 * prepare_line - Prepares the line variable for get_line.
 *
 * @lineptr: Buffer that stores the input string.
 * @buffer: String that is assigned to line.
 * @line_size: Size of line.
 * @buffer_size: Size of buffer.
 */
void prepare_line(char **lineptr, size_t *line_size, char *buffer, size_t buffer_size)
{
    if (*lineptr == NULL)
    {
        if (buffer_size > BUFSIZE)
            *line_size = buffer_size;
        else
            *line_size = BUFSIZE;
        *lineptr = buffer;
    }
    else if (*line_size < buffer_size)
    {
        if (buffer_size > BUFSIZE)
            *line_size = buffer_size;
        else
            *line_size = BUFSIZE;
        *lineptr = buffer;
    }
    else
    {
        _strcpy(*lineptr, buffer);
        free(buffer);
    }
}

/**
 * custom_get_line - Reads input from a stream.
 *
 * @lineptr: Buffer that stores the input.
 * @line_size: Size of lineptr.
 * @stream: Stream to read from.
 *
 * Return: The number of bytes read.
 */
ssize_t custom_get_line(char **lineptr, size_t *line_size, FILE *stream)
{
    int read_result;
    static ssize_t input_size;
    ssize_t retval;
    char *buffer;
    char character = 'z';

    if (input_size == 0)
        fflush(stream);
    else
        return (-1);

    input_size = 0;

    buffer = malloc(sizeof(char) * BUFSIZE);
    if (buffer == 0)
        return (-1);

    while (character != '\n')
    {
        read_result = read(STDIN_FILENO, &character, 1);

        if (read_result == -1 || (read_result == 0 && input_size == 0))
        {
            free(buffer);
            return (-1);
        }

        if (read_result == 0 && input_size != 0)
        {
            input_size++;
            break;
        }

        if (input_size >= BUFSIZE)
            buffer = _realloc(buffer, input_size, input_size + 1);

        buffer[input_size] = character;
        input_size++;
    }

    buffer[input_size] = '\0';
    prepare_line(lineptr, line_size, buffer, input_size);
    retval = input_size;

    if (read_result != 0)
        input_size = 0;

    return (retval);
}

