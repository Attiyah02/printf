#include "main.h"

void _buffer(char buff_arr[], int *int_buffer);

/**
 * _printf-print as the printf lib
 * @format: format
 *
 * Return:arguments
 */

int _printf(const char *format, ...)
{
	va_list ap;
	const char *p;
	int c, p_char = 0, str_len = 0;
	int flags, width, precision, size, int_buffer = 0;
	char buff_arr[BUFF_SIZE];

	va_start(ap, format);

	for (p = format; *p; p++)
	{
		if (*p != '%')
		{
			buff_arr[int_buffer++] = *p;
			if (int_buffer == BUFF_SIZE)
			{
				_buffer(buff_arr, &int_buffer);
			}
			p_char++;
		}
		else
		{
			_buffer(buff_arr, &int_buffer);
			flags = _flags_active(format, &c);
			width = width_calculator(format, &c, ap);
			precision = precision_calc(format, &c, ap);
			size = _size(format, &c);
			++c;
			str_len = handling_functions(format, &c, ap, buff_arr,
					flags, width, precision, size);
			if (str_len == -1)
			{
				return (-1);
			}
			p_char += str_len;
		}
	}
	_buffer(buff_arr, &int_buffer);
	va_end(ap);

	return (p_char);
}

/**
 * _buffer-Prints the char in a buffer
 * @buff_arr: array of char
 * @int_buffer: len of a buffer
 */
void _buffer(char buff_arr[], int *int_buffer)
{
	if (*int_buffer > 0)
		write(1, &buff_arr[0], *int_buffer);

	*int_buffer = 0;
}
