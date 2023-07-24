#include "main.h"


/**
 * print_u -  function to print an unsigned
 * @n: The unsigned integer to print
 *
 * Return: Number of characters printed
 */

int print_u(unsigned int n)
{
	int len = 0;

	char c;

	if (n >= 10)
		len += print_u(n / 10);

	c = '0' + n % 10;
	len += write(1, &c, 1);

	return (len);
}

/**
 * give_unsigned - Prints unsigned
 * @n: The unsignd to print
 *
 * Return: Number of characters printed
 */
int give_unsigned(unsigned int n)
{
	if (n == 0)
		return (_putchar('0'));

	return (print_u(n));
}
