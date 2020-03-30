/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elindber <elindber@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 13:26:42 by elindber          #+#    #+#             */
/*   Updated: 2020/03/30 02:11:22 by elindber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include <unistd.h>
# include <stdlib.h>
# include "../libftprintf/includes/ft_printf.h"
# include "../libftprintf/includes/get_next_line.h"
# include "../libftprintf/libft/libft.h"

# define UPRIGHT 1
# define UPLEFT 2
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
	char		*own_char;
	char		*enemy_char;
	int			player;
	int			height;
	int			width;
	int			own_x;
	int			own_y;
	int			enemy_x;
	int			enemy_y;
	int			direction;
	int			stop;
	int			phase;
}				t_info;

int				read_output(t_info *info, t_piece *piece, int x);
int				check_fit(t_info *info, t_piece *piece, int x, int y);
int				place_middle(t_info *info, t_piece *piece, int x, int y);
void			get_positions(t_info *info, int x, int y);
void			reach_enemy(t_info *info, t_piece *piece, int x, int y);
void			most_enemy(t_info *info, int max);
void			place_piece_prior_y(t_info *info, t_piece *piece, int x, int y);

#endif