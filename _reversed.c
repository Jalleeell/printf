#include "main.h"

/**
 *rev_str - the reverse string
 *
 *@str: the given string.
 *Return: lenght of string
 */
int rev_str(char *str)
{
	int i = 0, len = 0;

	while (str[i])
		i++;
	i--;
	while (i >= 0)
	{
		len += _putchar(str[i]);
		i--;
	}
	return (len);
}
