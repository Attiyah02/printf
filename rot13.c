#include "main.h"

/**
 * p_conversion - prints pointer
 * @arg_types: list of arguments
 * @buffer_arr: buffer array that prints
 * @flags: active flags
 * @width: width length
 * @precision: precision
 * @size: size
 *
 * Return: pointer
 */

int p_conversion(va_list arg_types, char buffer_arr[], int flags,
		int width, int precision, int size)
{
	char stringc = 0, padd = ' ';
	int i = BUFF_SIZE - 2, length = 2, padd_start = 1;
	unsigned long number_address;
	char link_to[] = "0123456789abcdef";
	void *address = va_arg(arg_types, void *);

	UNUSED(width);
	UNUSED(size);

	if (address == NULL)
		return (write(1, "(nil)", 5));

	buffer_arr[BUFF_SIZE - 1] = '\0';
	UNUSED(precision);

	number_address = (unsigned long)address;

	while (number_address > 0)
	{
		buffer_arr[i--] = link_to[number_address % 16];
		number_address /= 16;
		length++;
	}

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padd = '0';
	if (flags & F_PLUS)
		stringc = '+', length++;
	else if (flags & F_SPACE)
		stringc = ' ', length++;
	i++;

	return (write_point(buffer_arr, i, length, width, flags,

				padd, stringc, padd_start));
}

/**
 * write_point- write argument memory address
 * @buff_arr: arrays of char
 * @lp: loop start for buffer
 * @len: length of number
 * @width: width specifier
 * @flags: flags specifier
 * @padd: har of the padd
* @ex_char: char of extra char
 * @padd_start:loop start padd
*
 * Return: number of chars written.
 */

int write_point(char buff_arr[], int lp, int len,
	int width, int flags, char padd, char ex_char, int padd_start)
{
	int j;

	if (width > len)
	{
		for (j = 3; j < width - len + 3; j++)
			buff_arr[j] = padd;
		buff_arr[j] = '\0';
		if (flags & F_MINUS && padd == ' ')/* more character of  buffer */
		{
			buff_arr[--lp] = 'x';
			buff_arr[--lp] = '0';
			if (ex_char)
				buff_arr[--lp] = ex_char;
			return (write(1, &buff_arr[lp], len) + write(1, &buff_arr[3], j - 3));
		}
		else if (!(flags & F_MINUS) && padd == ' ')/* more character of  buffer */
		{
			buff_arr[--lp] = 'x';
			buff_arr[--lp] = '0';
			if (ex_char)
				buff_arr[--lp] = ex_char;
			return (write(1, &buff_arr[3], j - 3) + write(1, &buff_arr[lp], len));
		}
		else if (!(flags & F_MINUS) && padd == '0')/* more character for pad */
		{
			if (ex_char)
				buff_arr[--padd_start] = ex_char;
			buff_arr[1] = '0';
			buff_arr[2] = 'x';
			return (write(1, &buff_arr[padd_start], j - padd_start) +
				write(1, &buff_arr[lp], len - (1 - padd_start) - 2));
		}
	}
	buff_arr[--lp] = 'x';
	buff_arr[--lp] = '0';
	if (ex_char)
		buff_arr[--lp] = ex_char;
	return (write(1, &buff_arr[lp], BUFF_SIZE - lp - 1));
}

/**
 *  r_conversion - prints string in reverse
 *  @arg_types: list of arguments
 *  @buffer_arr: buffer array that handles print
 *  @flags: flags
 *  @width: width
 *  @precision: precision
 *  @size: size
 *
 * Return:reverse of a string
 */

int r_conversion(va_list arg_types, char buffer_arr[],
		int flags, int width, int precision, int size)
{
	char *str;
	int j, count = 0;

	UNUSED(buffer_arr);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(size);

	str = va_arg(arg_types, char *);

	if (str == NULL)
	{
		UNUSED(precision);

		str = ")Null(";
	}

	for (j = 0; str[j]; j++)
		;

	for (j = j - 1; j >= 0; j--)
	{
		char b = str[j];

		write(1, &b, 1);
		count++;
	}
	return (count);
}

/**
 * conversion_R - prints a rot13 string
 * @arg_types: list of arguments
 * @buffer_arr: buffer array to be handled print
 * @flags: active flags
 * @width: width
 * @precision: precision
 * @size sSize
 *
 * Return: an rot13 string
 */

int conversion_R(va_list arg_types, char buffer_arr[],
	int flags, int width, int precision, int size)
{
	char v;
	char *str;
	unsigned int k, l;
	int count = 0;
	char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	str = va_arg(arg_types, char *);
	UNUSED(buffer_arr);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (str == NULL)
		str = "(AHYY)";
	for (k = 0; str[k]; k++)
	{
		for (l = 0; in[l]; l++)
		{
			if (in[l] == str[l])
			{
				v = out[l];
				write(1, &v, 1);
				count++;
				break;
			}
		}
		if (!in[l])
		{
			v = str[k];
			write(1, &v, 1);
			count++;
		}
	}
	return (count);
}
