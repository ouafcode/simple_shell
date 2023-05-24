#include "main.h"
/**
 * pth_src - to search cmd in path
 * @cmd: input command
 * @pth_full: path of command
 * @pth: path of var
 *
 * Return: return pointer to path
 */
char *pth_src(char *cmd, char *pth_full, char *pth)
{
	unsigned int cmd_len;
	unsigned int pth_len;
       	unsigned int orig_len;
	char *pth_cpy;
        char *token;

	cmd_len = my_strlen(cmd);
	/*to have the length of original path*/
	orig_len = my_strlen(pth);

	pth_cpy = malloc(sizeof(char) * orig_len + 1);

	if (pth_cpy == NULL)
	{
		err(3);
		return (NULL);
	}

	my_strcpy(pth_cpy, pth);

	token = strtok(pth_cpy, ":");

	if (token == NULL)
		token = strtok(NULL, ":");

	while (token != NULL)
	{
		pth_len = my_strlen(token);
		pth_full = malloc(sizeof(char) * (pth_len + cmd_len) + 2);
		if (pth_full == NULL)
		{
			err(3);
			return (NULL);
		}

		my_strcpy(pth_full, token);

		pth_full[pth_len] = '/';

		my_strcpy(pth_full + pth_len + 1, cmd);

		pth_full[pth_len + cmd_len + 1] = '\0';

		if (access(pth_full, X_OK) != 0)
		{
			free(pth_full);
			pth_full = NULL;
			token = strtok(NULL, ":");
		}

		else
			break;
	}

	free(pth_cpy);

	return (pth_full);
}
