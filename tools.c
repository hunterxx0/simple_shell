#include "header.h"

/**
 * test_built_in - free a multidimensional array.
 *
 * @buffer : input line.
 * @env : envirement.
 * @head : first node.
 * Return: Number.
 */

int test_built_in(char *buffer, char **env, his **head)
{
	int test = 0;
	char *tmp = NULL;

	tmp = strip_built_in(buffer);

	if (tmp)
	{
		if (_strcmp("exit", tmp) == 0)
			test = 1;

		if (_strcmp("history", tmp) == 0)
		{
			_print_history(head, env);
			test = 2;
		}
	}
	if (tmp)
		free(tmp);
	return (test);
}


/**
* words - return the number of words in a string.
*
* @c : string of words.
* @x : delimiter between the words.
*
* Return: Integer.
*/

int words(char *c, char x)
{
	int w = 0, i = 0;

	while (c[i] != '\0')
	{
		if (c[i] != x)
		{
			if (c[i] == '#' && c[i])
			{
				c[i] = '\0';
				break;
			}
			w++;
			while (c[i] != x && c[i] != '\0')
				i++;
		}
		else
			i++;
	}
	return (w);
}


/**
 * strip - remove spaces at the begining and the end of a string.
 * @str : string.
 * Return: void.
 */

char *strip(char *str)
{
	int i = 0, st = 0, j = 0;
	char *start = NULL, *p = NULL;

	for (; str[i] && str[i] == ' '; i++)
		;

	if (str[i])
	{
		st = i;
		start = &str[i];

		for (; str[i]; i++)
			;

		for (i -= 2 ; str[i] == ' '; i--)
			;

		p = malloc(i - st + 3);
		if (!p)
			return (NULL);

		for (j = 0; j < i - st + 1; j++)
			p[j] = start[j];

		p[j] = '\n';
		p[j + 1] = '\0';
	}

	return (p);
}


/**
 * strip_built_in - remove spaces at the begining and the end of a string.
 * @str : string.
 * Return: void.
 */

char *strip_built_in(char *str)
{
	int i = 0, st = 0, j = 0;
	char *start = NULL, *p = NULL;

	for (; str[i] && str[i] == ' '; i++)
		;

	if (str[i])
	{
		st = i;
		start = &str[i];

		for (; str[i]; i++)
			;

		for (i-- ; str[i] == ' '; i--)
			;

		p = malloc(i - st + 2);
		if (!p)
			return (NULL);

		for (j = 0; j < i - st + 1; j++)
			p[j] = start[j];

		p[j] = '\0';
	}

	return (p);
}


/**
 * print_env - print envirement.
 *
 * @env : envirement.
 * Return: void.
 */

void print_env(char **env)
{
	int i = 0;

	for (i = 0; env[i]; i++)
	{
		_print(env[i]);
		_print("\n");
	}
	exit(0);

}
