# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: elindber <elindber@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/02 12:38:06 by elindber          #+#    #+#              #
#    Updated: 2020/06/08 17:11:42 by elindber         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = visual.a

SRC = main.c random_funcs.c read_output.c visualize.c 

FLAGS = -Wall -Wextra -Werror

MLXFLAGS = -lmlx -framework OpenGL -framework AppKit

LIB = ../libftprintf/

all : $(NAME)

$(NAME):
	@ gcc $(FLAGS) -o $(NAME) $(SRC) $(MLXFLAGS) -L $(LIB) -lftprintf

clean:
	@ /bin/rm -f *.o

fclean: clean
	@ /bin/rm -f $(NAME)

re : fclean all

