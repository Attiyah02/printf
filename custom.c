#include "main.h"
/*
 * custom_printf - prints the custom assigning flags
 * @num: random  number to printed
 */

void custom_printf(const char *format, ...)
{
	va_list args;

	va_start(args, format);

	while (*format)
	{
		if (*format == '%')
		{
			int flag_plus = 0;
			int flag_space = 0;
			int flag_hash = 0;
			format++;

			while (*format == '+' || *format == ' ' || *format == '#')
			{
				if (*format == '+')
				{
					flag_plus = 1;
				}
				else if (*format == ' ')
				{
					flag_space = 1;
				}
				else if (*format == '#')
				{
					flag_hash = 1;
				}
				format++;
			}

			switch (*format)
			{
				case 'd':
				case 'i':
				{
					int num = va_arg(args, int);

					if (flag_plus && num >= 0)
					{
						putchar('+');
					}
					else if (flag_space && num >= 0)
					{
						putchar(' ');
					}
					printf("%d", num);
					break;
				}
				case 'x':
				{
					unsigned int num = va_arg(args, unsigned int);

					if (flag_hash)
					{
						printf("0x");
					}
					printf("%x", num);
					break;
				}
				format++;
			}
		}

	}
	va_end(args);
}




