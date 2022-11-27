# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amugnier <amugnier@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/27 13:28:37 by amugnier          #+#    #+#              #
#    Updated: 2022/11/27 13:34:32 by amugnier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

FOLDER = srcs/

SRCS = ${FOLDER}ft_printf.c \
		${FOLDER}ft_printf_utils.c \
		${FOLDER}ft_put_pointer.c \

OBJS = $(SRCS:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
