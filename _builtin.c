#include "main.h"
/**
* my_exit - to exit from shell
*
* Return: Nothing(void)
*/

	int my_exit(void)
	{
		return (-1);
	}

/**
*_env - to print envr
*
* Return: Nothing (void)
**/

int _env(void)
{
		unsigned int i;

		i = 0;

		while (environ[i] != NULL)
		{
			/*to get the environ*/
			write(STDOUT_FILENO, environ[i], my_strlen(environ[i]));
			write(STDOUT_FILENO, "\n", 1);
			i++;
		}

		return (0);
	}
