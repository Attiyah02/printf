#include "main.h"

/**
 * converts_perc - prints a percentage
 * @lst: list of arguments
 * @buff_arr: buffer array that handles print
 * @flags:flags
 * @width: width
 * @precision: precision
 * @size: size
 *
 * Return:a percentage
 */

int converts_perc(va_list lst, char buff_arr[],
	int flags, int width, int precision, int size)
{
	UNUSED(lst);
	UNUSED(buff_arr);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	return (write(1, "%%", 1));
}
