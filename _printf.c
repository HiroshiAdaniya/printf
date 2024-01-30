#include "main.h"
/**
 * _printf - prints arguments to the stdout (1)
 * @format: character string
 * Return: number of characters printed / int
 */
int _printf(const char *format, ...)
{
	int i, j, k = 0;
	int ch = 0;
	char *string;
	va_list list;
	
	while (format[i] != '\0')
		i++;

	va_start(list, format);
	
	for (j = 0; j < i; j++)
	{
		if (format[j] == '%' && format[j + 1] == 'c')
		{
			string = va_arg(list, char *);
			write(1, &string, 1);
			j++;
			ch++;
		}
		else if (format[j] == '%' && format[j + 1] == 's')
		{
			string = va_arg(list, char *);
			while (string != NULL && string[k] != '\0')
				k++;
			write(1, string, k);
			j++;
			ch++;
		}
		else if (format[j] == '%' && format[j + 1] == '%')
		{
			write(1, "%", 1);
			j++;
		}
		else
		{
			write(1, &format[j], 1);
			ch++;
		}
		k = 0;
	}
	va_end(list);
	exit(ch);
}
