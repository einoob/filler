/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elindber <elindber@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 13:50:16 by elindber          #+#    #+#             */
/*   Updated: 2020/04/02 00:27:27 by elindber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void	free_board(t_info *info)
{
	int		y;

	y = 0;
	while (y <= info->height)
	{
		ft_strdel(&(info->board[y]));
		y++;
	}
	free(info->board);
}

void	place_block(t_info *info, int y, int x)
{
	info->last_x = x;
	info->last_y = y;
	ft_printf("%d %d\n", y, x);
}

void	reset_piece(t_piece *piece)
{
	piece->height = 0;
	piece->width = 0;
	piece->first_x = 0;
	piece->last_x = 0;
	piece->first_y = 0;
	piece->last_y = 0;
}

int		main(void)
{
	t_info	*info;
	t_piece *piece;

	if (!(info = (t_info*)malloc(sizeof(t_info)))
	|| !(piece = (t_piece*)malloc(sizeof(t_piece))))
		return (-1);
	info->phase = 0;
	while (1)
	{
//		int i = 0;
//		while (i < 42424242)
//			i++;
		reset_piece(piece);
		if (!(read_output(info, piece, 0)))
			return (0);
		get_positions(info, 0, 0);
		reach_enemy(info, piece, 0, 0);
		free_board(info);
		if (info->stop)
			break ;
	}
	free(piece);
	free(info);
	return (0);
}
