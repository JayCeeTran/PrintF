/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptrtest.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtran <jtran@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 16:23:46 by jtran             #+#    #+#             */
/*   Updated: 2024/11/13 16:59:02 by jtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdint.h>
#include "libft.h"

static int	ft_findbase(char *s)
{
	int	count;
	
	count = 0;
	while (*s)
	{
		count++;
		s++;
	}
	return (count);
}

static void	ft_put_hex_(unsigned long n, char *basel)
{
	unsigned long	divider;
	unsigned long	base;
	
	base = ft_findbase(basel);
	divider = 1;
	while (n / divider >= base)
		divider *= base;
	while (divider > 0)
	{	
		if (n / divider <= 9)
			ft_putchar_fd(n / divider + 48, 1);
		else if (n / divider > 9)
			ft_putchar_fd(n / divider - 10 + 'a', 1);
		n %= divider;
		divider /= base;
	}
}

void	print_add(void *ptr)
{
	unsigned long **p;
	
	
	p = (unsigned long **)&ptr;
	ft_put_hex_(*p,"0123456789abcdef");
	write(1, "\n", 1);	
	
}

int	main(void)
{
	int	x = 5;
	
	print_add(&x);
	
}
