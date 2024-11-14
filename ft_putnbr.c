/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtran <jtran@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 16:15:58 by jtran             #+#    #+#             */
/*   Updated: 2024/11/07 12:34:18 by jtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"



int	ft_putnbr(int n, int fd)
{
	int	divider;
	int	count;
	
	count = 0;
	divider = 1;
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return (11);
	}
	if (n < 0)
	{
		ft_putc('-', fd);
		n *= (-1);
		count++;
	}
	while (n / divider > 9)
		divider *= 10;
	while (divider > 0)
	{
		ft_putc(n / divider + '0', fd);
		n %= divider;
		divider /= 10;
		count++;
	}
	return (count);
}
