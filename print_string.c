#include "main.h"

/**
 * print_string - prints a string
 * @str: string to be printed
 *
 * Return: Number of characters printed
 */
int print_string(char *str)
{
	int i = 0;

	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}

	while (str[i])
		write(1, &str[i++], 1);

	return (i);
}

