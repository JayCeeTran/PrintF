/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtran <jtran@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 12:37:23 by jtran             #+#    #+#             */
/*   Updated: 2024/11/13 12:37:26 by jtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

static char	*check_symbol(const char **s, va_list args, flags *flag)
{ 
	if (**s == 'c')
	{
		flag->type = 'c';
		return(savec(va_arg(args, int)));
	}
	else if (**s == 's')
	{
		flag->type = 's';
		return(savestr(va_arg(args, void *)));
	}
	else if (**s == 'p')
		return(putp(va_arg(args, unsigned long long)));
	else if (**s == 'i' || **s == 'd')
	{
		flag->type = 'd';
		return(ft_itoa(va_arg(args, int)));
	}
	else if (**s == 'u')
		return(saveun(va_arg(args, unsigned int)));
	else if (**s == 'x')
		return(savehex(va_arg(args, unsigned int), 'x'));
	else if (**s == 'X')
		return(savehex(va_arg(args, unsigned int), 'X'));
	else if (**s == '%')
		write(1, "%", 1);
	return(NULL);
}

static void	movethrunums(const char **s)
{	
	while(**s >= '0' && **s <= '9')
		(*s)++;
}

static flags	check_flags(const char **s, flags flag)
{
	if(**s == '-')
	{
		flag.left = 1;
		(*s)++;
	}
	if(**s == '0')
	{
		flag.zero = 1;
		if(*(*s - 1) == '-')		
			flag.zero = 0;
		(*s)++;
	}
	flag.width = ft_atoi(*s);
	if (flag.width > 0)
		movethrunums(s);
	if(**s == '.')
	{
		flag.dot = 1;
		flag.zero = 0;
		(*s)++;
	}
	flag.ldot = ft_atoi(*s);
	movethrunums(s);
	return (flag);
}

/*static char *addzeros(char *s, int ldot)
{
	int	i;
	char *dest;
	char	*temp;

	i = ldot - ft_strlen(s);
	dest = malloc(i + 1);
	if(!dest)
		return (NULL);
	dest[i] = '\0';
	while(--i >= 0)
		dest[i] = '0';
	temp = ft_strjoin(dest, s);
	free(dest);
	return(temp);
}*/

/*static char *addspace(char *s, int width, int left)
{
	char *dest;
	int	i;

	i = 0;
	dest = malloc(width + 1);
	if(!dest)
		return(NULL);
	while(i < width)
		dest[i++] = ' ';
	dest[i] = '\0';
	if(left == 0)
		ft_memmove(dest + (width - (int)ft_strlen(s)), s, ft_strlen(s));
	else if (left == 1)
		ft_memmove(dest, s, ft_strlen(s));
	return (dest);
}*/

/*static char *cutstring(char *s, int width)
{
	char *temp;

	temp = ft_strdup(s);
	temp[width] = '\0';
	free(s);
	return (temp);
}

static int	countflags(flags *flag)
{
	int	slen;
	int	i;
	
	if(!flag->arg)
		return(1);
	slen = (int)ft_strlen(flag->arg);
	if(flag->ldot > slen && flag->dot && flag->type != 's')	
		flag->arg = addzeros(flag->arg, flag->ldot);
	else if(flag->ldot < slen && flag->ldot)
		flag->arg = cutstring(flag->arg, flag->ldot);
	if(flag->width > (int)ft_strlen(flag->arg))
	{	
		if(flag->type != 's' && flag->zero)
			flag->arg = addzeros(flag->arg, flag->width);
		else
			flag->arg = addspace(flag->arg, flag->width, flag->left);
	}
	if (flag->type == 'c')
		i = f_putch(flag->arg);
	else
		i = f_putstr_count(flag->arg);
	free(flag->arg);
	return(i);
}*/

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int	count;
	flags flag;

	ft_memset(&flag, 0, sizeof(flags));
	count = 0;
	va_start(args, s);
	while (*s)
	{
		if (*s == '%')
		{	
			s++;
			flag = check_flags(&s, flag);
			flag.arg = check_symbol(&s, args, &flag);
			count += countflags(&flag);
		}
		else
		{
			write (1, &*s, 1);
			count++;
		}
		s++;
	}
	va_end(args);
	return (count);
}

//int	main(void)
//{
	//ft_printf("%d\n", ft_printf("NULL %s NULL\n", NULL));
	//printf("%d\n", printf("NULL %s NULL\n", NULL));

	//ft_printf("%%\n");
	//printf("%%\n");

//	ft_printf("flen is %d\n", ft_printf("%-2ca\n", 0));
//	printf("len is %d\n", printf("%-2cb\n", 0));

	
	/*ft_printf("%10c\n", '2');
	printf("%10c\n", '2');

	ft_printf("%10.5d\n", 42);	
	printf("%10.5d\n", 42);

	ft_printf("%05d\n", 42);
	printf("%05d\n", 42);

	ft_printf("%5d\n", 42);
	printf("%5d\n", 42);

	ft_printf("%010d\n", 42);
	printf("%010d\n", 42);*/
//	return (0);
//}
