# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: elindber <elindber@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/11 15:37:56 by elindber          #+#    #+#              #
#    Updated: 2020/06/08 16:10:19 by elindber         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = elindber.filler

SRC =	source/main.c source/most_enemy.c source/place_piece_prior_y.c \
		source/piece_placement.c source/more_info.c source/parse_info.c \
		source/contact_counts.c

LIBFT = ./libftprintf/libftprintf.a

FLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME):
	@ make -C libftprintf/ re
	@ gcc $(FLAGS) -o $(NAME) $(SRC) $(LIBFT)
	@ make -C visualizer/ re
	@ echo "Ready to play." 
	
clean:
	@ make -C libftprintf/ clean
	@ echo "Object files cleaned."
	
fclean: clean
	@ /bin/rm -f $(NAME)
	@ /bin/rm -f filler.trace	
	@ make -C libftprintf/ fclean
	@ make -C visualizer fclean
	@ echo "Removed: elindber.filler and filler.trace"

re: fclean all
