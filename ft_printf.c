#include <stdio.h>
#include <stdarg.h>
#include "libft.h"


void    check_symbol(const char *s, va_list args)
{
    switch (*s) {
    case 'c':
        ft_putchar_fd(va_arg(args, int), 1);
        break;
    case 's':
        ft_putstr_fd(va_arg(args, char*), 1);
        break;
    case 'p':
        ft_putchar_fd(va_arg(args, int), 1);
        break;
    case 'd':
        ft_putnbr_fd(va_arg(args, int), 1);
        break;
    case 'i':
        ft_putnbr_fd(va_arg(args, int), 1);
        break;
        /*case 'u':
        return ('u');
    case 'x':
        return ('x');
    case 'X':
        return ('X');
    case '%':
        return ('%');*/
    }
}

int ft_printf(const char *s, ...)
{
    va_list args;
    va_start (args, s);

    while (*s)
    {
        if (*s == '%')
        {
            check_symbol(s + 1, args);
        }
        s++;
    }

    va_end (args);
    return (0);
}

int main()
{
    ft_printf("%d\n", 1000);
    return 0;
}
