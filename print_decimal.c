#include "main.h"

/**
 * print_deci - prints a decimal number
 * @nbr: number
 * @len: Pointer to the length counter
 */
void print_deci(int nbr, int *len)
{
	char str[] = "0123456789";
	unsigned int n = nbr;

	if (nbr < 0)
	{
		*len += _putchar('-');
		n = -nbr;
	}

	if (n >= 10)
		print_deci(n / 10, len);

	*len += _putchar(str[n % 10]);
}

