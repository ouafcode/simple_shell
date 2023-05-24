#include "main.h"
/**
*_exec - to execute builtin function
*@parse: arg to tokenize
*
* Return: return parsed token
*/
int _exec(char **parse)
{
	int sts;
	unsigned int size, nbr;
	unsigned int i;

	link_blt built[] = {
		{"exit", my_exit},
		{"env", _env},
		{NULL, NULL}
	};

	if (parse[0] == NULL)
		return (1);

	size = my_strlen(parse[0]);

	nbr = nbr_built(built);
	for (i = 0; i < nbr; i++)
	{
		if (my_strcmp(parse[0], built[i].blt, size) == 0)
		{
			sts = (built[i].ptr)();
			return (sts);
		}
	}
	return (1);
}

/**
*nbr_built - to check builtin
*@built: input builtin to be calculated
*
* Return: nbr of builtin
*/

int nbr_built(link_blt built[])
{
	unsigned int i;

	i = 0;
	while (built[i].blt != NULL)
		i++;

	return (i);
}
