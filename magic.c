#include "header.h"

/**
 * test_error - test the list of commands.
 * @b_arr : commands.
 * Return: integer.
 */

int test_error(char **b_arr)
{
	int i = 0, word = 0;

	for (i = 0; b_arr[i]; i++)
	{
		word = words(b_arr[i], ' ');
		if (word == 0 && b_arr[i + 1] != NULL)
			return (99);
	}

	return (0);
}


/**
 * magic(:)? (- Where the magic is done)?
 * @buffer : number of argement.
 * @word: list of argements.
 * @head: first node.
 * @env : lists of the envirement variables.
 * @av: av.
 * Return: int
 */

int magic(char *buffer, int word, his **head, char **env, char **av)
{
	char **b_arr = NULL, *tmp = NULL;
	int i = 0, test = 0;

	tmp = strip_built_in(buffer);
	b_arr = split(buffer, ';', word);
	free(tmp);
	if (test_error(b_arr) != 99)
	{
		for (i = 0; b_arr[i]; i++)
		{
			word = words(b_arr[i], ' ');
			if (word == 1)
			{
				test = test_built_in(b_arr[i], env, head);
				if (test == 1)
				{
					free_mat(b_arr);
					free_all(buffer, head, env);
					return (1);
				}
				if (test == 2)
				{
					free_mat(b_arr);
					return (2);
				}
			}
			if (word != 0)
				_exec(av, env, b_arr, word, i);
		}
	}
	else
		_exec(av, env, b_arr, word, -1);
	free_mat(b_arr);
	return (0);
}
