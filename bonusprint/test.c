#include "ft_printf.h"
#include <stdarg.h>

int   main(void)
{
  //ft_printf("%d\n", ft_printf("NULL %s NULL\n", NULL));
  //printf("%d\n", printf("NULL %s NULL\n", NULL));

  //ft_printf("%%\n");
  //printf("%%\n");

  ft_printf("%.1d\n", 99);
  printf("%.1d\n", 99);

  ft_printf("%.2d\n", -1);
  printf("%.2d\n", -1);

  /*ft_printf("%10c\n", '2');
  printf("%10c\n", '2');

  ft_printf("%10.5d\n", 42);
  printf("%10.5d\n", 42);

  ft_printf("%05d\n", 42);
  printf("%05d\n", 42);

  ft_printf("%5d\n", 42);                                                                                                           202     printf("%5d\n", 42);

  ft_printf("%010d\n", 42);
  printf("%010d\n", 42);*/
  return (0);
}
