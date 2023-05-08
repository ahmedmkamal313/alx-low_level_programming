#include "main.h"

/**
 * allocate_buffer - Allocates 1024 bytes for a buffer.
 * @filename: The name of the file buffer is storing chars for.
 *
 * Return: A pointer to the newly-allocated buffer.
 */
char *allocate_buffer(char *filename)
{
	char *buf;

	buf = malloc(sizeof(char) * 1024);

	if (buf == NULL)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't write to %s\n", filename);
		exit(99);
	}

	return (buf);
}

/**
 * close_fd - Closes file descriptors.
 * @fd: The file descriptor to be closed.
 */
void close_fd(int fd)
{
	int status;

	status = close(fd);

	if (status == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(100);
	}
}
/**
 * main - copies the content of a file to another file.
 * @argc: the number of arguments.
 * @argv: the array of arguments
 * Return: 0 on success, an exit code on failure.
 */

int main(int argc, char *argv[])
{
	int src_fd, dest_fd, read_bytes, write_bytes;
	char *buf;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	buf = allocate_buffer(argv[2]);
	src_fd = open(argv[1], O_RDONLY);
	read_bytes = read(src_fd, buf, 1024);
	dest_fd = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
	do {
		if (src_fd == -1 || read_bytes == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't read from file %s\n", argv[1]);
			free(buf);
			exit(98);
		}

		write_bytes = write(dest_fd, buf, read_bytes);
		if (dest_fd == -1 || write_bytes == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't write to %s\n", argv[2]);
			free(buf);
			exit(99);
		}

		read_bytes = read(src_fd, buf, 1024);
		dest_fd = open(argv[2], O_WRONLY | O_APPEND);
	} while (read_bytes > 0);

	free(buf);
	close_fd(src_fd);
	close_fd(dest_fd);

	return (0);
}
