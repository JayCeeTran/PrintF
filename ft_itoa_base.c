#include "libft.h"

char	*ft_itoa_base(int n, char *str, int base)
{
	int	divider;
	int	i;

	divider = 1;
	i = 0;
	if (n < 0 && base == 10)
	{	
		str[i++] = '-';
		n *= (-1);
	}
	while (n / divider >= base)
		divider *= base;
	while (divider > 0)
	{	
		if (n / divider <= 9)
			str[i] = n / divider + 48;
		else if (n / divider > 9)
			str[i] = n / divider - 10 + 'a';
		n %= divider;
		divider /= base;
		i++;
	}
	str[i] = '\0';
	return (str);
}
