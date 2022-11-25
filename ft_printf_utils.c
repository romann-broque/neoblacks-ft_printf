/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amugnier <amugnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 15:34:33 by amugnier          #+#    #+#             */
/*   Updated: 2022/11/25 16:29:33 by amugnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '\0')
	{
		write(1, "(null)", 6); //???
		return (6);
	}
	i = ft_strlen(str);
	write(1, str, i);
	return (i);
}

int	ft_putnbr(int nbr)
{
	char	*str;
	int		len;

	str = ft_itoa(nbr);
	len = ft_putstr(str);
	free(str);
	return (len);
}

int	ft_putnbr_u(unsigned int nbr)
{
	char	*str;
	int		len;

	str = ft_uitoa(nbr);
	len = ft_putstr(str);
	free(str);
	return (len);
}
