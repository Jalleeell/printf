#include "main.h"

/********still working on it*******/

/**
 * give_address - Prints pointer address
 * @ptr: pointer to print address of
 *
 * Return: len
 */

int give_address(unsigned long long ptr)
{
	int len = 0;

	len += print_string("0x");
	if (ptr == 0)
	{
		len += _putchar('0');
	}
	else
	{
		print_hex1(ptr, &len);
		len += give_len(ptr);
	}
	return (len);
}

/******** potential better function ********/

/*int give_address(void *ptr, int *ln)
  {
  print_string("0x", ln);
  print_hex1((unsigned long long)ptr, ln);
  return (*ln);
  }*/
