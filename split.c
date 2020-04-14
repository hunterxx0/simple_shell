#include "header.h"

/**
 * allocation - allocate a space memory for a pointer.
 * @p : pointer to ponter of string.
 * @i : current row of "p".
 * @width : width of the current row.
 * Return: void.
 */

int allocation(char **p, int i, int width)
{
	p[i] = malloc(sizeof(char) * (width + 1));
	if (p[i] == NULL)
	{
		for (i -= 1; i >= 0; i--)
			free(p[i]);
		free(p);
		return (1);
	}
	return (0);
}


/**
 * **split - function that splits a string into words.
 * @str : string.
 * @del : delimiter.
 * @heigth : number of words.
 * Return: pointer.
 */

char **split(char *str, char del, int heigth)
{
	int i, j = 0, k = 0, l, width;
	char **p = NULL;

	if (str == NULL || *str == '\0')
		return (NULL);

	p = malloc(sizeof(char *) * (heigth + 1));
	if (p == NULL)
		return (NULL);

	for (i = 0; i < heigth; i++)
	{

		while (str[j] == del && str[j] != '\0')
			j++;

		width = 0;
		k = j;

		while (str[k] != del && str[k] != '\0')
		{
			width++;
			k++;
		}

		if (allocation(p, i, width) == 1)
			return (NULL);

		for (l = 0; l < width; l++, j++)
			p[i][l] = str[j];
		p[i][l] = '\0';

	}
	p[i] = NULL;
	return (p);
}
