/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piece_placement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elindber <elindber@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/19 14:16:23 by elindber          #+#    #+#             */
/*   Updated: 2020/03/19 15:00:29 by elindber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

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
	ft_printf("%d %d\n", x, y);
}