/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amugnier <amugnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 15:20:24 by amugnier          #+#    #+#             */
/*   Updated: 2022/11/27 13:34:58 by amugnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_printf_args(const char *format, int i, va_list ap)
{
	if (format[i + 1] == '%')
		return (ft_putcharacter(format[i + 1]));
	else if (format[i + 1] == 'c')
		return (ft_putcharacter(va_arg(ap, int)));
	else if (format[i + 1] == 's')
		return (ft_putstring(va_arg(ap, char *)));
	else if (format[i + 1] == 'd' || format[i + 1] == 'i')
		return (ft_putnbr_i(va_arg(ap, int)));
	else if (format[i + 1] == 'u')
		return (ft_putnbr_u(va_arg(ap, unsigned int)));
	else if (format[i + 1] == 'x' || format[i + 1] == 'X')
	{
		if (format[i + 1] == 'X')
			return (ft_put_hex(va_arg(ap, unsigned int), "0123456789ABCDEF"));
		else
			return (ft_put_hex(va_arg(ap, unsigned int), "0123456789abcdef"));
	}
	else if (format[i + 1] == 'p')
		return (ft_putstring("0x") + ft_put_pointer(va_arg(ap, void *), \
		"0123456789abcdef"));
	else
		return (0);
}

int ft_printf(const char *format, ...)
{
	va_list ap;
	int		i;
	int		ret;

	i = 0;
	ret = 0;
	va_start(ap, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			ret = ft_printf_args(&format[i + 1], i, ap);
			i++;
		}
		else
			ret = ft_putcharacter(format[i]);
		i++;
	}
	va_end(ap);
	return (ret);
}
