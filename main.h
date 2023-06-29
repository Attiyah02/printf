#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

#define BUFF_SIZE 1024

/**
 * struct form- new struct
 * @form: format of struct
 * @func: function.
 */

struct form
{
	char form;
	int (*func)(va_list, char[], int, int, int, int);
};

/**
 * typedef struct fnct - struct operator
 * @form: format
 * @fnct: function
 */

typedef struct form fnct;

int _printf(const char *str_first, ...);
int handling_functions(const char *form, int *p, va_list lst, char buffer_arr[],
	int width, int size, int precision, int flags)

/*prototype for functions*/
int d_conversion(va_list arg_types, char buffer_arr[],
		int flags, int width, int precision, int size);

/*prototype for flags*/
int width_calculator(const char *format_str, int *p, va_list lst);

/*width handler*/
int write_number(int is_neg, int w, char buffer_arr[],
		int flags, int width, int precision, int size);

int is_digit(char);

long int size_number_conversion(long int num, int size);
void print_binary(int num, ...);
int _printf(char *format, ...);
void _custom_printf(const char *format, ...);
void _custom_flags(const char * format, ...);


#endif
