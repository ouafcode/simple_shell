#include <stdio.h>
#include <stdlib.h>
#include "test.h"

/**
 * main - check the code
 *
 * Return: Always 0.
 */
int main()
{
	char *delim = "  ";
	char *text ="test0/test/ls -l ; check test";
	char **token=_strtok(text,delim);

	printf("%s",get_cmd(token[0]));
	
	return (0);
}
