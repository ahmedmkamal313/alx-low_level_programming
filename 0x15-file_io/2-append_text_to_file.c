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
 * append_text_to_file - appends text at the end of a file.
 * @filename: the name of the file
 * @text_content: the NULL terminated string to add at the end
 * of the file
 * Return: 1 on success and -1 on failure
 */

int append_text_to_file(const char *filename, char *text_content)
{
	int fd;
	ssize_t nbytes;

	if (filename == NULL)
		return (-1);

	fd = open(filename, O_WRONLY | O_APPEND);

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
