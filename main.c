/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amugnier <amugnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 15:40:24 by amugnier          #+#    #+#             */
/*   Updated: 2022/11/28 20:02:18 by amugnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

// main function to test the ft_printf function
int	main(void)
{
	int	fd;

	fd = open("test.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	//test 1 : print a string
	dprintf(fd, "Hello%s\n", "worldpatate!");
	ft_printf("Hello%s\n", "worldpatate!");
	//test 2 : print a char
	dprintf(fd, "Hello%c\n", 'a');
	ft_printf("Hello%c\n", 'a');
	//test 3 : print a number
	dprintf(fd, "Hello%d\n", -42);
	ft_printf("Hello%d\n", -42);
	//test 4 : print a unsigned number
	dprintf(fd, "Hello%u\n", 42);
	ft_printf("Hello%u\n", 42);
	//test 5 : print a hexadecimal number
	dprintf(fd, "Hello%x\n", 42);
	ft_printf("Hello%x\n", 42);
	//test 6 : print a hexadecimal number
	dprintf(fd, "Hello%X\n", 42);
	ft_printf("Hello%X\n", 42);
	//test 7 : print a percentage
	dprintf(fd, "Hello%%\n");
	ft_printf("Hello%%\n");
	//test 8 : print a pointer
	dprintf(fd, "Hello%p\n", &fd);
	ft_printf("Hello%p\n", &fd);
	//test 9 : test multiple %
	dprintf(fd, "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n");
	ft_printf("%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n");
	//test 10 : test pointer = NULL
	dprintf(fd, "%p", NULL);
	ft_printf("%p", NULL);
	//test 11 %c%%c
	dprintf(fd, "\n%c%%c\n", 'a');
	ft_printf("\n%c%%c\n", 'a');
	//test 12 \0 char
	dprintf(fd, "%c\n", '\0');
	ft_printf("%c\n", '\0');
	//test 13 random
	dprintf(fd, "Hello%sworld%cpatate%d\n", "world", 'a', 42);
	ft_printf("Hello%sworld%cpatate%d\n", "world", 'a', 42);
	//test 14 INT_MIN
	dprintf(fd, "%ld\n", -2147483648);
	ft_printf("%d\n", -2147483648);
	//test 15 INT_MAX
	dprintf(fd, "%d\n", 2147483647);
	ft_printf("%d\n", 2147483647);
	//test 16 ERROR
	dprintf(fd, "%d\n", 2147483648);
	ft_printf("%d\n", 2147483648);
	//test 17 ERROR
	dprintf(fd, "%d\n", -2147483649);
	ft_printf("%d\n", -2147483649);
	//test 18 ERROR
	dprintf(fd, "%d\n", 2147483649);
	ft_printf("%d\n", 2147483649);

	return (0);
}
