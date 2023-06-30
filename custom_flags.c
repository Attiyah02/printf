#include "main.h"



void custom_prinft(const char *format, ...)
{
	va_list args;

	va_start(args, format);

	while (*format)
	{
		format++;
		int flag_plus = 0;
		int flag_space = 0;
		int flag_hash = 0;
		int length_modifier = 0;

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

		if (*format == 'l')
		{
			length_modifier = 1;
			format++;
		}
		else if (*format == 'h')
		{
			length_modifier = -1;
			format++;
		}

		switch (*format)
		{
			case 'd':
			case 'i':
			{
				int num;

				if (length_modifier == 1)
				{
					num = va_arg(args, long);
				}
				else if (length_modifier == -1)
				{
					num = va_arg(args, int);
				}
				else
				{
					num = va_arg(args, int);
				}
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
			case 'u':
			{
				unsigned int num;

				if (length_modifier == 1)
				{
					num = va_arg(args, unsigned long);
				}
				else if (length_modifier == -1)
				{
					num = va_arg(args, unsigned int);
				}
				else
				{
					num = va_arg(args, unsigned int);
				}
				printf("%u", num);
				break;
			}
			case 'o':
			{
				unsigned int num;

				if (length_modifier == 1)
				{
					num = va_arg(args, unsigned long);
				}
				else if (length_modifier == -1)
				{
					num = va_arg(args, unsigned int);
				}
				else
				{
					num = va_arg(args, unsigned int);
				}
				if (flag_hash)
				{
					putchar('0');
				}
				printf("%o", num);
				break;
			}
			case 'x':
			{
				unsigned int num;

				if (length_modifier == 1)
				{
					num = va_arg(args, unsigned long);
				}
				else if (length_modifier == -1)
				{
					num = va_arg(args, unsigned int);
				}
				else
				{
					num = va_arg(args, unsigned int);
				}
				if (flag_hash)
				{
					putchar('0');
					putchar('X');
				}
				printf("%x", num);
				break;
			}
			case 'X':
			{
				unsigned int num;

				if (length_modifier == 1)
				{
					num = va_arg(args, unsigned long);
				}
				else if (length_modifier == -1)
				{
					num = va_arg(args, unsigned int);
				}
				break;
			}
		}
	}
	va_end(args);
}
