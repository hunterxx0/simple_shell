#include "header.h"

/**
 * main(:)? (- shell)?
 * @ac : number of argement.
 * @av: list of argements.
 * @env : lists of the envirement variables.
 * Return: 0
 */
int main(int ac, char **av, char **env)
{
	char *buffer = NULL, *tmp = NULL;
	size_t bufsize = 0;
	int word = 0, characters = 0, test = 0;
	his *head = NULL;

	if (ac == 2)
	{
		fileinput(av, env);
		return (0);
	}
	while (1)
	{
		signal(SIGINT, csignal);
		if (isatty(STDIN_FILENO))
			_print("#cisfun$ ");
		characters = getline(&buffer, &bufsize, stdin);
		if (characters == -1)
			break;
		if (history(buffer, &head) == 0)
			continue;
		buffer[characters - 1] = '\0';
		tmp = strip_built_in(buffer);
		if (_strcmp("env", tmp) == 0)
		{
			print_env(env);
			free(tmp);
			continue;
		}
		if (tmp)
			free(tmp);
		word = words(buffer, ';');
		if (word != 0)
		{
			test = magic(buffer, word, &head, env, av);
			if (test == 1)
			{
				return (0);
			}
			if (test == 2)
				continue;
		}

	}
	free_all(buffer, &head, env);
	return (0);
}
