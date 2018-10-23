#***************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abytko <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/31 20:02:17 by abytko            #+#    #+#              #
#    Updated: 2018/05/03 13:05:56 by abytko           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
SRCDIR = ./src/
OBJDIR = ./obj/
INC = ./inc/
LIBDIR = ./lib
SRC = fdf.c ft_list_pushback.c ft_new_list.c ft_draw.c ft_route.c ft_key.c\
	  ft_zoom.c ft_center_and_color.c ft_move.c ft_brezenhem.c ft_mousput.c\
	  ft_usage.c ft_error.c
SRCGNL = get_next_line.c
FLAG = -Wall -Werror -Wextra
LIBFT = -L $(LIBDIR)/libft/ -lft
OBJ = $(addprefix $(OBJDIR), $(SRC:.c=.o))
OBJGNL = $(addprefix $(OBJDIR), $(SRCGNL:.c=.o))

all: $(NAME)

$(NAME):$(OBJ)
	make -C $(LIBDIR)/libft/
	gcc -c gnl/get_next_line.c -o obj/get_next_line.o
	gcc $(FLAG) -o $(NAME) $(OBJ) $(OBJGNL) -I $(INC) -I /usr/local/include/ \
		-L /usr/local/lib/ -lmlx -framework OpenGL -framework AppKit $(LIBFT)

$(OBJDIR)%.o: %.c
	gcc -c $< -o $@ $(FLAG) -I $(INC)

clean:
	rm -f $(OBJ) obj/get_next_line.o
	make clean -C $(LIBDIR)/libft

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBDIR)/libft

re: fclean all

vpath %.c $(SRCDIR)
