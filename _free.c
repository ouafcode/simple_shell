#include "main.h"
/**
 * ts_free - to free all allocation in memory
 * @pars: to parse array
 * @pth: point to path
 * @line: input line
 * @pth_full: point to full path
 * @flag: to mark if full path is in malloc
 *
 * Return: return nothing (void)
 */
void ts_free(char **pars, char *pth, char *line, char *pth_full, int flag)
{
	free(pth);
	free(pars);
	free(line);
	if (flag == 1)
		free(pth_full);
}
/**
 * arr_free - to free array
 * @arr: input array
 * @size: length of pointer
 *
 * Return: nothing(void)
 */
void arr_free(char **arr, unsigned int size)
{
	unsigned int i;

	i = 0;

	while (i < size)
	{
		free(arr[i]);
		i++;
	}

	free(arr);
}

