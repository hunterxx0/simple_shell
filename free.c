#include "header.h"

/**
 * free_mat - free a multidimensional array.
 *
 * @commands : array of commands.
 *
 * Return: Void.
 */

void free_mat(char **commands)
{
	int i = 0;

	if (commands)
	{
	while (commands[i])
		free(commands[i++]);
	free(commands);
	}
}


/**
 * free_list - Free a list.
 * @head : first element of the list.
 * Return : Void.
 */

void free_list(his **head)
{
	his *l = NULL;

	if (*head)
	{
		l = *head;
		while (l)
		{
			*head = l->next;
			free(l->cmd);
			free(l);
			l = *head;
		}
	}
}


/**
 * free_all - free evry malloc.
 * @buffer : input line.
 * @head : first element of the list.
 * @env : lists of the envirement variables.
 * Return: Void.
 */

void free_all(char *buffer, his **head, char **env)
{
	if (buffer)
		free(buffer);
	write_his(head, env);
}
