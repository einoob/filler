/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elindber <elindber@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 13:26:42 by elindber          #+#    #+#             */
/*   Updated: 2020/03/19 14:18:38 by elindber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include <unistd.h>
# include <stdlib.h>
# include "../libftprintf/includes/ft_printf.h"
# include "../libftprintf/includes/get_next_line.h"
# include "../libftprintf/libft/libft.h"

# define UPLEFT 1
# define UPRIGHT 2
# define DOWNRIGHT 3
# define DOWNLEFT 4

typedef struct s_piece
{
	char		**piece;
	int			height;
	int			width;
	int			first_x;;
	int			last_x;
	int			first_y;
	int			last_y;
}				t_piece;


typedef struct	s_info
{
	char		**map;
	char		own;
	char		enemy;
	int			player;
	int			height;
	int			width;
	int			own_x;
	int			own_y;
	int			enemy_x;
	int			enemy_y;
	int			direction;
}				t_info;

int				read_output(t_info *info, t_piece *piece, int x);
void			get_positions(t_info *info, int x, int y);
void			reach_enemy(t_info *info, t_piece *piece, int x, int y);

#endif