#include "main.h"

/**
 * give_address - Prints address
 * @ptr: pointer to print address of
 *
 * Return: Number of characters printed
 */
int give_address(void *ptr)
{
	unsigned long int adrs = (unsigned long int)ptr;
	int len = 0;

	print_string("0x");

	if (adrs == 0)
	{
		_putchar('0');
		len++;
	}
	else
	{
		print_hex1(adrs, &len);
	}
	return (len);
}

/**
 * give_len - gives lenght of an unsigned integer
 * @num: unsigned integer
 *
 * Return: The number of digits in integer
 */
int give_len(unsigned int num)
{
	int l = 0;

	while (num != 0)
	{
		l++;
		num = num / 10;
	}
	return (l);
}

/**
 * utostr - Converts unsigned to a string
 * @n: unsigned to convert
 *
 * Return: string representation
 */
char *utostr(unsigned int n)
{
	char *num;
	int l = give_len(n);

	num = (char *)malloc(sizeof(char) * (l + 1));
	if (!num)
		return (NULL);

	num[l] = '\0';

	while (n != 0)
	{
		num[l - 1] = n % 10 + '0';
		n = n / 10;
		l--;
	}
	return (num);
}

/**
 * give_unsigned - Print an unsigned integer
 * @n:unsigned integer to print
 *
 * Return: Number of characters printed
 */
int give_unsigned(unsigned int n)
{
	int print_len = 0;

	if (n == 0)
		print_len += write(1, "0", 1);
	else
	{
		char *num = utostr(n);

		if (num)
		{
			print_len += print_string(num);
			free(num);
		}
	}
	return (print_len);
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
