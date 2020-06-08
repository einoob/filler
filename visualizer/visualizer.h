/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualizer.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elindber <elindber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/02 12:49:01 by elindber          #+#    #+#             */
/*   Updated: 2020/06/08 16:14:39 by elindber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISUALIZER_H
# define VISUALIZER_H

# include "mlx.h"
# include "../libftprintf/includes/ft_printf.h"
# include "../libftprintf/includes/get_next_line.h"
# include "../libftprintf/libft/libft.h"

typedef struct	s_board
{
	void		*mlx;
	void		*win;
	char		**board;
	char		*own_char;
	char		*enemy_char;
	char		*own_name;
	char		*enemy_name;
	int			player;
	int			height;
	int			width;
	int			stop;
	int			increment;
	int			y_half;
	int			x_half;
	int			own_score;
	int			enemy_score;
	int			own_result;
	int			enemy_result;
	int			color;
	int			bpp;
	int			bar_width;
	int			endian;
}				t_board;

int				read_output(t_board *board, int x);
int				dup_board(t_board *board, int y);
int				re_allocate(t_board *board);
int				re_draw(t_board *board);
void			set_start_values(t_board *board);
void			free_board(t_board *board, int y);
void			score_bar(t_board *board, int y, int x);
void			visualize_game(t_board *board, int y, int x);
void			get_final_result(t_board *board, char *line, int i);

#endif
