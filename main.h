#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <unistd.h>

#define BUFF_SIZE 1024
#define UNUSED(x) (void)(x)

#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

#define S_LONG 2
#define S_SHORT 1

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
 * typedef struct fnc fnct - struct operator
 * @form: format
 * @fnct: function
 */

typedef struct form fnct;

int _printf(const char *str_first, ...);
int handling_functions(const char *form, int *p, va_list lst, char buffer_arr[],
	int width, int size, int precision, int flags);

/*prototype for functions*/
int d_conversion(va_list arg_types, char buffer_arr[],
		int flags, int width, int precision, int size);

/*prototype for flags*/
int width_calculator(const char *format_str, int *p, va_list lst);
int _flags_active(const char *form, int *p);
int precision_calc(const char *form, int *p, va_list lst);
int _size(const char *form, int *p);

/*width handler*/
int write_number(int is_neg, int w, char buffer_arr[],
		int flags, int width, int precision, int size);
int write_num(int w, char buffer_arr[],
	int flags, int width, int precision,
	int length, char padd, char ex_char);

int is_digit(char);

long int size_number_conversion(long int num, int size);

#endif
