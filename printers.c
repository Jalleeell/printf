#include "main.h"

int _putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	print_string(char *str)
{
	int i;

	i = 0;
	if (!str)
	{
		write (1, "(null)", 6);
		return (6);
	}
	while (str[i])
		write(1, &str[i++], 1);
	return (i);
}

int give_oct(unsigned int n)
{
	if (n / 8 != 0)
		give_oct(n / 8);

	return (_putchar((n % 8) + '0'));
}

void print_hex1(unsigned int nbr, int *len)
{
	char str[] = "0123456789abcdef";

	if (nbr >= 16)
		print_hex1(nbr / 16, len);
	*len += write (1, &str[nbr % 16], 1);
}

int give_address(void *ptr)
{
	unsigned long int adrs = (unsigned long int)ptr;
	int len = 0;

	len += _putchar('0');
	len += _putchar('x');

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

int give_len(unsigned int num)
{
	int l = 0;
	while (num != 0) {
		l++;
		num = num / 10;
	}
	return (l);
}

char* utostr(unsigned int n)
{
	char* num;
	int l = give_len(n);
	num = (char*)malloc(sizeof(char) * (l + 1));
	if (!num)
		return NULL;
	num[l] = '\0';
	while (n != 0) {
		num[l - 1] = n % 10 + '0'; // Use '0' instead of 48 (ASCII value for '0')
		n = n / 10;
		l--;
	}
	return num;
}

int give_unsigned(unsigned int n)
{
	int print_len = 0;
	if (n == 0)
		print_len += write(1, "0", 1);
	else {
		char* num = utostr(n);
		if (num) {
			print_len += print_string(num);
			free(num);
		}
	}
	return print_len;
}

void print_hex2(unsigned int nbr, int *len)
{
	char str[] = "0123456789ABCDEF";

	if (nbr >= 16)
		print_hex2(nbr / 16, len);
	*len += write (1, &str[nbr % 16], 1);
}

void print_deci(int nbr, int *len)
{
	char str[] = "0123456789";

	if (nbr < 0)
	{
		*len += write(1, "-", 1);
		nbr = -nbr;
	}
	if (nbr >= 10)
		print_deci(nbr / 10, len);
	*len += write (1, &str[nbr % 10], 1);
}
