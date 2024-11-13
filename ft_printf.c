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
	switch (*s)
	{
	case 'c':
		ft_putchar_fd(va_arg(args, int), 1);
		break ;
	case 's':
		ft_putstr_fd(va_arg(args, char *), 1);
		break ;
	case 'p':
		ft_put_p(va_arg(args, uint64_t), "0123456789abcdef");
		break ;
	case 'd':
		ft_putnbr_fd(va_arg(args, int), 1);
		break ;
	case 'i':
		ft_putnbr_fd(va_arg(args, int), 1);
		break ;
	case 'u':
		ft_putnbr_unsig(va_arg(args, unsigned int), 1);
		break;
	case 'x':
		ft_put_hex_l(va_arg(args, unsigned int), "0123456789abcdef");
		break;
	case 'X':
		ft_put_hex_u(va_arg(args, unsigned int), "0123456789ABCDEF");
		break;
	case '%':
		write (1, "%", 1);
		break;
	}
}

int	ft_printf(const char *s, ...)
{
	va_list	args;

	va_start(args, s);
	while (*s)
	{
		if (*s == '%')
		{
			s++;
			check_symbol(s++, args);
			if (!*s)
				break ;
		}
		write (1, &*s++, 1);
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
