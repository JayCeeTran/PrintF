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
	
	ft_printf("%d\n", ft_printf("%p\n", str));
	printf("%d\n", printf("%p\n", str));

	ft_printf("%d\n", ft_printf("%p\n", s));
	printf("%d\n", printf("%p\n", s));

	ft_printf("%d\n", ft_printf("%p\n", sstr));
	printf("%d\n", printf("%p\n", sstr));

	ft_printf("%d\n", ft_printf("%p\n", &x));
	printf("%d\n", printf("%p\n", &x));

	ft_printf("%p\n", str);
	printf("%p\n", str);
	
	ft_printf("%p\n", s);
	printf("%p\n", s);
	
	ft_printf("%p\n", sstr);
	printf("%p\n", sstr);
	
	printf("%p\n", &x);
	ft_printf("%p\n", &x);
	
	
//	STRING TESTS
	
	ft_printf("%d\n", ft_printf("%s\n", "\0"));
	printf("%d\n", printf("%s\n", "\0"));

	ft_printf("%d\n", ft_printf("%s\n", "He\0llo"));
	printf("%d\n", printf("%s\n", "He\0llo"));

	ft_printf("%s\n", "He\0llo");
	printf("%s\n", "He\0llo");
	
	ft_printf("%d\n", ft_printf("\1234\n"));
	printf("%d\n", printf("\1234\n"));

//	HEX && UNSIGNED TESTS

	ft_printf("%d\n", ft_printf("%d\n", 99999999999));
	printf("%d\n", printf("%d\n", 99999999999));

	ft_printf("%d\n", ft_printf("%x\n", 10000000 100));
	printf("%d\n", printf("%x\n", 1000000 100));

	ft_printf("%u\n", -1000);
	printf("%u\n", -1000);
	
	printf("%x\n", 1000);
	ft_printf("%x\n", 1000);
	
	printf("%X\n", -1000);
	ft_printf("%X\n", -1000);
	
	
//	EXTRA CHECKS

	ft_printf("%d\n", ft_printf("hello\n"));
	printf("%d\n", printf("hello\n"));
	
	ft_printf("%d\n", ft_printf("%x hello\n", 1000));
	printf("%d\n", printf("%x hello\n", 1000));

	ft_printf("%d\n", ft_printf("%x %X %d hello\n", -1000, -1000, -1000));
	printf("%d\n", printf("%x %X %d hello\n", -1000, -1000, -1000));


//
	printf("%d\n%", 5);	// leaves % out of the string (%\n%) makes % appear in the current string 
	printf("%x\n", -1000); // prints negative value of unsigned int
	printf("%X\n", 1000);
	
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
