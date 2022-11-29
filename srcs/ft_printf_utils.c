/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amugnier <amugnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 15:34:33 by amugnier          #+#    #+#             */
/*   Updated: 2022/11/29 15:15:48 by amugnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

// function to print a char
int	ft_putcharacter(int fd, char c)
{
	write(fd, &c, 1);
	return (1);
}

// function to print a string
int	ft_putstring(int fd, char *str)
{
	int	i;

	i = 0;
	if (str[i] == '\0')
		return(write(fd, "\0", 1));
	i = ft_strlen(str);
	write(fd, str, i);
	return (i);
}

// function to print a number
int	ft_putnbr_i(int fd, int nbr)
{
	char	*str;
	int		len;

	str = ft_itoa(nbr);
	len = ft_putstring(fd,str);
	free(str);
	return (len);
}

// function to print a unsigned number
int	ft_putnbr_u(int fd, unsigned int nbr)
{
	char	*str;
	int		len;

	str = ft_uitoa(nbr);
	len = ft_putstring(fd, str);
	free(str);
	return (len);
}
