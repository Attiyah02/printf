#include "main.h"

/**
 * handling_functions- prints argument by specifier handler
 * @form: string being printed
 * @p: pointer of var
 * @lst: argument lst
 * @buffer_arr: array container
 * @flags: flags active
 * @width: width length
 * @precision: precision
 * @size: size
 *
 * Return: 1 or 2
 */

int handling_functions(const char *form, int *p, va_list lst,
		char buffer_arr[], int width, int size, int precision, int flags)
{
	int b, un = 0, p_char = -1;
	fnct str_arr[] = {{'d', d_conversion}, {'i', d_conversion},
		{0, NULL}};

	for (b = 0; str_arr[b].form != '\0'; b++)
		if (form[*p] == str_arr[b].form)
			return (str_arr[b].func(lst, buffer_arr, flags, width, precision, size));

	if (str_arr[b].form == '\0')
	{
		if (form[*p] == '\0')
			return (-1);
		un += write(1, "%%", 1);
		if (form[*p - 1] == ' ')
			un += write(1, " ", 1);
		else if (width)
		{
			--(*p);
			while (form[*p] != ' ' && form[*p] != '%')
				--(*p);
			if (form[*p] == ' ')
				--(*p);
			return (1);
		}
		un += write(1, &form[*p], 1);
		return (un);
	}
	return (p_char);
}

/**
 * is_digit - verifies char is a digit
 *@d: char being checked
 *
 * Return: 1 Successful else 0
 */

int is_digit(char d)
{
	if (d >= '0' && d <= '9')
		return (1);

	return (0);
}

/**
 * size_number_conversion - gives number to size
 *@num: number being used
 *@size: type of number
 *
 * Return: value of num
 */

long int size_number_conversion(long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((short)num);

	return ((int)num);

}

/**
 * write_number - prints a string
 * @is_neg: list of arguments
 * @w: char .
 * @buffer_arr: buffer that handles prints
 * @flags:calculates flags
 * @width: width length
 * @precision: precision specifier
 * @size: size specifier
 *
 * Return: a strin.
 */

int write_number(int is_neg, int w, char buffer_arr[],
	int flags, int width, int precision, int size)
{
	int length = BUFF_SIZE - w - 1;
	char padd = ' ', ex_char = 0;

	UNUSED(size);

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padd = '0';
	if (is_neg)
		ex_char = '-';
	else if (flags & F_PLUS)
		ex_char = '+';
	else if (flags & F_SPACE)
		ex_char = ' ';

	return (write_num(w, buffer_arr, flags, width, precision,
		length, padd, ex_char));
}

/**
 * write_num - writesnumber using bufffer
 * @w:l start of buffer
 * @buffer_arr: array of char
 * @flags: flags
 * @width: width
 * @precision: precision specifier
 * @length:Number of length
 * @padd:Pading character
 * @ex_char:more character
 *
 * Return: no. of chars
 */

int write_num(int w, char buffer_arr[],
	int flags, int width, int precision,
	int length, char padd, char ex_char)
{
	int j, padd_start = 1;

	if (precision == 0 && w == BUFF_SIZE - 2 &&
			buffer_arr[w] == '0' && width == 0)
		return (0);
	if (precision == 0 && w == BUFF_SIZE - 2 && buffer_arr[w] == '0')
		buffer_arr[w] = padd = ' ';
	if (precision > 0 && precision < length)
		padd = ' ';
	while (precision > length)
		buffer_arr[--w] = '0', length++;
	if (ex_char != 0)
		length++;
	if (width > length)
	{
		for (j = 1; j < width - length + 1; j++)
			buffer_arr[j] = padd;
		buffer_arr[j] = '\0';
		if (flags & F_MINUS && padd == ' ')
		{
			if (ex_char)
				buffer_arr[--w] = ex_char;
			return (write(1, &buffer_arr[w], length) + write(1, &buffer_arr[1], j - 1));
		}
		else if (!(flags & F_MINUS) && padd == ' ')
		{
			if (ex_char)
				buffer_arr[--w] = ex_char;
			return (write(1, &buffer_arr[1],
						j - 1) + write(1, &buffer_arr[w], length));
		}
		else if (!(flags & F_MINUS) && padd == '0')
		{
			if (ex_char)
				buffer_arr[--padd_start] = ex_char;
			return (write(1, &buffer_arr[padd_start], j - padd_start) +
				write(1, &buffer_arr[w], length - (1 - padd_start)));
		}
	}
	if (ex_char)
	{
		buffer_arr[--w] = ex_char;
	}
	return (write(1, &buffer_arr[w], length));
}
