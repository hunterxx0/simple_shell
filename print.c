#include "header.h"

/**
 * csignal(:)? (- c)?
 * @x : signal.
 * Return:
 */
void csignal(int x)
{
	(void)x;
	_print("\n#cisfun$ ");
}

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}


/**
 * _print - print a text in the standar output
 *
 * @s: input int
 * Return: Void.
 */

void _print(char *s)
{
	int i = 0;

	for (i = 0; s[i]; i++)
		;
	write(STDOUT_FILENO, s, i);
}

/**
 * print_number - prints an integer.
 * @n: No parameters
 * Return: void
 */

void print_number(int n)
{
	int x = 0, j = 0, i = 0, n1 = 0, n2 = n, k = 1;

	if (n == 0)
		_putchar(48);
	else
	{
		if (n < 0)
		{
			_putchar('-');
			if (n == -2147483648)
				n += 1;
			n = -n;
		}
		n1 = n;
		while (n > 0)
		{
			n = n / 10;
			i++;
			if (i > 1)
				k *= 10;
		}
		for (j = 0 ; j < i ; j++)
		{
			x = n1 / k;
			if (n2 == -2147483648 && j == i - 1)
				x += 1;
			_putchar(x + '0');
			n1 = n1 % k;
			k /= 10;
		}
	}
}
