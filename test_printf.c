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
	char *str = "Hello";
	char *s;
	char *sstr;
	
	sstr = NULL;
	
	
//	POINTER TESTS
	
	ft_printf("%p\n", str);
	printf("%p\n", str);
	
	ft_printf("%p\n", s);
	printf("%p\n", s);
	
	ft_printf("%p\n", sstr);
	printf("%p\n", sstr);
	
	printf("%p\n", &x);
	ft_printf("%p\n", &x);
	
	
//	STRING TESTS
	
	ft_printf("%s\n", "\0");
	printf("%s\n", "\0");
	
	ft_printf("%s\n", "He\0llo");
	printf("%s\n", "He\0llo");
	
	
//	HEX && UNSIGNED TESTS

	ft_printf("%u\n", -1000);
	printf("%u\n", -1000);
	
	printf("%x\n", 1000);
	ft_printf("%x\n", 1000);
	
	printf("%X\n", -1000);
	ft_printf("%X\n", -1000);
	
	
//	EXTRA CHECKS

	printf("%%\n", 1000);
	ft_printf("%%\n", 1000);
	
	printf("%%\n");
	ft_printf("%%\n");
	
	printf("%%%%%%%%\n");
	ft_printf("%%%%%%%%\n");


//
	printf("%d\n%", 5);	// leaves % out of the string (%\n%) makes % appear in the current string 
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
	ft_printf("H%ello World\n"); // undefined
	printf("%%%\n");
	

}
