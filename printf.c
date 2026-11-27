#include "main.h"

/**
 * _printf - produces output according to a format
 * @format: character string made of zero or more directives
 * @...: the values to print, one for each conversion specifier
 *
 * Return: the number of characters printed, excluding the null byte
 */
int _printf(const char *format, ...)
{
	va_list list;
	int counter = 0;
	int position = 0;

	if (format == NULL)
    {
		return (-1);
    }
	va_start(list, format);
	while (format[position] != '\0')
	{
		if (format[position] != '%')
			counter += _putchar(format[position]);
		else
		{
			position++;
			if (format[position] == '\0')
			{
				va_end(list);
				return (-1);
			}
			if (format[position] == 'c')
				counter += _putchar(va_arg(list, int));
			else if (format[position] == 's')
				counter += print_string(va_arg(list, char *));
			else if (format[position] == '%')
				counter += _putchar('%');
			else
			{
				counter += _putchar('%');
				counter += _putchar(format[position]);
			}
		}
		position++;
	}
	va_end(list);
	return (counter);
}
