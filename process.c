#include "main.h"
/**
 * prc_child - to process child
 * @pth_full: the full pth
 * @parse: user input to be parsed
 *
 * Return: 0 on success
 */
int prc_child(char *pth_full, char **parse)
{
	pid_t PID;
	int sts;
	int exev_sts;
	char **put_env = environ;

	PID = fork();
	if (PID == -1)
	{
		err(1);
		exit(EXIT_FAILURE);
	}
	if (PID == 0)
	{
		/*get status of execution funct*/
		exev_sts = execve(pth_full, parse, put_env);
		if (exev_sts == -1)
			return (-1);
	}

	else
		wait(&sts);

	return (0);

}
