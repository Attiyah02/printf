#include "main.h"

/**
 * d_conversion - prints an integer
 * @arg_types: list of arguments
 * @buffer_arr: buffer array that handles print
 * @flags:flags active
 * @width: width length
 * @precision: precision specifier
 * @size: size specifier
 *
 * Return:an integer
 */

int d_conversion(va_list arg_types, char buffer_arr[],
		int flags, int width, int precision, int size)
{
	int w = BUFF_SIZE - 2;
	int is_neg = 0;
	long int l = va_arg(arg_types, long int);
	unsigned long int number;

	l = size_number_conversion(l, size);

	if (l == 0)
		buffer_arr[w--] = '0';

	buffer_arr[BUFF_SIZE - 1] = '\0';
	number = (unsigned long int)l;

	if (l < 0)
	{
		number = (unsigned long int)(-1);
		is_neg = 1;
	}

	do {
		buffer_arr[w++] = (number % 10) + '0';
		number /= 10;
	} while (number > 0);
	w--;

	return (write_number(is_neg, w, buffer_arr, flags, width, precision, size));
}