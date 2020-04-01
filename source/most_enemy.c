/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   most_enemy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elindber <elindber@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/27 13:48:09 by elindber          #+#    #+#             */
/*   Updated: 2020/04/02 01:23:35 by elindber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int		top_left(t_info *info, int x, int y)
{
	int		count;

	count = 0;
	while (y + 1 < info->height / 2)
	{
		while (x + 1 < info->width / 2)
		{
			if (info->board[y][x] == info->enemy_char[0]
			|| info->board[y][x] == info->enemy_char[1])
				count++;
			x++;
		}
		y++;
		x = 0;
	}
	return (count);
}

int		top_right(t_info *info, int x, int y)
{
	int		count;

	count = 0;
	while (y + 1 < info->height / 2)
	{
		while (x < info->width)
		{
			if (info->board[y][x] == info->enemy_char[0]
			|| info->board[y][x] == info->enemy_char[1])
				count++;
			x++;
		}
		y++;
		x = info->width / 2;
	}
	return (count);
}

int		bottom_left(t_info *info, int x, int y)
{
	int		count;

	count = 0;
	while (y < info->height)
	{
		while (x + 1 < info->width / 2)
		{
			if (info->board[y][x] == info->enemy_char[0]
			|| info->board[y][x] == info->enemy_char[1])
				count++;
			x++;
		}
		y++;
		x = 0;
	}
	return (count);
}

int		bottom_right(t_info *info, int x, int y)
{
	int		count;

	count = 0;
	while (y < info->height)
	{
		while (x < info->width)
		{
			if (info->board[y][x] == info->enemy_char[0]
			|| info->board[y][x] == info->enemy_char[1])
				count++;
			x++;
		}
		y++;
		x = info->width / 2;
	}
	return (count);
}

int		most_enemy(t_info *info, t_piece *piece, int max, int res)
{
	res = top_left(info, 0, 0);
	if (max < res)
	{
		max = res;
		info->most_enemy = 2;
	}
	res = top_right(info, info->width / 2, 0);
	if (max < res)
	{
		max = res;
		info->most_enemy = 1;
	}
	res = bottom_left(info, 0, info->height / 2);
	if (max < res)
	{
		max = res;
		info->most_enemy = 4;
	}
	res = bottom_right(info, info->width / 2, info->height / 2);
	if (max < res)
	{
		max = res;
		info->most_enemy = 3;
	}
	return (place_middle(info, piece, 0, info->most_enemy));
}
