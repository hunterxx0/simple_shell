#include "header.h"

/**
 * file_exec - exec from file.
 * @av : file.
 * @lines : command list.
 * @env : env.
 * @word : number of words.
 * Return: void.
 */

void file_exec(char **av, char **lines, char **env, int word)
{
	int i = 0, test = 0;

	for (; lines[i]; i++)
	{
		word = words(lines[i], ' ');
		if (word == 1)
		{
			test = test_built_in(lines[i], env, NULL);
			if (test == 1)
				break;
			if (test == 2)
				if (!lines[i + 1])
					free_mat(lines);
		}
		if (word != 0)
			_exec(av, env, lines, word, i);
	}

}
/**
 * fileinput - exex a file.
 * @av : file.
 * @env : env.
 * Return: void.
 */

void fileinput(char **av, char **env)
{
	char **lines = NULL, cmd[4096] = "\0";
	int fd = 0, w = 0;
	ssize_t r = 0;

	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		perror(av[0]);
	r = read(fd, cmd, 4096);
	if (r == -1)
	perror(av[0]);
	w = words(cmd, '\n');
	lines = split(cmd, '\n', w);
	file_exec(av, lines, env, w);
	close(fd);
	free_mat(lines);
}
