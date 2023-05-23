#include "main.h"
/**
 * my_getline - get line from user input
 * @input: user input
 *
 * Return: return buffer
 */
char *my_getline(FILE *input)
{
	char *input_line;
	ssize_t get;
	size_t length;

	input_line = NULL;
	length = 0;
	get = getline(&input_line, &length, input);
	if (get == -1)
	{
		free(input_line);
		exit(EXIT_SUCCESS);
	}

	return (input_line);
}
