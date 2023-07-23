#include "main.h"

/**
 * _printf - A custom printf
 * @format: The format string that contains the format specifiers
 *
 * Return: Number of characters printed
 */

int _printf(const char *format, ...)
{
	va_list ptr;
	int len, i;

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
				print_deci(va_arg(ptr, int), &len);
			else if (format[i] == 'b')
				print_deci(va_arg(ptr, int), &len);
			else if (format[i] == 'x')
				print_hex1(va_arg(ptr, unsigned int), &len);
			else if (format[i] == 'X')
				print_hex2(va_arg(ptr, unsigned int), &len);
			else if (format[i] == '%')
				len += _putchar(format[i]);
			else if (format[i] == 's')
				len += print_string(va_arg(ptr, char *));
			else
				len += _putchar(format[i]);
		}
		else
			len += _putchar(format[i]);

		i++;
	}

	va_end(ptr);
	return (len);
}
