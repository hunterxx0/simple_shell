#include "header.h"

/**
 * history - create a list that contain the command history.
 * @buffer : list of commands.
 * @head : first element of the list.
 * Return: integer.
 */

int history(char *buffer, his **head)
{

	his *tmp = NULL;
	his *p = *head;
	int i = 0, test = 0;
	char *str = NULL;

	for (i = 0; buffer[i]; i++)
		if (buffer[i] != ' ' && buffer[i] != '\n')
		{
			test = 1;
			break;
		}

	if (buffer[0] != '\n' && test == 1)
	{
		str = strip(buffer);
		if (!str)
			str = _strdup(buffer);

		tmp = malloc(sizeof(his));
		if (!tmp)
			return (test);

		tmp->cmd = str;
		tmp->next = NULL;

		if (*head == NULL)
			*head = tmp;

		else
		{
			while (p->next)
				p = p->next;

			p->next = tmp;
		}
	}
	return (test);
}


/**
 * _print_history - print the command history.
 * @head : first node.
 * @env : list of the envirement variables.
 * Return: void.
 */

void _print_history(his **head, char **env)
{
	int line = 0, nb_line = 0;
	char *tmp = NULL;

	tmp = find_home_path(env);
	nb_line = lines(tmp);

	line = list_length(head);

	if (nb_line == 0 && line >= 4096)
		print_list(head, line, nb_line);

	if (line < 4096)
	{
		print_file(tmp, line, nb_line);
		print_list(head, line, nb_line);
	}
	free(tmp);
}

/**
 * print_list - print a list.
 * @head : first node.
 * @line : number of element of the list.
 * @nb_line : number of lines in the history file.
 * Return: void.
 */

void print_list(his **head, int line, int nb_line)
{
	his *tmp = *head;
	int x = 0;

	x = line - 4096;
	if (x > 0)
		nb_line = 0;


	for (; x > 0; x--)
		tmp = tmp->next;

	for (; tmp; nb_line++)
	{
		print_number(nb_line % 4096);
		_print(" ");
		_print(tmp->cmd);
		tmp = tmp->next;
	}
}


/**
 * print_file - print a file.
 * @t : file path.
 * @lines : number of element of the list.
 * @nb_line : number of lines in the history file.
 * Return: void.
 */

void print_file(char *t, int lines, int nb_line)
{
	char tmp[1024];
	int i = 0, x = 0, j = 0, c = 0, fd = 0, loop = 0;

	x = 4096 - lines;
	if (nb_line > x)
		loop = x;
	fd = open(t, O_RDONLY);
	if (fd == -1)
		return;

	do {
		c = read(fd, tmp, 1024);

		if (nb_line > x)
			for (i = 0; i < c && j < nb_line - x; i++)
				if (tmp[i] == '\n')
					j++;

		if (i == 1024 && (j == nb_line - x || j == 0))
			i = 0;

		for (; i < c; i++, loop++)
		{
			print_number(loop % 4096);
			_putchar(' ');
			for (; tmp[i] != '\n' && i < c; i++)
				_putchar(tmp[i]);

			if (tmp[i] == '\n')
				_putchar(tmp[i]);
		}
	} while (c == 1024);
	close(fd);
}


/**
 * write_his - write in the history file.
 * @head : first node.
 * @env : list of the envirement variables.
 * Return: void.
 */

void write_his(his **head, char **env)
{
	his *l = *head;
	int fd = 0;
	char *tmp = NULL;

	if (!head && !env)
		return;
	tmp = find_home_path(env);

	fd = open(tmp, O_WRONLY | O_APPEND | O_CREAT, 0644);
	if (fd == -1)
	{
		free_list(head);
		return;
	}

	while (l)
	{
		write(fd, l->cmd, _strlen(l->cmd));
		l = l->next;
	}

	close(fd);
	free(tmp);
	free_list(head);
}
