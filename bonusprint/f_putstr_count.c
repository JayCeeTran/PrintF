#include "ft_printf.h"

int	f_putstr_count(const char *s, int ciszero, int left)
{
	int	i;

	i = 0;
	if (ciszero && left)
		write(1, &s[i++], 1);
	while(s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	if (ciszero && !left)
		write(1, &s[i], 1);
	return (i);
}
