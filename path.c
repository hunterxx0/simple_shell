#include "header.h"

/**
 * path - find the path of a command
 *
 * @commands : command.
 * @env : enviremment.
 * @tmp : current path.
 * Return: path.
 */

void path(char **commands, char **env, char *tmp)
{
	int i = 0, word = 0, j = 0, l = 0;
	char *buffer = NULL, **paths = NULL, **p = NULL;
	struct stat st;

	tmp[0] = '\0';
	while (env[i])
	{
		if (env[i][0] == 'P' && env[i][1] == 'A')
		{
			buffer = env[i];
			break;
		}
		i++;
	}
	for (i = 0; i < 6; buffer++, i++)
		;
	word = words(buffer, ':');
	paths = split(buffer, ':', word), i = 0;
	while (paths[i])
	{
		word = words(paths[i], '/');
		p = split(paths[i], '/', word);
		for (j = 0; p[j]; j++)
		{
			_strcpy(tmp, "/");
			for (l = 0; l <= j; l++)
				_strcat(tmp, p[l]), _strcat(tmp, "/");

			_strcat(tmp, commands[0]);
			if (stat(tmp, &st) == 0)
			{
				free_mat(paths), free_mat(p);
				return;
			}
		} free_mat(p), i++;
	}
	if (paths[i] == NULL)
		tmp[0] = '\0';
	free_mat(paths);
}


/**
 * find_home_path - find the path of a command
 *
 * @env : enviremment.
 * Return:void.
 */

char *find_home_path(char **env)
{
	int i = 0;
	char *buffer = NULL, tmp[200], *p = NULL;

	tmp[0] = '\0';
	while (env[i])
	{
		if (env[i][0] == 'H' && env[i][1] == 'O' && env[i][4] == '=')
		{
			buffer = env[i];
			break;
		}
		i++;
	}

	for (i = 0; i < 5; buffer++, i++)
		;

	_strcpy(tmp, buffer);
	_strcat(tmp, "/");
	_strcat(tmp, ".simple_shell_history");
	p = _strdup(tmp);

	return (p);
}
