#include "main.h"

/**
 * _flags_active - calculates active flags
 * @form: string to print the arguments
 * @p: takes parameter
 *
 * Return: flags
 */

int _flags_active(const char *form, int *p)
{
	int j, current_int;
	int flags = 0;
	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (current_int = *p + 1; form[current_int] != '\0'; current_int++)
	{
		for (j = 0; FLAGS_CH[j] != '\0'; j++)
			if (form[current_int] == FLAGS_CH[j])
			{
				flags |= FLAGS_ARR[j];
				break;
			}

		if (FLAGS_CH[j] == 0)
			break;
	}

	*p = current_int - 1;

	return (flags);
}
