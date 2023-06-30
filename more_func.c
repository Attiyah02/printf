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

#include "main.h"
/**
 * write_char - prints a string
 * @c: char types.
 * @buff_arr: buffer array to handle print
 * @flags:calc active flags
 * @width: width
 * @precision: precision specifier
 * @size: size specifier
*
 * Return: Number of characters printed.
 */

int write_char(char c, char buff_arr[],
	int flags, int width, int precision, int size)
{
	/*storing character at left of padding and right of buffer*/
	int j = 0;
	char padd = ' ';

	UNUSED(precision);
	UNUSED(size);

	if (flags & F_ZERO)
		padd = '0';

	buff_arr[j++] = c;
	buff_arr[j] = '\0';

	if (width > 1)
	{
		buff_arr[BUFF_SIZE - 1] = '\0';
		for (j = 0; j < width - 1; j++)
			buff_arr[BUFF_SIZE - j - 2] = padd;

		if (flags & F_MINUS)
			return (write(1, &buff_arr[0], 1) +
					write(1, &buff_arr[BUFF_SIZE - j - 1], width - 1));
		else
			return (write(1, &buff_arr[BUFF_SIZE - j - 1], width - 1) +
					write(1, &buff_arr[0], 1));
	}

	return (write(1, &buff_arr[0], 1));
}
