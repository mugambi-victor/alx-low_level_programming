#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/stat.h>

#define BUFFER_SIZE 1024

int open_source_file(const char *filename);
int open_destination_file(const char *filename);
ssize_t read_and_write(int src_fd, int dest_fd);
/**
 * main - Entry point of the program.
 *
 * @argc: The number of command-line arguments.
 * @argv: An array of command-line arguments.
 *
 * Return: 0 on success, or an error code on failure.
 */
int main(int argc, char *argv[])
{
	int src_fd, dest_fd;
	ssize_t result;

	if (argc != 3)
	{
		dprintf(2, "Usage: %s file_from file_to\n", argv[0]);
		return (97);
	}
	src_fd = open_source_file(argv[1]);

	if (src_fd == -1)
		return (98);

	dest_fd = open_destination_file(argv[2]);

	if (dest_fd == -1)
	{
		close(src_fd);
		return (99);
	}

	result = read_and_write(src_fd, dest_fd);

	if (close(src_fd) == -1 || close(dest_fd) == -1)
	{
		dprintf(2, "Error: Can't close file descriptors\n");
		return (100);
	}

	return (result == -1 ? 98 : 0);
}
/**
 * open_source_file - Open the source file for reading.
 *
 * @filename: The path to the source file to be opened.
 *
 * Return: The file descriptor on success, or -1 on failure.
 *         If the file cannot be opened, an error message is printed.
 */
int open_source_file(const char *filename)
{
	int fd = open(filename, O_RDONLY);

	if (fd == -1)
		dprintf(2, "Error: Can't read from file %s\n", filename);
	return (fd);
}
/**
 * open_destination_file - Open the destination file for writing.
 *
 * @filename: The destination file path.
 *
 * Return: The file descriptor on success, or -1 on failure.
 */
int open_destination_file(const char *filename)
{
       	mode_t file_permissions = S_IRUSR | S_IWUSR | S_IRGRP;
	int fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, file_permissions);

	if (fd == -1)
	{
		dprintf(2, "Error: Can't write to %s\n", filename);
	}
	else
	{
		/**
		 * check if the file was just created
		 */

		if (errno == EEXIST)
		{
			/**
			 * If the file already existed, don't change its permissions
			 */
			file_permissions = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;
			chmod(filename, file_permissions);
		}
	}

	return (fd);
}
/**
 * read_and_write - Read from the source file descriptor and write to the
 *                  destination file descriptor.
 *
 * @src_fd: The source file descriptor.
 * @dest_fd: The destination file descriptor.
 *
 * Return: The total number of bytes written to the destination file descriptor
 *         on success, or -1 on failure.
 */
ssize_t read_and_write(int src_fd, int dest_fd)
{
	char buffer[BUFFER_SIZE];
	ssize_t bytes_read, bytes_written, total_bytes_written = 0;

	while ((bytes_read = read(src_fd, buffer, BUFFER_SIZE)) > 0)
	{
		bytes_written = write(dest_fd, buffer, bytes_read);
		if (bytes_written == -1)
		{
			dprintf(2, "Error: Can't write to destination file\n");
			return (-1);
		}
		total_bytes_written += bytes_written;
	}

	if (bytes_read == -1)
	{
		dprintf(2, "Error: Can't read from source file\n");
		return (-1);
	}

	return (total_bytes_written);
}
