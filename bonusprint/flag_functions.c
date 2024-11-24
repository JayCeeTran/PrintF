
#include "ft_printf.h"

int	minuslenford(char *s, int type)
{
	if(!s)
		return(0);
	if(type == 'd')
	{
		while(*s)
		{
			if(*s == '-')
				return(1);
			s++;
		}
	}
	return(0);
}
char *addzero(char *s, int ldot)
{
    int i;
    char *dest;
    char    *temp;

    i = ldot - ft_strlen(s);
    dest = malloc(i + 1);
    if(!dest)
        return (NULL);
    dest[i] = '\0';
    while(--i >= 0)
        dest[i] = '0';
    temp = ft_strjoin(dest, s);
    free(dest);
	free(s);
    return(temp);
}

char *addzeros(char *s, int ldot, int type)
{
    int i;
    char *dest;
    char    *temp;

    i = ldot - ft_strlen(s);
	if(minuslenford(s, type))
		i++;
    dest = malloc(i + 1);
    if(!dest)
        return (NULL);
    dest[i] = '\0';
    while(--i >= 0)
        dest[i] = '0';
    temp = ft_strjoin(dest, s);
    free(dest);
	free(s);
    return(temp);
}

char *addspace(char *s, int width, int left, int type)
{
    char *dest;
    int i;
	int len;

	len = (int)ft_strlen(s);
    i = 0;
    dest = malloc(width + 1);
    if(!dest)
        return(NULL);
    while(i < width)
        dest[i++] = ' ';
    dest[i] = '\0';
    if(left == 0)
	{
		if(*s == '\0' && type == 'c')
			dest[i - 1] = '\0';
		else
			ft_memcpy(dest + (width - len), s, len);
	}
    else if (left == 1)
	{
		if(*s == '\0' && type == 'c')
			dest[0] = '\0';
		else
			ft_memmove(dest, s, ft_strlen(s));
	}
	free(s);
    return (dest);
}

char *cutstring(char *s, int width)
{
    char *temp;

    temp = ft_strdup(s);
    temp[width] = '\0';
    free(s);
    return (temp);
}

void	swapminus(char *s)
{
	int	temp;
	int		i;

	i = 0;
	while(s[i] != '-' && s[i] != '\0')
		i++;
	if (s[i] == '-')
	{
		temp = s[i];
		s[i] = s[0];
		s[0] = temp;
	}
}

int  countflags(flags *flag)
{
    int slen;
    int i;
	int	ciszero;

	ciszero = 0;
	slen = (int)ft_strlen(flag->arg);
	slen -= minuslenford(flag->arg, flag->type);
//	printf("slen %d, s is %s, width is %d\n", slen, flag->arg, flag->ldot);
	if(!flag->arg)
		return(1);
	if(*flag->arg == '\0' && flag->type == 'c')
		ciszero = 1;
    if(flag->ldot > slen && flag->dot && flag->type != 's' && flag->type != 'c')
        flag->arg = addzeros(flag->arg, flag->ldot, flag->type);
    else if(flag->ldot < slen && flag->dot && flag->type == 's')
        flag->arg = cutstring(flag->arg, flag->ldot);
    if(flag->width > (int)ft_strlen(flag->arg))
    {
        if(flag->type != 's' && flag->zero && flag->type != 'c')
            flag->arg = addzero(flag->arg, flag->width);
        else 
            flag->arg = addspace(flag->arg, flag->width, flag->left, flag->type);
    }
	if(flag->type == 'd')
		swapminus(flag->arg);
    if (flag->type == 'c' && ft_strlen(flag->arg) < 2 && !flag->left)
        i = f_putch(flag->arg);
    else
        i = f_putstr_count(flag->arg, ciszero, flag->left);
    free(flag->arg);
    return(i);
}
