#include "main.h"

void exct(char **argv)
{
	char *cmd = NULL;
	char *cmd_act = NULL; // command actuel

	if (argv){
	/*get the command*/
		cmd = argv[0];

	/*generer le path vers la commande avant executer*/
		cmd_act = get_path(cmd);
	
	/*execut la cmd actuel avec excve*/
		if (execve(cmd_act, argv, NULL) == -1)
		{
			perror("Error:");
		}
	}
}
