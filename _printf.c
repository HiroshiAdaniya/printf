#include "main.h"
#include <stdio.h>  // Include necessary headers
#include <stdarg.h>

/**
 * _printf - prints formatted output to stdout
 * @format: character string containing format specifiers
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
    int i = 0, j, k = 0, ch = 0;  // Initialize variables
    char *string;
    va_list list;

    va_start(list, format);  
    while (format[i] != '\0')
        i++;

    for (j = 0; j < i; j++)
    {
        if (format[j] == '%' && format[j + 1] == 'c')
        {
            string = va_arg(list, char *);
            write(1, &string, 1);
            ch++;
            j++;
        }
        else if (format[j] == '%' && format[j + 1] == 's')
        {
            k = 0;
            string = va_arg(list, char *);
            while (string != NULL && string[k] != '\0')  // Calculate length of string
                k++;
            printf("%s", string);  // Print the string using printf
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
