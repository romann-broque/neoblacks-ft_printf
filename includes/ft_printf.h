/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amugnier <amugnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 15:35:05 by amugnier          #+#    #+#             */
/*   Updated: 2022/11/27 13:26:28 by amugnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include <stddef.h>
# include <stdlib.h>
# include "libft.h"

int		ft_putcharacter(char c);
int		ft_putstring(char *str);
int		ft_putnbr_i(int nbr);
int		ft_putnbr_u(unsigned int nbr);
int		ft_printf_args(const char *format, int i, va_list ap);
int		ft_hexabase(unsigned long nbr);
char	*ft_hextostr(unsigned long nbr, char *base);
int		ft_put_pointer(void *nbr, char *base);
int		ft_put_hex(unsigned int nbr, char *base);

#endif
