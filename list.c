#include "header.h"

/**
 * lines - return the number of lines in a file.
 * @tmp : home path.
 * Return: file number.
 */

int lines(char *tmp)
{
	int fd = 0, c = 0, nb_line = 0, i = 0;
	char s[1024];

	fd = open(tmp, O_RDONLY);
	if (fd == -1)
		return (0);

	do {
		c = read(fd, s, 1024);
		if (c == -1)
			return (0);

		for (i = 0; i < c; i++)
		{
			if (s[i] == '\n')
				nb_line++;
		}
	} while (c == 1024);

	c = close(fd);
	if (c == -1)
		return (-1);

	return (nb_line);
}


/**
* list_length - return the length of a list.
* @head : first element.
* Return: list length
*/

int list_length(his **head)
{
	int len = 0;
	his *p = *head;

	while (p)
	{
		len++;
		p = p->next;
	}
	return (len);
}
