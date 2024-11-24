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

static char	*saven(unsigned long long n, unsigned long long divider, int len)
{
	char	*dest;
	int		i;

	i = 2;
	len = len + 2;
	dest = malloc(len + 1);
	if (!dest)
		return (NULL);
	dest[0] = '0';
	dest[1] = 'x';
	while (divider > 0 && i <= len)
	{	
		if (n / divider <= 9)
			dest[i] = n / divider + 48;
		else if (n / divider > 9)
			dest[i] = n / divider - 10 + 'a';
		n %= divider;
		divider /= 16;
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*putp(unsigned long long n)
{
	unsigned long long	divider;
	char	*dest;
	int		len;
	
	len = 1;
	if (n == 0)
	{
		dest = ft_strdup("(nil)");
		return (dest);
	}
	divider = 1;
	while (n / divider >= 16)
	{
		divider *= 16;
		len++;
	}
	dest = saven(n, divider, len);
	return (dest);
}
/*int	main(void)
{
	char *dest;
	char *dest1;
	char *dest2;
	char *dest3;

	dest = putp(1000);
	dest1 = putp(-1000);
	dest2 = NULL;
	dest3 = putp(5000);

	printf("%s\n", dest);
	printf("%s\n", dest1);
	
	printf("%s\n", dest3);

	printf("%p\n", dest);
	printf("%p\n", dest1);
	printf("%p\n", dest2);
	printf("%p\n", dest3);
}*/
