#include "main.h"

/**
 * _size - calculates size of arg
 * @form: formatted string to print
 * @p:list of arguments
 *
 * Return: Precision.
 */

int _size(const char *form, int *p)
{
	int current_int = *p + 1;
	int size_str = 0;

	if (form[current_int] == 'l')
		size_str = S_LONG;
	else if (form[current_int] == 'h')
		size_str = S_SHORT;

	if (size_str == 0)
		*p = current_int - 1;
	else
		*p = current_int;

	return (size_str);
}
