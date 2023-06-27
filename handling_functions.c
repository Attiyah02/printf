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
	fnct str_arr[] = {
		{'d', d_conversion}, {'i', d_conversion},
		{0, NULL}
	};
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
