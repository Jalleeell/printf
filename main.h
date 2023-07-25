#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>

int		_printf(const char *format, ...);
int		_putchar(int c);
int		print_string(char *str);
void	print_deci(int nbr, int *len);
void	print_hex1(unsigned int nbr, int *len);
void	print_hex2(unsigned int nbr, int *len);
int		_rot13(char *str);
int		rev_str(char *str);
int print_addr(unsigned long int nbr);

#endif
