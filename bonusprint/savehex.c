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

static char	*save_n(unsigned int n, unsigned int divider, unsigned int len, char c)
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
		else if (n / divider > 9 && c == 'x')
			dest[i] = n / divider - 10 + 'a';
		else if (n / divider > 9 && c == 'X')
			dest[i] = n / divider - 10 + 'A';
		n %= divider;
		divider /= 16;
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char *savehex(unsigned int n, int c)
{
	unsigned int	divider;
	int	count;
	char	*dest;
	unsigned int	base;

	count = 1;
	base = 16;
	if (n == 0)
	{
		dest = malloc(2);
		if (!dest)
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
	dest = save_n(n, divider, count, c);
	return (dest);
}

/*int	main(void)
{
		char *dest;
		char *dest2;
		char *dest3;
		char *dest4;

		dest = savehex(1000, 'x');
		dest2 = savehex(-1000, 'X');
		dest3 = savehex(0, 'x');
		dest4 = savehex(1000, 'X');

		printf("%s\n", dest);
		printf("%s\n", dest2);
		printf("%s\n", dest3);	
		printf("%s\n", dest4);
}*/

















