#include "main.h"
/**
 * _printf - prints arguments to the stdout (1)
 * @format: character string
 * Return: number of characters printed / int
 */
int _printf(const char *format, ...)
{
	int j, count = 0;
	char *string;
	char c;
	va_list list;

	va_start(list, format);
	for (j = 0; format != NULL && format[j] != '\0'; j++)
	{
		if (format[j] == '%' && format[j + 1] == 'c')
		{
			c = va_arg(list, int);
			if (c == 0)
				return (-1);
			write(1, &c, 1);
			j++;
			count++;
		}
		else if (format[j] == '%' && format[j + 1] == 's')
		{
			string = va_arg(list, char *);
			if (string == NULL)
				return (NULL);
			while (*string != '\0')
			{
				write(1, string, 1);
				count++;
				string++;
			}
			j++;
		}
		else if (format[j] == '%' && format[j + 1] == '%')
		{
			write(1, "%", 1);
			j++;
			count++;
		}
		else
		{
			write(1, &format[j], 1);
			count++;
		}
	}
	va_end(list);
	return (count);
}
