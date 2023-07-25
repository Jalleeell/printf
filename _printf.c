#include "main.h"

/**
 * print_non_printable - Prints a string while non-printable characters
 * are printed this way: \x
 * @str: string to print
 *
 * Return: Number of char
 */
int print_non_printable(char *str)
{
	int i = 0, len = 0;

	while (str[i])
	{
		if (str[i] >= 32 && str[i] <= 126)
			len += _putchar(str[i]);
		else
		{
			len += _putchar('\\');
			len += _putchar('x');
			if (str[i] < 16)
				len += _putchar('0');
			print_hex2(str[i], &len);
		}
		i++;
	}
	return (len);
}

/**
* print_bou - prints the binary representation of a number
* @nbr: the given number
* @base: the given base
* @len: Pointer to the length counter
*/
void print_bou(unsigned int nbr, unsigned int base, int *len)
{
	if (nbr >= base)
		print_bou(nbr / base, base, len);
	*len += _putchar((nbr % base) + '0');
}

/**
* check_formats - finder data type
* @c: the data type
* @ptr: arguments pointer
* Return: Number of char
*/
int	check_formats(char c, va_list ptr)
{
	int len = 0;

	if (c == 'c')
		len += _putchar(va_arg(ptr, int));
	else if (c == 'd' || c == 'i')
		print_deci(va_arg(ptr, int), &len);
	else if (c == 'b')
		print_bou(va_arg(ptr, unsigned int), 2, &len);
	else if (c == 'o')
		print_bou(va_arg(ptr, unsigned int), 8, &len);
	else if (c == 'u')
		print_bou(va_arg(ptr, unsigned int), 10, &len);
	else if (c == 'x')
		print_hex1(va_arg(ptr, unsigned int), &len);
	else if (c == 'X')
		print_hex2(va_arg(ptr, unsigned int), &len);
	else if (c == '%')
		len += _putchar(c);
	else if (c == 's')
		len += print_string(va_arg(ptr, char *));
	else if (c == 'S')
		len += print_non_printable(va_arg(ptr, char *));
	else if (c == 'R')
		len += _rot13(va_arg(ptr, char *));
	else if (c == 'r')
		len += rev_str(va_arg(ptr, char *));
	else
	{
		len += _putchar('%');
		len += _putchar(c);
	}
	return (len);
}

/**
 * _printf - A custom printf
 * @format: The format string that contains the format specifiers
 *
 * Return: Number of characters printed
 */

int _printf(const char *format, ...)
{
	va_list ptr;
	int len = 0, i = 0;

	va_start(ptr, format);
	if (!format)
		return (-1);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (!format[i])
				return (-1);
			len += check_formats(format[i], ptr);
		}
		else
			len += _putchar(format[i]);
		i++;
	}
	va_end(ptr);
	return (len);
}
