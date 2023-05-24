#include "main.h"
/**
 * err - to print error
 * @nbr: number of error
 *
 * Return: return nothing (void)
 */
void err(int nbr)
{
	switch (nbr)
	{
		case 1:
		write(STDERR_FILENO, ERROR_FORK, my_strlen(ERROR_FORK));
		perror("Error");
		break;

	case 2:
		perror("Error");
		break;

	case 3:
		write(STDERR_FILENO, ERROR_MALOC, my_strlen(ERROR_MALOC));
		break;
	case 4:
		write(STDERR_FILENO, ERROR_PATH, my_strlen(ERROR_PATH));
		break;

	default:
		return;
	}
}
