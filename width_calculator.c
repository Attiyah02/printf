#include "main.h"

/**
 * width_calculator - calculates width to print
 * @format_str: formatted string to print arg.
 * @p: List of arguments to be printed.
 * @lst: list of arguments.
 *
 * Return: width
 */

int width_calculator(const char *format_str, int *p, va_list lst)
{
	int pres_int;
	int width = 0;

	for (pres_int = *p + 1; format_str[pres_int] != '\0'; pres_int++)
	{
		if (is_digit(format_str[pres_int]))
		{
			width *= 10;
			width += format_str[pres_int] - '0';
		}
		else if (format_str[pres_int] == '*')
		{
			pres_int++;
			width = va_arg(lst, int);
			break;
		}
		else
			break;
	}

	*p = pres_int - 1;

	return (width);
}

