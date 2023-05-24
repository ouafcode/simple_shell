#include "main.h"
/**
 * my_strcmp - to compare two str
 * @vn: input name by user
 * @var: input variable to compare with it
 * @size: length of input name by user
 *
 * Return: return 1 if success , or -1 if failed
 */
int my_strcmp(char *vn, char *var, unsigned int size)
{
	unsigned int var_size;
	unsigned int i;

	var_size = my_strlen(var);
	if (var_size != size)
		return (-1);

	i = 0;

	while (vn[i] != '\0' && var[i] != '\0')
	{
		if (vn[i] != var[i])
			return (1);
		i++;
	}

	return (0);
}
/**
 * my_strncmp - to compare two string
 * @vn: input name by user
 * @var: input variable to compare with it
 * @size: length of input name by user
 *
 * Return: 1 if success or -1 if failed
 */
int my_strncmp(char *vn, char *var, unsigned int size)
{
	unsigned int i;

	i = 0;

	while (i < size)
	{
		if (vn[i] != var[i])
			return (-1);
		i++;
	}

	return (1);
}
/**
 * my_strcpy - to copy string
 * @to: str to copy to
 * @from: str to copy from
 *
 * Return: str copied
 */
char *my_strcpy(char *to, char *from)
{
	int i;
	int j = my_strlen(from);

	for (i = 0; i <= j; i++)
		to[i] = from[i];

	return (to);
}
/**
 * my_strlen - to calculate the length of string
 * @str: input string
 *
 * Return: the length
 */
int my_strlen(char *str)
{
	int i = 0;

	while (str[i] != '\0')
		i++;

	return (i);
}
