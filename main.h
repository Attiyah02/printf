#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

#define BUFF_SIZE 1024

/**
 * typedef struct fmt fmt_t - struct operand
 * @spec: format
 * @fmt_t: function
 */

typedef struct spec fmt_t;

/*prototype*/
int d_conversion(va_list arg_types, char buffer_arr[],
		int flags, int width, int precision, int size);

/*width handler*/
int write_number(int is_neg, int w, char buffer_arr[],
		int flags, int width, int precision, int size);

long int size_number_conversion(long int num, int size);

#endif
