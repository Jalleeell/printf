#include "main.h"

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

/**
 * print_hex2 - print the hexadecimal in uppercase
 * @nbr: input number
 * @len: Pointer to length counter
 */
void print_hex2(unsigned int nbr, int *len)
{
	char str[] = "0123456789ABCDEF";

	if (nbr >= 16)
		print_hex2(nbr / 16, len);

	*len += write(1, &str[nbr % 16], 1);
}