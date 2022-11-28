# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amugnier <amugnier@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/27 13:28:37 by amugnier          #+#    #+#              #
#    Updated: 2022/11/28 15:54:55 by amugnier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

PATH_LIB = libft/
LIBFT = $(PATH_LIB)/libft.a

FOLDER = srcs/

SRCS = ${FOLDER}ft_printf.c \
		${FOLDER}ft_printf_utils.c \
		${FOLDER}ft_put_pointer.c \

OBJS = $(SRCS:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

all: $(LIBFT) $(NAME)

$(NAME): $(OBJS)
	cp $(LIBFT) $(NAME)
	ar rc $(NAME) $(OBJS)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(LIBFT):
	$(MAKE) -C $(PATH_LIB)

clean:
	$(MAKE) -C $(PATH_LIB) clean
	$(RM) $(OBJS)

fclean: clean
	$(MAKE) -C $(PATH_LIB) fclean
	$(RM) $(NAME)

re: fclean
	$(MAKE) -C $(PATH_LIB) re
	$(MAKE)

.PHONY: all clean fclean re
