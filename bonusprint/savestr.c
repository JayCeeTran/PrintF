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

char	*savestr(char *s)
{
	char *dest;

	if (s == NULL)
	{
		dest = ft_strdup("(null)");
		return (dest);
	}
	dest = ft_strdup(s);
	return (dest);
}
