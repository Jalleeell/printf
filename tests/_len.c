#include "main.h"

/**
 * give_len - gives number of digits in an unsigned int
 * @num: unsigned int
 *
 * Return: number of digits
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
