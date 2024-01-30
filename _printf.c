#include "main.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * _printf - prints formatted output to stdout
 * @format: character string containing format specifiers
 * Return: number of characters printed (excluding the null byte)
 */
int _printf(const char *format, ...)
{
    int j, k = 0, ch = 0;
    char *string;
    va_list list;

    va_start(list, format);

    for (j = 0; format[j] != '\0'; j++)
    {
        if (format[j] == '%' && format[j + 1] == 'c')
        {
            string = va_arg(list, char *);
            write(1, &string, 1);
            ch++;
            j++;
        }
        else if (format[j] == '%' && format[j + 1] == 's')  // Handle %s specifier
        {
            k = 0;
            string = va_arg(list, char *);
            while (string != NULL && string[k] != '\0')
                k++;
            write(1, string, k);
            ch += k;
            j++;
        }
        else if (format[j] == '%' && format[j + 1] == '%')
        {
            write(1, "%", 1);
            ch++;
            j++;
        }
        else
        {
            write(1, &format[j], 1);
            ch++;
        }
    }

    va_end(list);

    return ch;
}
