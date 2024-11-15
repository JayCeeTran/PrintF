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

#include "ft_printf.h"

int	ft_put_p(unsigned long long n)
{
	unsigned long long	divider;
	int	count;
	
	count = 0;
	if (n == 0)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	divider = 1;
	while (n / divider >= 16)
		divider *= 16;
	write (1, "0x", 2);
	count+= 2;
	while (divider > 0)
	{	
		if (n / divider <= 9)
			ft_putc(n / divider + 48, 1);
		else if (n / divider > 9)
			ft_putc(n / divider - 10 + 'a', 1);
		n %= divider;
		divider /= 16;
		count++;
	}
	return (count);
}
