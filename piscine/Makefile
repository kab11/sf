# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cfranco <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/29 15:01:46 by cfranco           #+#    #+#              #
#    Updated: 2018/01/29 15:01:54 by cfranco          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bsq

SOURCE = bsq.c \
		ft_putchar.c \
		ft_putstr.c \
		ft_strlen.c \
		ft_strlcat.c \
		read.c

all: $(NAME)

$(NAME):
	gcc -Wall -Werror -Wextra -o $(NAME) $(SOURCE)

clean:
	rm -rf

fclean:
	rm -rf $(NAME)

re: fclean all