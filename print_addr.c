#include "main.h"

/**
 * get_addr - get addr
 *
 * @nbr: given number
 * @len: lenght
 */
void get_addr(unsigned long int nbr, int *len)
{
	char str[] = "0123456789abcdef";

	if (nbr >= 16)
		get_addr(nbr / 16, len);
	*len += write(1, &str[nbr % 16], 1);
}

/**
 * print_addr - print addr
 *
 * @nbr: given number
 * Return: lenght
 */
int print_addr(unsigned long int nbr)
{
	int len = 0;

	if (nbr)
	{
		len = print_string("0x");
		get_addr(nbr, &len);
	}
	else
		len = print_string("(nil)");
	return (len);
}

