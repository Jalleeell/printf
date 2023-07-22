#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>

#define BUFF 1024

int _putchar(int c);
int	print_string(char *str);
int give_oct(unsigned int n);
void print_hex1(unsigned int nbr, int *len);
int give_address(void *ptr);
int give_len(unsigned int num);
char* utostr(unsigned int n);
int give_unsigned(unsigned int n);
void print_hex2(unsigned int nbr, int *len);
void print_deci(int nbr, int *len);
int _printf(const char *format, ...);

#endif
