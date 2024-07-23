// mini printf name mini_printf we use : malloc , free
// /write , and this function will manage only : 
// char c and s string and d decimal and x hex ...
// we can use Variadic function for pass the arguments
// va_start , va_arg , va_copy , va_end .
// printf prototype : int printf(const char *, ...);


#ifndef FT_MINI_PRINTF_H
#define FT_MINI_PRINTF_H
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

int print_char(int c)
{
  return write(1, &c, 1);
}
int print_str(char *str)
{
  int count;
  count  = 0;
  while(*str != '\0')
  {
    print_char((int)*str);
    ++count;
    ++str;
  }
  return count;
}

int print_digit(long n, int base)
{
  int count;
  char *symb;

  count = 0;
  symb = "0123456789abcdef";
  if (n < 0)
  {
    write(1, "-", 1);
    return print_digit(-n, base) + 1;
  }else if (n < base)
  {
    return print_char(symb[n]);
  }else
  {
    count = print_digit(n / base, base);
    return count + print_digit(n % base, base);
  }
}

int format_print(char content, va_list params)
{
  int count;
  count = 0;
  if (content == 'c')
    count += print_char(va_arg(params, int));
  else if (content == 's')
    count += print_str(va_arg(params, char *));
  else if (content == 'd')
    count += print_digit((long)va_arg(params, int), 10);
  else if (content == 'x')
    count += print_digit((long)va_arg(params, unsigned int), 16);
  else 
    count += write(1, &content, 1);
  return count;
}

int ft_mini_printf(const char *format, ...)
{
  va_list params;
  int count = 0;
  va_start(params, format);
  count  = 0;
  while (*format != '\0')
  {
    if (*format == '%')
      count += format_print(*(++format), params);
    else 
      count += write(1, format, 1);
    ++format;
  }
  va_end(params);
  return count;
}
#endif
