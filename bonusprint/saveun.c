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

static char	*save_n(unsigned int n, unsigned int divider, unsigned int len)
{
	char *dest;
	unsigned int	i;

	i = 0;
	dest = malloc (len + 1);
	if (!dest)
		return (NULL);
	while (divider > 0 && i <= len)
	{	
		if (n / divider <= 9)
			dest[i] = n / divider + 48;
		n %= divider;
		divider /= 10;
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char *saveun(unsigned int n)
{
	unsigned int	divider;
	int	count;
	char	*dest;
	unsigned int	base;
	
	count = 1;
	base = 10;
	if (n == 0)
	{
		dest = malloc(2);
		if(!dest)
			return (NULL);
		dest[0] = '0';
		dest[1] = '\0';
		return (dest);
	}
	divider = 1;
	while (n / divider >= base)
	{
		divider *= base;
		count++;
	}
	dest = save_n(n, divider, count);
	return (dest);
}

/*int	main(void)
{
		char *dest;
		char *dest2;
		char *dest3;
		char *dest4;

		dest = saveun(1000);
		dest2 = saveun(-1000);
		dest3 = saveun(0);
		dest4 = saveun(100094949);

		printf("%s\n", dest);
		printf("%s\n", dest2);
		printf("%s\n", dest3);	
		printf("%s\n", dest4);


		printf("%u\n", 1000);
		printf("%u\n", -1000);
		printf("%u\n", 0);	
		printf("%u\n", 100094949);}
}*/
