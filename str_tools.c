#include "header.h"


/**
 * _strcpy - copies the string.
 * @dest : string.
 * @src : string.
 * Return: char.
 */

void _strcpy(char *dest, char *src)
{
	int i = 0, j;

	while (src[i] != '\0')
		i++;

	for (j = 0 ; j <= i ; j++)
		dest[j] = src[j];
}


/**
 * *_strcat - concatenates two strings.
 * @dest : first string.
 * @src : second string.
 * Return: Always 0.
 */

void _strcat(char *dest, char *src)
{
	int i = 0, j = 0;

	while (dest[i] != '\0')
	{
		i++;
	}
	while (src[j] != '\0')
	{
		dest[i] = src[j];
		j++;
		i++;
	}
	dest[i] = '\0';
}


/**
 * _strcmp - compares two strings.
 * @s1 : first string.
 * @s2 : second string.
 * Return: Always 0.
 */

int _strcmp(char *s1, char *s2)
{
	int i = 0, x = 0;

	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
	{
		i++;
	}
	x = s1[i] - s2[i];
	return (x);
}


/**
 * _strlen - returns the length of a string.
 * @s : string.
 * Return: void.
 */

int _strlen(char *s)
{
	int i = 0;

	while (s[i] != '\0')
		i++;
	return (i);
}


/**
 * *_strdup - returns a pointer to a newly allocated space in memory,
 * which contains a copy of the string given as a parameter.
 * @str : pointer to a string.
 * Return: poiter to a new string.
 */

char *_strdup(char *str)
{
	int size = 0, i;
	char *p, *str1;

	str1 = str;
	if (str == NULL)
		return (NULL);
	size = _strlen(str1);
	p = malloc(sizeof(char) * (size + 1));
	if (p == NULL)
		return (NULL);

	for (i = 0; i < size; i++)
		p[i] = str[i];
	p[i] = '\0';
	return (p);

}
