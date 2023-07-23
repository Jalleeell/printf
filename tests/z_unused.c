#include "main.h"

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

/****============****/
int _putchar(int c)
{
	write (1, &c, 1);
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

void print_hex2(unsigned int nbr, int *len)
{
	char str[] = "0123456789ABCDEF";

	if (nbr >= 16)
		print_hex2(nbr / 16, len);
	*len += write (1, &str[nbr % 16], 1);
}

void print_decioctal(int nbr, int *len)
{
	char str[] = "0123456789";

	if (nbr < 0)
	{
		*len += putchar ('-');
		nbr = -nbr;
	}
	if (nbr >= 10)
		print_decioctal(nbr / 10, len);
	*len += write (1, &str[nbr % 10], 1);
}

void print_hex1(unsigned int nbr, int *len)
{
	char str[] = "0123456789abcdef";

	if (nbr >= 16)
		print_hex1(nbr / 16, len);
	*len += write (1, &str[nbr % 16], 1);
}

int _printf(const char *format, ...)
{
	va_list ptr;
	int len;
	int	i;

	i = 0;
	len = 0;
	va_start(ptr, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == 'c')
				len += _putchar(va_arg(ptr, int));
			else if (format[i] == 'd' || format[i] == 'i')
				print_decioctal(va_arg(ptr, int), &len);
			else if (format[i] == 'b')
				print_decioctal(va_arg(ptr, int), &len);
			else if (format[i] == 'x')
				print_hex1(va_arg(ptr, unsigned int), &len);
			else if (format[i] == 'X')
				print_hex2(va_arg(ptr, unsigned int), &len);
			else if (format[i] == '%')
				len += _putchar(format[i]);
			else if (format[i] == 's')
				len += print_string(va_arg(ptr, char *));
			else
				len +=_putchar(format[i]);
		}
		else
			len +=_putchar(format[i]);
		i++;
	}
	return (len);
}
