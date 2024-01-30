#include "main.h"
/**
 * _printf - prints arguments to the stdout (1)
 * @format: character string
 * Return: number of characters printed / int
 */
int _printf(const char *format, ...)
{
	int j = 0;
	int count = 0;
	char *string;
	va_list list;

	va_start(list, format);
	for (j = 0; format != NULL && format[j] != '\0'; j++)
	{
		if (format[j] == '%' && format[j + 1] == 'c')
		{
			string = va_arg(list, char *);
			write(1, string, 1);
			j++;
			count++;
		}
		else if (format[j] == '%' && format[j + 1] == 's')
		{
			string = va_arg(list, char *);
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
