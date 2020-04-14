#include "header.h"

/**
 * print_error - print a text in the standar error.
 *
 * @s: input int
 * Return: Void.
 */

void print_error(char *s)
{
	int i = 0;

	for (i = 0; s[i]; i++)
		;
	write(STDERR_FILENO, s, i);
}


/**
 * _exec(:)? (- exuecuting commands)?
 *
 * @buffer: list of commands.
 * @av: list of argements.
 * @env : lists of the envirement variables.
 * @word: number of words in the input line.
 * @i : index.
 * Return:
 */
void _exec(char **av, char **env, char **buffer, int word, int i)
{
	pid_t pid = 0;
	int s = 0;
	char **commands, tmp[200];
	struct stat st;

	pid = fork();
	if (pid == 0)
	{
		if (i == -1)
		{
			print_error(av[0]);
			print_error(": syntax error near unexpected token `;'\n");
			exit(2);
		}

		commands = split(buffer[i], ' ', word);
		_strcpy(tmp, commands[0]);
		if (stat(commands[0], &st) != 0)
			path(commands, env, tmp);

		if (tmp[0] != '\0')
			execve(tmp, commands, env);
		else
		{
			if (!buffer[i + 1])
			{
				free_mat(buffer);
			}
			perror(av[0]);
			free_mat(commands);
			exit(127);
		}
	}
	else
		wait(&s);
}
