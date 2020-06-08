/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elindber <elindber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 13:50:16 by elindber          #+#    #+#             */
/*   Updated: 2020/06/02 16:34:20 by elindber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void	free_board_and_piece(t_info *info, t_piece *piece)
{
	int		y;

	y = 0;
	while (y <= info->height)
	{
		ft_strdel(&(info->board[y]));
		y++;
	}
	free(info->board);
	y = 0;
	while (y <= piece->height)
	{
		ft_strdel(&(piece->piece[y]));
		y++;
	}
	free(piece->piece);
}

void	reset_piece(t_piece *piece)
{
	piece->height = 0;
	piece->width = 0;
	piece->x_start = 0;
	piece->x_end = 0;
	piece->y_start = 1;
	piece->y_end = 0;
}

int		main(void)
{
	t_info	*info;
	t_piece *piece;

	if (!(info = (t_info*)malloc(sizeof(t_info)))
	|| !(piece = (t_piece*)malloc(sizeof(t_piece))))
		return (-1);
	info->phase = 0;
	info->own_char = NULL;
	info->enemy_char = NULL;
	while (1)
	{
		reset_piece(piece);
		if (!(read_output(info, piece, 0)))
			return (0);
		get_positions(info, 0, 0);
		reach_enemy(info, piece, 0, 0);
		free_board_and_piece(info, piece);
		if (info->stop == 1)
			break ;
	}
	free(piece);
	free(info);
	return (0);
}
