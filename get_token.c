#include "test.h"

/**
 *  **_strtok : devide a string in words
 *  @str: the input string
 *  @d : delimiter string
 *  Return : a pointer to an array of strings or NULL in failure
 */
char **_strtok(char *str, char *d)
{
	char **phrase = NULL;
	int i, j, k, debut_mot, long_mot, nbr_mot = 0;

	if (str == NULL || str[0] == 0)
		return (NULL);
	for (i = 0; str[i] != '\0'; i++)
		if (!dl_check(str[i], d) && (dl_check(str[i + 1], d) || str[i + 1] == '\0'))
			nbr_mot++;
	if (nbr_mot == 0)
		return (NULL);
	phrase = malloc((nbr_mot + 1) * sizeof(char *));
	if (!phrase)
		return (NULL);
	for (i = 0, j = 0; i < nbr_mot; i++)
	{
		while (dl_check(str[j], d))
			j++;
		debut_mot = j;
		while (!dl_check(str[j], d) && str[j])
			j++;
		long_mot = j - debut_mot;
		phrase[i] = malloc((long_mot + 1) * sizeof(char));
		if (!phrase[i])
		{
			while (!i)
				free(phrase[--i]);
			free(phrase);
			return (NULL);
		}
		for (k = 0 ; k < long_mot; k++)
			phrase[i][k] = str[debut_mot + k];
		phrase[i][k + 1] = 0;
	}
	phrase[i] = NULL;
	return (phrase);
}
/**
 * delim_check - checks if characteris a delimeter
 * @c: the caracter to check
 * @d: the delimeter string
 * return 1 if true ,0 if false
 */
int dl_check(char c, char *dl)
{
	while (*dl)
		if (*dl++ == c)
			return (1);
	return (0);
}
/**
 * get_cmd - to the cmd without path
 * @str: the string to check
 * return a string or NULL if failure
 */
char *get_cmd(char *str)
{
	char *s = NULL;
	int i, pos = -1, taille, sl = '/';

	for (i = 0; str[i] != '\0'; i++)
		if (str[i] == sl)
			pos = i + 1;
	if (pos == -1)
		return (str);
	taille = i - pos;
	s = malloc((taille) * sizeof(char));
	if (!s)
		return (NULL);
	for (i = 0; i < taille; i++)
		s[i] = str[pos + i];
	s[taille] = 0;
	return (s);
}
