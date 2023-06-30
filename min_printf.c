#include "main.h"
#include <string.h>

/*
 * _printf - function that handles c, s, and literal %
 * @ch: variable that stores characters.
 * @str: varibale that store strings
 * @p: pointer to the next format
 * @ap: argument pointer
 */

int _printf(const char *format, ...)
{
	va_list ap;
	char *p, *str;
	int ch;

	va_start(ap, format);

	for (p = format; *p; format++)
	{
		if (*p != '%')
		{
			putchar(*p);
			continue;
		}
		switch (format++)
		{
			case'c':
				ch = va_arg(ap, int);
				putchar(ch);
				format++;
				break;

			case's':
				str = va_arg(ap, char *);
				fputs(str, stdout);
				*p += strlen(str);
				break;

			case'%':
				putchar('%');
				format++;
				break;

			default:
				putchar(*p);
				break;
		}
	}
	va_end(ap);
}
