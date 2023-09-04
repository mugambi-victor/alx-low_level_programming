#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

/**
 * create_file - Create a file and write text to it.
 *
 * @filename: The name of the file to create or truncate.
 * @text_content: The text content to write to the file.
 *
 * Return: 1 on success, -1 on failure.
 */
int create_file(const char *filename, char *text_content)
{
    int fd, write_result;
    ssize_t len = 0;

    if (filename == NULL)
        return (-1);

    if (text_content != NULL)
    {
        while (text_content[len])
            len++;
    }

    /* Open the file for writing, creating it if it doesn't exist,
       or truncating it if it does. */
    fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0600);
    if (fd == -1)
        return (-1);

    if (len > 0)
    {
        write_result = write(fd, text_content, len);
        if (write_result == -1)
        {
            close(fd);
            return (-1);
        }
    }

    close(fd);
    return (1);
}
