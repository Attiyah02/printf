#include "main.h"

/**
 * precision_calc - calculates the precision
 * @form: formatted string
 * @p: list of arguments
 * @lst: list of arguments
 *
 * Return: precision.
 */

int precision_calc(const char *form, int *p, va_list lst)
{
	int current_int = *p + 1;
	int precision = -1;

	if (form[current_int] != '.')
		return (precision);

	precision = 0;

	for (current_int += 1; form[current_int] != '\0'; current_int++)
	{
		if (is_digit(form[current_int]))
		{
			precision *= 10;
			precision += form[current_int] - '0';
		}
		else if (form[current_int] == '*')
		{
			current_int++;
			precision = va_arg(lst, int);
			break;
		}
		else
			break;
	}

	*p = current_int - 1;

	return (precision);
}
