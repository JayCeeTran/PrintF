#ifndef	LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <limits.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "libc/libft.h"
 int     f_putstr_count(const char *s, int ciszero, int left);
 int     f_putch(const char *c);
 char    *savehex(unsigned int n, int c);
 char    *saveun(unsigned int n);
 char    *putp(unsigned long long n);
 char    *savestr(char *s);
 char    *savec(int c);
 int     ft_printf(const char *s, ...);

// FLAG FUNCTIONS
 typedef struct{
      int left;
      int zero;
      int width;
      int dot;
      int ldot;
      char *arg;
      char type;
 } flags;

int	countflags(flags *flag);
char *cutstring(char *s, int width);
char *addspace(char *s, int width, int left, int type);
char *addzeros(char *s, int ldot, int type);
char *addzero(char *s, int ldot);


#endif
