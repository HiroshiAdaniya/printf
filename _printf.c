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
			if (*format == '\0')
				return (-1);
			if (*format == '%')
				count += write(1, "%", 1);
			else if (*format == 'c' || *format == 's' ||
			*format == 'd' || *format == 'i')
				count += handleFormatSpecifier(format, list);
			else
			{
				count = write(1, "%", 1);
				count += write(1, format, 1);
			}
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
	else if (*specifier == 'd' || *specifier == 'i')
	{
		int d = va_arg(list, int);

		if (d == 0)
			count += write(1, "0", 1);
		else
			count += itoc(d);
	}

	printf("count --- %d\n", count);
	return (count);
}
/**
 * itoc - converts an int to a char string
 * @d: an integer
 * Return: nothing / void
 */
int itoc(int d)
{
	char *buffer;
	char swop;
	unsigned int i, j, num, swap = 0;
	unsigned int count = 0;

	if (d < 0)
	{
		count = count + write(1, "-", 1);
		swap = d * -1;
	} else
		swap = d;

	i = 0;
	j = swap;
	while (j != 0)
	{
		i++;
		j = j / 10;
	}
	buffer = malloc(sizeof(char) * i);
	if (buffer == NULL)
		return (-1);

	while (swap > 0)
	{
		num = swap % 10;
		buffer[i] = num + '0';
		swap = swap / 10;
		i++;
	}
	for (j = 0; j < i / 2; j++)
	{
		swop = buffer[j];
		buffer[j] = buffer[i - j - 1];
		buffer[i - j - 1] = swop;
	}
	count += write(1, buffer, i);
	free(buffer);
	printf("count --- %d\n", count);
	return (count);
}
