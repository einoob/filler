/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piece_placement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elindber <elindber@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/19 14:16:23 by elindber          #+#    #+#             */
/*   Updated: 2020/03/23 14:00:20 by elindber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int		check_fit(t_info *info, t_piece *piece, int x, int y)
{
	int		overlap;
	int		px;
	int		py;
	
	overlap = 0;
	px = 0;
	py = 0;
	if (x + piece->width > info->width)
		x -= (x + piece->width - info->width);
	if (y + piece->height > info->height)
		y -= (y + piece->height - info->height);
	while (py < piece->height)
	{
		while (piece->piece[py][px] != '\0')
		{
			if (piece->piece[py][px] == '*' && info->map[y][x] == info->own)
				overlap++;
			if (overlap > 1)
				return (0);
			if (piece->piece[py][px] == '*'
			&& (info->map[y][x] != info->own && info->map[y][x] != '.'))
				return(0);
			px++;
			x++;
		}
		py++;
		y++;
		px = 0;
		x -= piece->width;
	}
	if (overlap != 1)
		return (0);
	return (1);
	
}

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
	ft_printf("%d %d\n", y, x);
}

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
		y = piece->last_y;
	else if (info->direction == DOWNRIGHT || info->direction == DOWNLEFT)
		y = piece->first_y;
	x = get_x_overlap(info, piece, x, y);
	y = info->own_y - y < 0 ? 0 : info->own_y - y;
	x = info->own_x - x < 0 ? 0 : info->own_x - x;
	place_piece(info, piece, x, y);
//	if (info->direction == UPLEFT || info->direction == UPRIGHT)
//		x = info->direction == UPLEFT ? info->own_x + x : info->own_x - x;
//	else
//		x = info->direction == DOWNLEFT ? info->own_x + x : info->own_x - x;
//	ft_printf("%d %d\n", y, x);
	//	place_piece(info, piece, x, y);
}