#include "main.h"
/**
 * _printf - prints arguments to the stdout (1)
 * @format: character string
 * Return: number of characters printed / int
 */
int _printf(const char *format, ...)
{
	int count = 0;
	va_list list;

	va_start(list, format);
	if (format == NULL)
		return (-1);
	while (*format != '\0')
	{
		if (*format != '%')
		{
			count += write(1, format, 1);
		}
		else
		{
			format++;
			if (*format == '%')
				count += write(1, "%", 1);
			else if (*format == 'c' || *format == 's')
				count += handleFormatSpecifier(format, list);
			else
				return (-1);
		}
		format++;
	}
	va_end(list);
	return (count);
}


/**
 * handleFormatSpecifier - handles the format
 * @specifier: pointer to specifier character
 * @list: va_list
 *
 * Return: number of characters written
 */
int handleFormatSpecifier(const char *specifier, va_list list)
{
	int count = 0;

	if (*specifier == 'c')
	{
		char c = va_arg(list, int);

		count += write(1, &c, 1);
	}
	else if (*specifier == 's')
	{
		char *string = va_arg(list, char *);

		if (string == NULL)
			string = "(null)";

		while (*string != '\0')
		{
			count += write(1, string, 1);
			string++;
		}
	}
	return (count);
}














