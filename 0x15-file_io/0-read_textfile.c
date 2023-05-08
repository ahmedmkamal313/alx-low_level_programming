#include "main.h"

/**
 * read_textfile - read a text file and prints it to the POSIX
 * standard output.
 * @filename: the name of the file to read.
 * @letters: the number of the letters to read and print.
 * Return: the actual number of letter read and printed,
 * or 0 if and error occurs.
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
	FILE *fp;
	char *buffer;
	ssize_t nbytes;

	if (filename == NULL)
		return (0);

	fp = fopen(filename, "r");

	if (fp == NULL)
		return (0);

	buffer = malloc(sizeof(char) * letters);

	if (buffer == NULL)
		return (0);
	nbytes = fread(buffer, sizeof(char), letters, fp);

	if (nbytes == 0)
		return (0);
	fclose(fp);

	nbytes = fwrite(buffer, sizeof(char), nbytes, stdout);

	if(nbytes == 0)
		return (0);

	free(buffer);

	return(nbytes);
}
