#include "main.h"
/**
 * main - main funct
 *
 * Return: 0 in sucess
 */
int main(void)
{
	char *get_line, *pth, *pth_full, **parse;
	int flag, sts_built, child_sts;
	struct stat buffer;

	while (TRUE)
	{
		prmpt(STDIN_FILENO, buffer);
		get_line = my_getline(stdin);
		if (my_strcmp(get_line, "\n", 1) == 0)
		{
			free(get_line);
			continue;
		}
		parse = token_funct(get_line);
		if (parse[0] == NULL)
			continue;
		sts_built = _exec(parse);
		if (sts_built == 0 || sts_built == -1)
		{
			free(parse);
			free(get_line);
		}
		if (sts_built == 0)
			continue;
		if (sts_built == -1)
			_exit(EXIT_SUCCESS);
		flag = 0;
		pth = get_env("PATH");
		pth_full = pth_src(parse[0], pth_full, pth);
		if (pth_full == NULL)
			pth_full = parse[0];
		else
			flag = 1;
		child_sts = prc_child(pth_full, parse);
		if (child_sts == -1)
			err(2);
		ts_free(parse, pth, get_line, pth_full, flag);
	}
	return (0);
}
