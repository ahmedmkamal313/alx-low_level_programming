#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * keygen5 - generates a valid key for crackme5
 * @username: the username to generate a key for
 * Return: the key as a string
 */
char *keygen5(char *username)
{
	int len = strlen(username); /* get the length of the username */
	int sum = 0;
	int i; /* declare a loop variable */
	char *key = malloc(len + 1); /* allocate memory for the key */

	if (key == NULL) /* check if memory allocation failed */
		return (NULL); /* return NULL */

	for (i = 0; i < len; i++) /* loop through the username */
	{
		sum += username[i]; /* add the ASCII value of each character to the sum */
		key[i] = username[i] ^ 0x4f;
	}
	key[i] = sum & 0x3f;
	key[i] += 'A'; /* add 'A' to convert it to an uppercase letter */
	key[len] = '\0'; /* add a null terminator to the key */

	return (key); /* return the key */
}

/**
 * main - entry point for the keygen program
 * @argc: number of arguments
 * @argv: array of arguments
 * Return: 0 on success, 1 on error
 */
int main(int argc, char **argv)
{
	char *key; /* declare a pointer to store the key */

	if (argc != 2) /* check if the number of arguments is not 2 */
	{
		printf("Usage: %s username\n", argv[0]); /* print usage message */
		return (1); /* exit with status 1 */
	}

	key = keygen5(argv[1]); /* generate a key for the given username */

	if (key == NULL) /* check if key generation failed */
	{
		printf("Error: memory allocation failed\n"); /* print error message */
		return (1); /* exit with status 1 */
	}

	printf("%s\n", key); /* print the key */

	free(key); /* free the memory allocated for the key */

	return (0); /* exit with status 0 */
}
