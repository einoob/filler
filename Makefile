# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: elindber <elindber@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/11 15:37:56 by elindber          #+#    #+#              #
#    Updated: 2020/04/02 01:29:50 by elindber         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ./players/elindber.filler

SRC = source/*.c

LIBFT = ./libftprintf/libftprintf.a

FLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME):
	@ make -C libftprintf/ fclean && make -C libftprintf/
	@ gcc $(FLAGS) -o $(NAME) $(SRC) $(LIBFT)
	@ echo "Ready to play." 
	
clean:
	@ make -C libftprintf/ clean
	@ echo "Object files cleaned."
	
fclean: clean
	@ /bin/rm -f $(NAME)
	@ /bin/rm -f filler.trace	
	@ make -C libftprintf/ fclean
	@ echo "Removed: elindber.filler."

re: fclean all
