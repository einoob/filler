/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piece_placement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elindber <elindber@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/19 14:16:23 by elindber          #+#    #+#             */
/*   Updated: 2020/04/02 01:26:59 by elindber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int		character_count(t_info *info, int line)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (info->board[line][i])
	{
		if (info->board[line][i] != '.' || info->board[line][i] != '.')
			count++;
		i++;
	}
	return (count > info->width / 3);
}

void	direction_change(t_info *info)
{
	if (info->phase == 0 && ((info->direction < 3 && (ft_strchr
(info->board[0], info->own_char[0]) || character_count(info, 0)))
	|| (info->direction > 2 && (ft_strchr(info->board[info->height - 1],
	info->own_char[0]) || character_count(info, info->height - 1)))))
	{
		if (info->direction == DOWNRIGHT || info->direction == UPRIGHT)
			info->direction = info->direction == UPRIGHT ? DOWNRIGHT : UPRIGHT;
		else if (info->direction == UPLEFT || info->direction == DOWNLEFT)
			info->direction = info->direction == UPLEFT ? DOWNLEFT : UPLEFT;
		info->phase = 1;
	}
	if (info->phase == 1 && (((character_count(info, 0) || ft_strchr
(info->board[0], info->own_char[0])) && info->direction < 3) ||
	(info->direction > 2 && (ft_strchr(info->board[info->height - 1],
	info->own_char[0]) || character_count(info, info->height - 1)))))
	{
		if (info->direction == UPLEFT || info->direction == UPRIGHT)
			info->direction = info->direction == UPLEFT ? DOWNLEFT : DOWNRIGHT;
		else if (info->direction == DOWNLEFT || info->direction == DOWNRIGHT)
			info->direction = info->direction == DOWNLEFT ? UPLEFT : UPRIGHT;
		info->phase = 2;
	}
}

int		check_fit(t_info *info, t_piece *piece, int x, int y)
{
	int		overlap;
	int		px;
	int		py;

	overlap = 0;
	px = -1;
	py = -1;
	while (++py < piece->height)
	{
		while (piece->piece[py][++px] != '\0')
		{
			if (piece->piece[py][px] == '*' && (info->board[y][x] ==
			info->own_char[0] || info->board[y][x] == info->own_char[1]))
				overlap++;
			if (overlap > 1 || (piece->piece[py][px] == '*' &&
			(info->board[y][x] != info->own_char[0] && info->board[y][x]
			!= info->own_char[1] && info->board[y][x] != '.')))
				return (0);
			x++;
		}
		y++;
		px = -1;
		x -= piece->width;
	}
	return (overlap == 1);
}

void	place_piece(t_info *info, t_piece *piece, int x, int y)
{
	int		incre_y;
	int		incre_x;

	incre_y = y == 0 ? 1 : -1;
	incre_x = x == 0 ? 1 : -1;
	if (info->phase > 2 && place_middle(info, piece, 0, info->direction) == 1)
		return ;
	while (!(check_fit(info, piece, x, y)))
	{
		x += incre_x;
		if (x < 0 || x > info->width - piece->width)
		{
			y += incre_y;
			x = x == -1 ? info->width - piece->width : 0;
		}
		if (y < 0 || y > info->height - piece->height)
		{
			ft_printf("0 0\n");
			info->stop = 1;
			return ;
		}
	}
	if (info->phase < 2)
		direction_change(info);
	place_block(info, y, x);
}

void	reach_enemy(t_info *info, t_piece *piece, int x, int y)
{
	y = info->direction < 3 ? 0 : info->height - piece->height;
	x = info->direction % 2 == 0 ? 0 : info->width - piece->width;
	if (info->phase == 3 && enemy_direction(info, piece))
		return ;
	if (info->phase == 2)
		place_piece_prior_y(info, piece, x, y);
	else
		place_piece(info, piece, x, y);
}
