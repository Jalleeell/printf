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
			else if (format[i] == 'o')
				len += give_oct(va_arg(ptr, unsigned int));
			else if (format[i] == 'u')
				len += give_unsigned(va_arg(ptr, unsigned int));
			else if (format[i] == 'p')
				len += give_address(va_arg(ptr, void *));
			else
			{
				_putchar('%');
				len++;
				len +=_putchar(format[i]);
			}
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
	_printf("Unsigned:[%u]\n", ui);
	printf("Unsigned:[%u]\n", ui);
	_printf("Unsigned octal:[%o]\n", ui);
	printf("Unsigned octal:[%o]\n", ui);
	_printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
	printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
	_printf("Character:[%c]\n", 'H');
	printf("Character:[%c]\n", 'H');
	_printf("String:[%s]\n", "I am a string !");
	printf("String:[%s]\n", "I am a string !");
	_printf("Addas:[%p]\n", addr);
	printf("Addas:[%p]\n", addr);
	len = _printf("Percent:[%%]\n");
	len2 = printf("Percent:[%%]\n");
	_printf("Len:[%d]\n", len);
	printf("Len:[%d]\n", len2);
	_printf("Unknown:[%r]\n");
	printf("Unknown:[%r]\n");
	return (0);
}
