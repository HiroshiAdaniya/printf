#include "main.h"
/**
 * _printf - prints arguments to the stdout (1)
 * @format: character string
 * Return: number of characters printed / int
 */
int _printf(const char *format, ...)
{
	int count = 0;
	char *string;
	char c;
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
			if (*format == '\0')
				return (-1);
			if (*format == '%')
				count += write(1, "%", 1);
			else if (*format == 'c')
			{
				c = va_arg(list, int);
				count += write(1, &c, 1);
			}
			else if (*format == 's')
			{
				string = va_arg(list, char *);
				while (*string != '\0')
				{
					count += write(1, string, 1);
					string++;
				}
			}
		}
		format++;
	}
	va_end(list);
	return (count);
}

