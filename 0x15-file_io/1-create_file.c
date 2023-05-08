#include "main.h"

/**
 * _strlen - returns the length of a string.
 * @s: the string to measure.
 * Return: the length of s.
 */

size_t _strlen(char *s)
{
	size_t len = 0;

	while (*s++)
		len++;

	return (len);
}

/**
 * create_file - creates a file.
 * @filename: the name of the file.
 * @text_content: a NULL terminated string to write to the file.
 * Return: 1 on success, -1 on failure.
 */

int create_file(const char *filename, char *text_content)
{
	int fd;
	ssize_t nbytes;

	if (filename == NULL)
		return (-1);

	fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0600);

	if (fd == -1)
		return (-1);

	if (text_content == NULL)
		return (1);

	nbytes = write(fd, text_content, _strlen(text_content));

	if (nbytes == -1)
		return (-1);

	close(fd);
	return (1);
}
