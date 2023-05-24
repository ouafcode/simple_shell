#include "main.h"
/**
 * token_funct - to parse string
 * @string: input str
 *
 * Return: return pointer to arr
 */
char **token_funct(char *string)
{
	char **parse;
	char *parse_new;
	unsigned int i;

	parse = malloc(sizeof(char) * BUFF);
	if (parse == NULL)
	{
		err(3);
		exit(EXIT_FAILURE);
	}

	parse_new = strtok(string, "\n\t\r ");

	i = 0;
	while (parse_new != NULL)
	{
		parse[i] = parse_new;
		parse_new = strtok(NULL, "\n\t\r ");
		i++;
	}

	parse[i] = NULL;

	return (parse);
}
