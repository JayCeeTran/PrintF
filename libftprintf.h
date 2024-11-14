#ifndef	LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <limits.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

int				ft_putc(char c, int fd);
int				ft_putendl_fd(char *s, int fd);
int				ft_put_us_hex(unsigned int n, char *basel, int c);
int				ft_put_p(unsigned long long n);
int				ft_putnbr(int n, int fd);
int				ft_putstr_fd(char *s, int fd);

#endif
