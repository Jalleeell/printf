#include "main.h"

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

int main(void)
{
    int len;
    int len2;
    unsigned int ui;
    void *addr;

    len = _printf("Let's try to printf a simple sentence.\n");
    len2 = printf("Let's try to printf a simple sentence.\n");
    ui = (unsigned int)INT_MAX + 1024;
    addr = (void *)0x7ffe637541f0;
    _printf("Length:[%d, %i]\n", len, len);
    printf("Length:[%d, %i]\n", len2, len2);
    _printf("Negative:[%d]\n", -762534);
    printf("Negative:[%d]\n", -762534);
    _printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
    printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
    _printf("Character:[%c]\n", 'H');
    printf("Character:[%c]\n", 'H');
    _printf("String:[%s]\n", "I am a string !");
    printf("String:[%s]\n", "I am a string !");
    len = _printf("Percent:[%%]\n");
    len2 = printf("Percent:[%%]\n");
    _printf("Len:[%d]\n", len);
    printf("Len:[%d]\n", len2);
    _printf("Unknown:[%r]\n");
    printf("Unknown:[%r]\n");
    return (0);
}