#include "main.h"


/**
 * print_string - Prints a string while non-printable characters
 * are printed this way: \x
 * @str: string to print
 *
 * Return: Number of char
 */

int print_string(char *str)
{
	int i = 0, len = 0;

	while (str[i])
	{
		if (str[i] >= 32 && str[i] <= 126)
		{
			_putchar(str[i]);
			len++;
		}
		else
		{
			len += write(1, "\\x", 2);
			print_hex2(str[i], &len);
		}
		i++;
	}
	return (len);
}
