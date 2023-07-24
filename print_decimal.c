#include "main.h"

/**
 * print_deci - prints a decimal number
 * @nbr: number
 * @len: Pointer to the length counter
 */
void print_deci(int nbr, int *len)
{
	char str[] = "0123456789";

	if (nbr < 0)
	{
		*len += _putchar('-');
		nbr = -nbr;
	}

	if (nbr >= 10)
		print_deci(nbr / 10, len);

	*len += _putchar(str[nbr % 10]);
}
