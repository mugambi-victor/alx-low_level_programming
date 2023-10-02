#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define BUF_SIZE 1024

/**
 * copy_file - Copies the content of one file to another.
 * @from_filename: The name of the source file.
 * @to_filename: The name of the destination file.
 *
 * Return: 0 on success, or an exit code on failure.
 */
int copy_file(const char *from_filename, const char *to_filename)
{
	int fd_from, fd_to;
	ssize_t read_bytes, write_bytes;
	char buffer[BUF_SIZE];

	fd_from = open(from_filename, O_RDONLY);
	if (fd_from == -1)
	{
		dprintf(2, "Error: Can't read from file %s\n", from_filename);
		return (98);
	}
	fd_to = open(to_filename, O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (fd_to == -1)
	{
		dprintf(2, "Error: Can't write to %s\n", to_filename);
		close(fd_from);
		return (99);
	}
	while ((read_bytes = read(fd_from, buffer, BUF_SIZE)) > 0)
	{
		write_bytes = write(fd_to, buffer, read_bytes);
		if (write_bytes == -1)
		{
			dprintf(2, "Error: Can't write to %s\n", to_filename);
			close(fd_from);
			close(fd_to);
			return (99);
		}
	}
	if (read_bytes == -1)
	{
		dprintf(2, "Error: Can't read from file %s\n", from_filename);
		close(fd_from);
		close(fd_to);
		return (98);
	}
	if (close(fd_from) == -1 || close(fd_to) == -1)
	{
		dprintf(2, "Error: Can't close fd %d\n",
(close(fd_from) == -1) ? fd_from : fd_to);
		return (100);
	}
	return (0);
}

/**
 * main - Main function.
 * @argc: The number of arguments.
 * @argv: The array of arguments.
 *
 * Return: 0 on success, or an exit code on failure.
 */
int main(int argc, char **argv)
{
	if (argc != 3)
	{
		dprintf(2, "Usage: %s file_from file_to\n", argv[0]);
		return (97);
	}
	return (copy_file(argv[1], argv[2]));
}
