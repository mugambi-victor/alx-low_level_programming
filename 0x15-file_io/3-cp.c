#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <sys/stat.h>

#define BUFFER_SIZE 1024

void close_file(int fd);
void handle_error(const char *message, const char *file, int exit_code);

/**
 * main - Copies the contents of a file to another file.
 * @argc: The number of arguments supplied to the program.
 * @argv: An array of pointers to the arguments.
 *
 * Return: 0 on success.
 *
 * Description: If the argument count is incorrect - exit code 97.
 *              If file_from does not exist or cannot be read - exit code 98.
 *              If file_to cannot be created or written to - exit code 99.
 *              If file_to or file_from cannot be closed - exit code 100.
 */
int main(int argc, char *argv[])
{
	int from, to, r, w;
	char buffer[BUFFER_SIZE];

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		return (97); /* Exit with code 97 for incorrect argument count. */
	}

	from = open(argv[1], O_RDONLY);
	if (from == -1)
	{
		handle_error("Can't open source file", argv[1], 98);
	}

	to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
	if (to == -1)
	{
		handle_error("Can't open destination file", argv[2], 99);
	}

	do {
		r = read(from, buffer, BUFFER_SIZE);
		if (r == -1)
		{
			handle_error("Can't read from file", argv[1], 98);
		}

		w = write(to, buffer, r);
		if (w == -1)
		{
			handle_error("Can't write to file", argv[2], 99);
		}

	} while (r > 0);

	close_file(from);
	close_file(to);

	return (0);
}

/**
 * close_file - Closes a file descriptor.
 * @fd: The file descriptor to be closed.
 */
void close_file(int fd)
{
	if (close(fd) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(100); /* Exit with code 100 if closing the file descriptor fails. */
	}
}

/**
 * handle_error - Handles and reports an error.
 * @message: The error message to be displayed.
 * @file: The name of the file associated with the error.
 * @exit_code: The exit code to use when terminating the program.
 */
void handle_error(const char *message, const char *file, int exit_code)
{
	dprintf(STDERR_FILENO, "Error: %s %s\n", message, file);
	exit(exit_code);
}
