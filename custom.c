include <stdio.h>
#include <stdarg.h>

void custom_printf(const char* format, ...) {
	    va_list args;
	        va_start(args, format);

		    while (*format) {
			            if (*format == '%') {
					                format++;
							            int flag_plus = 0;
								                int flag_space = 0;
										            int flag_hash = 0;

											                // Check for flag characters
													//             while (*format == '+' || *format == ' ' || *format == '#') {
													//                             if (*format == '+') {
													//                                                 flag_plus = 1;
													//                                                                 } else if (*format == ' ') {
													//                                                                                     flag_space = 1;
													//                                                                                                     } else if (*format == '#') {
													//                                                                                                                         flag_hash = 1;
													//                                                                                                                                         }
													//                                                                                                                                                         format++;
													//                                                                                                                                                                     }
													//
													//                                                                                                                                                                                 // Handle conversion specifiers
													//                                                                                                                                                                                             switch (*format) {
													//                                                                                                                                                                                                             case 'd':
													//                                                                                                                                                                                                                             case 'i':
													//                                                                                                                                                                                                                                             {
													//                                                                                                                                                                                                                                                                 int num = va_arg(args, int);
													//                                                                                                                                                                                                                                                                                     if (flag_plus && num >= 0) {
													//                                                                                                                                                                                                                                                                                                             putchar('+');
													//                                                                                                                                                                                                                                                                                                                                 } else if (flag_space && num >= 0) {
													//                                                                                                                                                                                                                                                                                                                                                         putchar(' ');
													//                                                                                                                                                                                                                                                                                                                                                                             }
													//                                                                                                                                                                                                                                                                                                                                                                                                 printf("%d", num);
													//                                                                                                                                                                                                                                                                                                                                                                                                                     break;
													//                                                                                                                                                                                                                                                                                                                                                                                                                                     }
													//                                                                                                                                                                                                                                                                                                                                                                                                                                                     case 'x':
													//                                                                                                                                                                                                                                                                                                                                                                                                                                                                     {
													//                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         unsigned int num = va_arg(args, unsigned int);
													//                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                             if (flag_hash) {
													//                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     printf("0x");
													//                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         }
													//                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                             printf("%x", num);
													//                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 break;
													//                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 }
													//                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 // Add more cases for other conversion specifiers as needed
													//
													//                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 default:
													//                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     putchar('%');
													//                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         putchar(*format);
													//                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                             break;
													//                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         }
													//                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 } else {
													//                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                             putchar(*format);
													//                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     }
													//                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                             format++;
													//                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 }
													//
													//                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     va_end(args);
													//                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     }
													//
													//                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     int main() {
													//                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         int num = 42;
													//                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                             unsigned int hex = 0xABCD;
													//
													//                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 custom_printf("Formatted output: %+d\n", num);
													//                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     custom_printf("Formatted output: % d\n", num);
													//                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         custom_printf("Formatted output: %#x\n", hex);
													//
													//                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                             return 0;
													//                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                             }
