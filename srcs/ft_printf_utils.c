/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amugnier <amugnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 15:34:33 by amugnier          #+#    #+#             */
/*   Updated: 2022/11/28 20:04:23 by amugnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

// function to print a char
int	ft_putcharacter(char c)
{
	int	fd;

	fd = open("my_input.txt", O_WRONLY | O_APPEND);
	write(fd, &c, 1);
	return (1);
}

// function to print a string
int	ft_putstring(char *str)
{
	int	i;
	int	fd;

	fd = open("my_input.txt", O_WRONLY | O_APPEND);
	i = 0;
	if (str[i] == '\0')
	{
		write(fd, "(null)", 6);
		return (6);
	}
	i = ft_strlen(str);
	write(fd, str, i);
	return (i);
}

// function to print a number
int	ft_putnbr_i(int nbr)
{
	char	*str;
	int		len;

	str = ft_itoa(nbr);
	len = ft_putstring(str);
	free(str);
	return (len);
}

// function to print a unsigned number
int	ft_putnbr_u(unsigned int nbr)
{
	char	*str;
	int		len;

	str = ft_uitoa(nbr);
	len = ft_putstring(str);
	free(str);
	return (len);
}
