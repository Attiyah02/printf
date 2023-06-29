#include <stdio.h>
#include <stdarg.h>

void print_binary(unsigned int num) {
	    if (num > 1) {
		            print_binary(num / 2);
			        }
	        printf("%d", num % 2);
}

void custom_printf(const char* format, ...) {
	    va_list args;
	        va_start(args, format);

		    while (*format) {
			            if (*format == '%') {
					                format++;
							            if (*format == 'b') {
									                    unsigned int num = va_arg(args, unsigned int);
											                    print_binary(num);
													                } else {
																                putchar(*format);
																		            }
								            } else {
										                putchar(*format);
												        }
				            format++;
					        }

		        va_end(args);
}

int main() {
	    unsigned int num = 42;
	        custom_printf("Binary representation of %u is %b\n", num, num);
		    return 0;
}

