/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_printf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtran <jtran@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 12:55:29 by jtran             #+#    #+#             */
/*   Updated: 2024/11/13 13:02:27 by jtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	main(void)
{
	int x = 5;
	printf("H%ello World\n"); // undefined
	printf("%d\n%", 5);	// leaves % out of the string (%\n%) makes % appear in the current string 
	printf("test previous\n");
	printf("%s\n", "\0");
	printf("%s\n", "He\0llo");
	printf("%x\n", -1000); // prints negative value of unsigned int
	printf("%X\n", 1000);
	printf("%p\n", &x); 	// prints out address of variable
	printf("%%\n", 1000); // prints out %
	printf("%u\n", 1000);
	printf("%u\n", -1000);
	printf("%s\n", "\0");
	printf("%s\n", "\0");
	printf("%s\n", "\0");
	printf("%s\n", "\0");
	printf("%s\n", "\0");
	printf("%s", "\0");
	

}
