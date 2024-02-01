#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

int _printf(const char *format, ...);

int handleFormatSpecifier(const char *specifier, va_list arg_list);
int itoc(int);
#endif
