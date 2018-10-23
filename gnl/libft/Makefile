# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abytko <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/17 13:07:40 by abytko            #+#    #+#              #
#    Updated: 2017/12/27 17:00:17 by abytko           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRC = *.c
OBJECT = *.o
FLAG = -Wall -Werror -Wextra
H = ./includes

all: $(NAME)

$(NAME):
	gcc -c $(FLAG) $(SRC) -I$(H)
	ar rc $(NAME) $(OBJECT)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all
