#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

/**
 * append_text_to_file - Append text at the end of a file.
 *
 * @filename: The name of the file.
 * @text_content: The text content to append to the file.
 *
 * Return: 1 on success and -1 on failure.
 */
int append_text_to_file(const char *filename, char *text_content)
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

    /* Open the file for writing, appending to it if it exists,
       or creating it if it doesn't exist. */
    fd = open(filename, O_WRONLY | O_APPEND | O_CREAT, 0600);
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
