#include "main.h"

/**
 * _rot13 -  encodes a string using rot13.
 * @str: string
 *
 * Return: lenght of printed string.
 */
int	_rot13(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((str[i] >= 'a' && str[i] <= 'm')
			|| (str[i] >= 'A' && str[i] <= 'M'))
			_putchar(str[i] + 13);
		else if ((str[i] >= 'n' && str[i] <= 'z')
			|| (str[i] >= 'N' && str[i] <= 'Z'))
			_putchar(str[i] - 13);
		else
			_putchar(str[i]);
		i++;
	}
	return (i);
}
