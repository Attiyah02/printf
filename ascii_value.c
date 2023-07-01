#include "main.h"

/**
 * does_it_print - evaluates if a char is printable
 * @k: char being evaluated
 *
 * Return: 1 (Successful) else 0
 */

int does_it_print(char k)
{
	int val = 0;

	if (k >= 32 && k < 127)
{
	val = 1;
}
return (val);
}

/**
 * append_hexa - append ascii in hexadecimal code to buffer
 * @buffer: array of chars
 * @a: index to append from
 * @ascii_code: the ascii code
 *
 * Return: Always 3
 */

int append_hexa(char ascii_code, char buffer[], int a)
{
	const char represents_ascii[] = "0123456789ABCDEF";

	if (ascii_code < 0)
		ascii_code = -ascii_code;

	buffer[a] = '\\';
	buffer[a++] = 'x';

	buffer[a++] = represents_ascii[ascii_code / 16];
	buffer[a] = represents_ascii[ascii_code % 16];

	return (3);
}

/**
 * convert_unsigned - turns size into number
 * @number: number being changed
 * @size: size being converted
 *
 * Return: value of number
 */

long int convert_unsigned(unsigned long int number, int size)
{
	if (size == S_LONG)
		return (number);
	else if (size == S_SHORT)
		return ((unsigned short)number);

	return ((unsigned int)number);
}

/**
 * conversion_S - prints a non-printable
 * @arg_types: list of arguments
 * @buff_arr: buffer array
 * @flags:flags
 * @width: width
 * @precision: precision
 *
 * @size: size
 *
 * Return: non-printable
 */

int conversion_S(va_list arg_types, char buff_arr[],
	int flags, int width, int precision, int size)
{
	int j = 0, off = 0;
	char *str = va_arg(arg_types, char *);

	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (str == NULL)
		return (write(1, "(null)", 6));

	while (str[j] != '\0')
	{
		if (does_it_print(str[j]))
			buff_arr[j + off] = str[j];
		else
			off += append_hexa(str[j], buff_arr, j + off);

		j++;
	}

	buff_arr[j + off] = '\0';

	return (write(1, buff_arr, j + off));
}
