#include "main.h"

void _buffer(char buff_arr[], int *int_buffer);

/**
 * _printf-print as the printf lib
 * @str_first: format
 *
 * Return - arguements
 */

int _printf(const char *str_first, ...)
{
	int c, p_char = 0, str = 0;
	int flags, width, precision, size, int_buffer = 0;
	va_list lst;
	char buff_arr[BUFF_SIZE];

	if (str_first == NULL)
		return (-1);

	va_start(lst, str_first);

	for (c = 0; str_first && str_first[c] != '\0'; c++)
	{
		if (str_first[c] != '%')
		{
			buff_arr[int_buffer++] = str_first[c];
			if (int_buffer == BUFF_SIZE)
				_buffer(buff_arr, &int_buffer);
			p_char++;
		}
		else
		{
			_buffer(buff_arr, &int_buffer);
			flags = _flags_active(str_first, &c);
			width = width_calculator(str_first, &c, lst);
			precision = precision_calc(str_first, &c, lst);
			size = _size(str_first, &c);
			++c;
			str = handling_functions(str_first, &c, lst, buff_arr,
				flags, width, precision, size);
			if (str == -1)
				return (-1);
			p_char += str;
		}
	}

	_buffer(buff_arr, &int_buffer);

	va_end(lst);

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
