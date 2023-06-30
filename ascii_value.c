#include "main.h"

/**
 * does_it_print - evaluates if a char is printable
 * @c: char being evaluated
 *
 * Return: 1 (Successful) else 0
 */

int does_it_print(char c)
{
	int val = 0;

	if (c >= 32 && c < 127)
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
