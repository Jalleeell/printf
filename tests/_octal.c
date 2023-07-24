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
