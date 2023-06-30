#include "main.h"

/**
 * print_binary - print binary numbers
 * @num: number to be converted to binaru number
 *
 * Return- binary
 */

void print_binary(unsigned int num)
{
	if (num > 1)
	{
		print_binary(num / 2);
	}
	printf("%d", num % 2);
}

/**
 * _custom_printf - printf function to help print binary numbers
 * @format: format
 *
 * Return: prints binary
 */

void _custom_printf(const char *format, ...)
{
	va_list args;

	va_start(args, format);

	while (*format)
	{
		if (*format == '%')
		{
			format++;

			if (*format == 'b')
			{
				unsigned int num = va_arg(args, unsigned int);

				print_binary(num);
			}
			else
			{
				putchar(*format);
			}
		}
		else
		{
			putchar(*format);
		}
		format++;
	}
	va_end(args);
}
