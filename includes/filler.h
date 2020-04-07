/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elindber <elindber@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 13:26:42 by elindber          #+#    #+#             */
/*   Updated: 2020/04/07 13:49:04 by elindber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

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
	char		**board;
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
	int			phase;
	int			most_enemy;
	double		contacts;
	int			put_x;
	int			put_y;
	int			stop;
}				t_info;

int				read_output(t_info *info, t_piece *piece, int x);
int				check_fit(t_info *info, t_piece *piece, int x, int y);
int				own_char(t_info *info, char board);
int				place_middle(t_info *info, t_piece *piece, int x, int direction);
int				most_enemy(t_info *info, int max, int res);
int				count_contacts(t_info *info, int x, int y);
void			get_positions(t_info *info, int x, int y);
void			reach_enemy(t_info *info, t_piece *piece, int x, int y);
void			place_piece_prior_y(t_info *info, t_piece *piece, int x, int y);

#endif