/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtran <jtran@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 15:31:23 by jtran             #+#    #+#             */
/*   Updated: 2024/11/06 14:18:58 by jtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char *savec(int c)
{
	char	*dest;

	if (c == 0)
	{
		dest = ft_calloc(1, 1);
		if(!dest)
			return(NULL);
		return(dest);
	}
	dest = malloc(2);
	if (!dest)
		return (NULL);
	dest[0] = c;
	dest[1] = '\0';
	return (dest);
}
