/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtran <jtran@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 16:06:27 by jtran             #+#    #+#             */
/*   Updated: 2024/11/06 14:17:55 by jtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *s, int fd)
{
	int	count;
	char *c;

	c = (char *) s;
	if (s == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	count = 0;
	while (*s)
	{
		write(fd, s, 1);
		s++;
		count++;
	}
	return (count);
}
