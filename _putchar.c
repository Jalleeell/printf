#include "main.h"

/**
 * _putchar - Custom putchar
 * @c: character to be printed
 *
 * Return: Number of characters printed
 */
int _putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

