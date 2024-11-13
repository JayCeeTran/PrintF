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

void	ft_put_hex_l(unsigned int n, char *basel)
{
	uint64_t	divider;
	uint64_t	base;
	
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
