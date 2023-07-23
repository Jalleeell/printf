#include "main.h"

/**
 * _putchar - Custom putchar
 * @c: character to be printed
 *
 * Return: Number of characters printed
 */
int _putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

/**
 * print_string - prints a string
 * @str: string to be printed
 *
 * Return: Number of characters printed
 */
int print_string(char *str)
{
	int i;

	i = 0;

	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}

	while (str[i])
		write(1, &str[i++], 1);

	return (i);
}

/**
 * give_oct - prints octal number
 * @n: The input number
 *
 * Return: Number of characters printed
 */
int give_oct(unsigned int n)
{
	if (n / 8 != 0)
		give_oct(n / 8);

	return (_putchar((n % 8) + '0'));
}

/**
 * print_hex1 - prints hexadecimal in lowercase
 * @nbr: The input number
 * @len: Pointer to the length counter
 */
void print_hex1(unsigned int nbr, int *len)
{
	char str[] = "0123456789abcdef";

	if (nbr >= 16)
		print_hex1(nbr / 16, len);

	*len += write(1, &str[nbr % 16], 1);
}
