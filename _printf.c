#include "main.h"

/**
* print_bin - prints the binary representation of a number
* @nbr: the given number
* @base: the given base
* @len: Pointer to the length counter
*/
void print_bin(unsigned int n, unsigned int base, int *counter)
{
	if (n < base)
		*counter += _putchar(n + '0');
	else
	{
		print_bin(n / base, base, counter);
		print_bin(n % base, base, counter);
	}
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
			else if (format[i] == 'c')
				len += _putchar(va_arg(ptr, int));
			else if (format[i] == 'd' || format[i] == 'i')
				print_deci(va_arg(ptr, int), &len);
			else if (format[i] == 'b')
				print_bin(va_arg(ptr, unsigned int), 2, &len);
			else if (format[i] == 'o')
				print_bin(va_arg(ptr, unsigned int), 8, &len);
			else if (format[i] == 'u')
				print_bin(va_arg(ptr, unsigned int), 10, &len);
			else if (format[i] == 'x')
				print_hex1(va_arg(ptr, unsigned int), &len);
			else if (format[i] == 'X')
				print_hex2(va_arg(ptr, unsigned int), &len);
			else if (format[i] == '%')
				len += _putchar(format[i]);
			else if (format[i] == 's')
				len += print_string(va_arg(ptr, char *));
			else
			{
				len += _putchar('%');
				len += _putchar(format[i]);
			}
		}
		else
			len += _putchar(format[i]);
		i++;
	}
	va_end(ptr);
	return (len);
}
