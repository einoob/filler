/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   block_enemy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elindber <elindber@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/27 13:48:09 by elindber          #+#    #+#             */
/*   Updated: 2020/03/29 17:23:24 by elindber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int		top_left(t_info *info, int x, int y)
{
	int		count;

	count = 0;
	while (y <= info->height / 2 - 1)
	{
		while (x <= info->width / 2 - 1)
		{
			if (info->map[y][x] == info->enemy_char[0]
			|| info->map[y][x] == info->enemy_char[1])
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
	while (y <= info->height / 2 - 1)
	{
		while (x < info->width)
		{
			if (info->map[y][x] == info->enemy_char[0]
			|| info->map[y][x] == info->enemy_char[1])
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
		while (x <= info->width / 2 - 1)
		{
			if (info->map[y][x] == info->enemy_char[0]
			|| info->map[y][x] == info->enemy_char[1])
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
			if (info->map[y][x] == info->enemy_char[0]
			|| info->map[y][x] == info->enemy_char[1])
				count++;
			x++;
		}
		y++;
		x = info->width / 2;
	}
	return (count);
}

void	most_enemy(t_info *info, int max)
{
	if (max < top_left(info, 0, 0))
	{
		max = top_left(info, 0, 0);
		info->direction = UPLEFT;
	}
	if (max < top_right(info, info->width / 2, 0))
	{
		max = top_right(info, info->width / 2, 0);
		info->direction = UPRIGHT;
	}
	if (max < bottom_left(info, 0, info->height / 2))
	{
		max = bottom_left(info, 0, info->height / 2);
		info->direction = DOWNRIGHT;
	}
	if (max < bottom_right(info, info->width / 2, info->height / 2))
		info->direction = DOWNLEFT;
}
