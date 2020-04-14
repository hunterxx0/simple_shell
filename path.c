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
	int i = 0, word = 0;
	char *buffer = NULL, **paths = NULL;
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
	paths = split(buffer, ':', word);

	i = 0;
	while (paths[i])
	{
		_strcpy(tmp, paths[i]);
		_strcat(tmp, "/");
		_strcat(tmp, commands[0]);

		if (stat(tmp, &st) == 0)
			break;
		i++;
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
