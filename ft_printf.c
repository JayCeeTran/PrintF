/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtran <jtran@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 12:37:23 by jtran             #+#    #+#             */
/*   Updated: 2024/11/13 12:37:26 by jtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdint.h>

static int	check_symbol(const char **s, va_list args)
{	
	if (**s == 'c')
		return(ft_putc(va_arg(args, int), 1));
	else if (**s == 's')	
		return(ft_putstr_fd(va_arg(args, void *), 1));
	else if (**s == 'p')
		return(ft_put_p(va_arg(args, unsigned long long)));
	else if (**s == 'd')
		return(ft_putnbr(va_arg(args, int), 1));
	else if (**s == 'i')
		return(ft_putnbr(va_arg(args, int), 1));
	else if (**s == 'u')
		return(ft_put_us_hex(va_arg(args, unsigned int), "0123456789", 'u'));
	else if (**s == 'x')
		return(ft_put_us_hex(va_arg(args, unsigned int), "0123456789abcdef", 'x'));
	else if (**s == 'X')
		return(ft_put_us_hex(va_arg(args, unsigned int), "0123456789ABCDEF", 'X'));
	if (**s == '%')
	{
		write(1, "%", 1);
		return (1);
	}
	return(0);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int	count;

	count = 0;
	va_start(args, s);
	while (*s)
	{
		if (*s == '%')
		{	
				s++;
				count += check_symbol(&s, args);
		}
		else
		{
			write (1, &*s, 1);
			count++;
		}
		s++;
	}
	va_end(args);
	return (count);
}

/*int	main(void)
{
	ft_printf("%d\n", ft_printf("NULL %s NULL\n", NULL));
	printf("%d\n", printf("NULL %s NULL\n", NULL));

	ft_printf("%d\n", ft_printf("%s\n", "He\0llo"));
	printf("%d\n", printf("%s\n", "He\0llo"));

	ft_printf("%d\n", ft_printf("%x %X %d hello\n", -1000, -1000, -1000));
	printf("%d\n", printf("%x %X %d hello\n", -1000, -1000 , -1000));

	ft_printf("%d\n", ft_printf("%s\n", "\0"));
	printf("%d\n", printf("%s\n", "\0"));
	return (0);
}*/
