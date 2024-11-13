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

#include "libft.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdint.h>
void	check_symbol(const char *s, va_list args)
{
	if (*s == 'c')
		ft_putchar_fd(va_arg(args, int), 1);
	else if (*s == 's')
		ft_putstr_fd(va_arg(args, char *), 1);
	else if (*s == 'p')
		ft_put_p(va_arg(args, uint64_t), "0123456789abcdef");
	else if (*s == 'd')
		ft_putnbr_fd(va_arg(args, int), 1);
	else if (*s == 'i')
		ft_putnbr_fd(va_arg(args, int), 1);
	else if (*s == 'u')
		ft_putnbr_unsig(va_arg(args, unsigned int), 1);
	else if (*s == 'x')
		ft_put_hex_l(va_arg(args, unsigned int), "0123456789abcdef");
	else if (*s == 'X')
		ft_put_hex_u(va_arg(args, unsigned int), "0123456789ABCDEF");
	else if (*s == '%')
	{	
		check_symbol(s + 1, args);
		write (1, "%", 1);
	}
}
void	check_white(const char *s)
{
	if (*s == 'n')
		ft_putchar_fd('\n', 1);
	else if (*s == 't')
		ft_putchar_fd('\t', 1);
	else if (*s == 'v')
		ft_putchar_fd('\v', 1);
	else if (*s == 'r')
		ft_putchar_fd('\r', 1);
	else if (*s == 'b')
		ft_putchar_fd('\b', 1);
	else if (*s == '"')
		ft_putchar_fd('"', 1);
	else if (*s == '\0')
		ft_putchar_fd('\0', 1);
	else if (*s == '?')
		ft_putchar_fd('?', 1);
	else if (*s == ''')
		write (1, ''', 1);
	}
}

int	ft_printf(const char *s, ...)
{
	va_list	args;

	va_start(args, s);
	while (*s)
	{
		if (*s == '%' || *s == '\')
		{
			s++;
			if (*s - 1 == '%')
				check_symbol(s, args);
			else
				check_white(s);
		}	
		else
			write (1, &*s, 1);
		s++;
	}
	va_end(args);
	return (0);
}

int	main(void)
{
	int	x = 5;
	ft_printf("aaa%d bb%s sss%x s%X %% s%u s%p", 1000, "hello", 1000, -1000, -1000, &x);
	return (0);
}
