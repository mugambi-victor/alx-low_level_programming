#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * read_textfile - Read and print a text file to the POSIX standard output.
 *
 * @filename: The name of the file to read.
 * @letters: The number of letters to read and print.
 *
 * Return: The actual number of letters read and printed.
 *         0 on error, including if the file cannot be opened, read fails,
 *         memory allocation fails, or write fails.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	FILE *file;
	char *buffer;
	ssize_t bytes_read;

	if (filename == NULL)
		return (0); /* If filename is NULL, return 0 as specified. */
	file = fopen(filename, "r");
	if (file == NULL)
		return (0); /* If the file cannot be opened, return 0. */
	buffer = malloc(letters + 1); /* Allocate memory for the buffer. */
	if (buffer == NULL)
	{
		fclose(file);
		return (0); /* Memory allocation failed, return 0. */
	}
	bytes_read = fread(buffer, 1, letters, file); /* Read from the file. */
	if (bytes_read < 0 || write(STDOUT_FILENO, buffer, bytes_read) != bytes_read)
	{
		/* If read or write fails, return 0. */
		free(buffer);
		fclose(file);
		return (0);
	}
	free(buffer);
	fclose(file);

	/* Return the actual number of letters read and printed. */
	return (bytes_read);
}
