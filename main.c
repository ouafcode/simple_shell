#include "main.h"

/**
 * main - check the code
 * argc: nombre des argument d'entree
 * argv: tableau des chaines de caractere
 * Return: success = 0, fail = -1 .
 */

int main(int argc, char **argv)
{
	//partie de definition
	char *prompt = "$";
	char *input = NULL, *input_cp = NULL;
	size_t n = 0;
	ssize_t input_ver; //pour verifier input
	const char *delim = " \n";
	int nbr_parse = 0;
	char *parse;
	int i;
	
	/*declaring void variable*/
	(void)argc;
	
	if (isatty(STDIN_FILENO))
	{
	//when is running is interactive mode
	//display prompt and accept input from user
		while (1);
		{
			_putchar("$");
			input_ver = getline(&input, &n, stdin);
		
			/*allocae memory pour input copie*/
			input_cp = malloc(sizeof(char) * input_ver);
			if (input_cp == NULL){
				perror("tsh: memory allocation error");
				return (-1);
			}
		
			/*faire une copie de la commade entree*/
			strcpy(input_cp, input);
		
			/*verifier si getline atteint EOF ou CTRL+D*/
			if (input_ver == -1)
			{
				_putchar("\n");
				return (-1);
			}
			else{
				/*diviser la commande entree en string*/
				parse = strtok(input, delim);

				while (parse != NULL){
					nbr_parse++;
					parse = strtok(NULL, delim);
				}
				nbr_parse++;

				/*Allocat memory for string */
				argv = malloc(sizeof(char *) * nbr_parse);

				/*stocker chaque token dans argv array*/
				parse = strtok(input_cp, delim);

				for (i = 0; parse != NULL; i++)
				{
					argv[i] = malloc(sizeof(char) * strlen(parse));
					strcpy(argv[i], parse);
					parse = strtok(NULL, delim);
				}
				argv[i] = NULL;

				/*execute command*/
				exct(argv);
			}

			/*free allocat memory*/
			free(input_cp);
			free(input);
		}
	}
	//else{
	// if is running in non-interactive mode//
	// execute commands from script or batch file//
	return (0);
}
