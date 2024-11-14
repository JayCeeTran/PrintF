/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtran <jtran@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 14:37:43 by jtran             #+#    #+#             */
/*   Updated: 2024/11/13 14:37:47 by jtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ft_findbase(char *s)
{
	int	count;
	
	count = 0;
	while (*s)
	{
		count++;
		s++;
	}
	if (count != 10 && count != 16)
		return (0);
	return (count);
}

static int	print_n(unsigned int n, unsigned int divider, unsigned int base, char c)
{
	int	count;
	
	count = 0;
	while (divider > 0)
	{	
		if (n / divider <= 9)
			ft_putc(n / divider + 48, 1);
		else if (n / divider > 9 && c == 'x')
			ft_putc(n / divider - 10 + 'a', 1);
		else if (n / divider > 9 && c == 'X')
			ft_putc(n / divider - 10 + 'A', 1);
		n %= divider;
		divider /= base;
		count++;
	}
	return (count);
}

int	ft_put_us_hex(unsigned int n, char *basel, int c)
{
	unsigned int	divider;
	unsigned int	base;
	int	count;
	
	if (n == 0)
	{
		write(1, 0, 1);
		return (1);
	}
	base = ft_findbase(basel);
	if (!basel || c != 'u' && c != 'x' && c != 'X' || !base)
		return (0);
	divider = 1;
	while (n / divider >= base)
		divider *= base;
	return (count = print_n(n, divider, base, c));
}