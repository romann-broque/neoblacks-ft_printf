/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_pointer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amugnier <amugnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 16:16:52 by amugnier          #+#    #+#             */
/*   Updated: 2022/11/28 18:43:45 by amugnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

// Function to convert a number an hexadecimal
int	ft_hexabase(unsigned long nbr)
{
	int	i;

	i = 0;
	if (nbr == 0)
		return (1);
	while (nbr > 0)
	{
		nbr = nbr / 16;
		i++;
	}
	return (i);
}

// Function to convert a number an hexadecimal to string
char	*ft_hextostr(unsigned long nbr, char *base)
{
	int		size;
	char	*hex;

	size = ft_hexabase(nbr);
	hex = (char *)malloc(sizeof(char) * (size + 1));
	if (!hex)
		return (NULL);
	hex[size] = '\0';
	while (size > 0)
	{
		hex[size - 1] = base[nbr % 16];
		nbr = nbr / 16;
		size--;
	}
	return (hex);
}

// Function to print a pointer
int	ft_put_pointer(void *nbr, char *base)
{
	int				lenght;
	int				fd;
	char			*str;
	unsigned long	n;

	fd = open("my_input.txt", O_WRONLY | O_APPEND);
	if (!nbr)
	{
		write(fd, "(nil)", 5);
		return (5);
	}
	else
	{
		n = (unsigned long)nbr;
		str = ft_hextostr(n, base);
		write(fd, "0x", 2);
		lenght = ft_strlen(str);
		write(fd, str, lenght);
		free(str);
		return (lenght + 2);
	}
}

// Function to print a pointer
int	ft_put_hex(unsigned int nbr, char *base)
{
	char	*str;
	int		lenght;

	str = ft_hextostr(nbr, base);
	lenght = ft_putstring(str);
	free(str);
	return (lenght);
}
