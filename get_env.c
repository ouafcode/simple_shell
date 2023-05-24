#include "main.h"
/**
 * get_env - funct for getting env variable
 * @name_pth: name path of env
 *
 * Return: return pointer or null
 */
char *get_env(const char *name_pth)
{
	char **env_cpy;
	char *var, *name, *pth;
	int comp;/*to compare*/
	unsigned int len_pth, env_len, len, i;

	env_len = 0;
	while (environ[env_len] != NULL)
		env_len++;

	env_cpy = NULL;
	env_cpy = envr_cpy(env_cpy, env_len);
	len = my_strlen((char *)name_pth);
	i = 0;
	while (env_cpy[i] != NULL)
	{
		var = env_cpy[i];
		comp = my_strncmp((char *)name_pth, var, len);
		if (comp == 1)
		{
			name = strtok(var, "=");
			name = strtok(NULL, "\n ");
			if (*name == '\0')
			{
				err(4);
				exit(EXIT_FAILURE);
			}
			len_pth = my_strlen(name);
			pth = malloc(sizeof(char) * len_pth + 1);
			if (pth == NULL)
			{
				err(3);
				return (NULL);
			}
			pth = my_strcpy(pth, name);
			arr_free(env_cpy, env_len);
			return (pth);
		} i++;
	}
	return (NULL);
}
/**
 * envr_cpy - to copy env variable
 * @env_cpy: point to env
 * @env_len: length of env
 *
 * Return: return double pointer
 */
char **envr_cpy(char **env_cpy, unsigned int env_len)
{
	char *var;
	unsigned int len_var;
	unsigned int i;

	env_cpy = malloc(sizeof(char **) * (env_len));
	if (env_cpy == NULL)
	{
		err(3);
		return (NULL);
	}

	i = 0;
	while (i < env_len)
	{
		var = environ[i];
		len_var = my_strlen(var);

		env_cpy[i] = malloc(sizeof(char) * len_var + 1);

		if (env_cpy[i] == NULL)
		{
			err(3);
			return (NULL);
		}
		my_strcpy(env_cpy[i], environ[i]);
		i++;
	}

	return (env_cpy);
}
