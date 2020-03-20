/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piece_placement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elindber <elindber@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/19 14:16:23 by elindber          #+#    #+#             */
/*   Updated: 2020/03/20 15:10:46 by elindber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

//int		check_fit(t_info *info, t_piece *piece, int x, int y)
//{
//	int		overlap;

//	overlap = 0;
	
//}
/*
void	place_piece(t_info *info, t_piece *piece, int x, int y)
{
	if (!(check_fit(info, piece, x, y)))
	{
		x++;
		if (piece->piece[y][x] == '\0')
		{
			y++;
			x = 0;
		}
		place_piece(info, piece, x, y);
	}
}*/

int		get_x_overlap(t_info *info, t_piece *piece, int x, int y)
{
	if (info->direction == UPLEFT || info->direction == DOWNLEFT)
	{
		x = piece->width - 1;
		while (piece->piece[y][x] != '*')
			x--;
	}
	else
		while (piece->piece[y][x] != '*')
			x++;
	return (x);
}

void	reach_enemy(t_info *info, t_piece *piece, int x, int y)
{
	if (info->direction == UPLEFT || info->direction == UPRIGHT)
	{
		y = piece->last_y;
		x = get_x_overlap(info, piece, x, y);
	}
	else if (info->direction == DOWNRIGHT || info->direction == DOWNLEFT)
	{
		y = piece->first_y;
		x = get_x_overlap(info, piece, x, y);
	}
	y = info->direction < 3 ? info->own_y + y : info->own_y - y;
	if (info->direction == UPLEFT || info->direction == UPRIGHT)
		x = info->direction == UPLEFT ? info->own_x + x : info->own_x - x;
	else
		x = info->direction == DOWNLEFT ? info->own_x + x : info->own_x - x;
	ft_printf("%d %d\n", y, x);
//	place_piece(info, piece, x, y);
}