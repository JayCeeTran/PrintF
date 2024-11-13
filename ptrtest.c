/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptrtest.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtran <jtran@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 16:23:46 by jtran             #+#    #+#             */
/*   Updated: 2024/11/13 16:59:02 by jtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdint.h>
#include "libft.h"

/*void	print_add(void *ptr)
{
	
	ft_put_hex_l(ptr,"0123456789abcdef");
	write(1, "\n", 1);	
	
}*/

int	main(void)
{
	int	x = 5;
	
	printf("%p\n",&x );
	ft_put_p((uint64_t)&x ,"0123456789abcdef");
}
