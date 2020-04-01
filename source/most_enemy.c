/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   most_enemy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elindber <elindber@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/27 13:48:09 by elindber          #+#    #+#             */
/*   Updated: 2020/04/01 19:05:55 by elindber         ###   ########.fr       */
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
	while (y <= info->height / 2 - 1)
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
		while (x <= info->width / 2 - 1)
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

int		try_follow(t_info *info, t_piece *piece, int x, int y)
{
	int		incre_y;
	int		incre_x;
	int		start_x;

	incre_y = y == 0 ? 1 : -1;
	incre_x = x == 0 ? 1 : -1;
	if (y > info->height - piece->height)
		y = info->height - piece->height;
	if (x > info->width - piece->width)
		x = info->width - piece->width;
	start_x = x;
	while (!(check_fit(info, piece, x, y)))
	{
		x += incre_x;
		if (x == info->last_x || x < 0 || x > info->width - piece->width)
		{
			x = start_x;
			y += incre_y;
		}
		if (y + incre_y == info->last_y || y < 0 || y > info->height - piece->height)
			return (0);
	}
	place_block(info, y, x);
	return (1);
}

int		enemy_direction(t_info *info, t_piece *piece, int x, int y)
{
	piece->first_x += 0;

	if (info->direction == 4)
		info->direction -= 3;
	else
		info->direction++;
	return (info->direction);
}

/*
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

/*
	int res_x;
	int res_y;

	res_y = -1;
	while (y < info->height)
	{
		while (info->board[y][x] != '\0')
		{
			if (info->board[y][x] == info->enemy_char[1])
			{
				res_x = x;
				res_y = y;
			}
			x++;
		}
		x = 0;
		y++;
	}
		if (info->own_y < info->height / 2)
	{
		if (res_y + 1 < info->height / 2)
			info->direction = res_x + 1 < info->width / 2 ? UPLEFT : UPRIGHT;
		else
			info->direction = res_x + 1 < info->width / 2 ? DOWNLEFT : DOWNRIGHT;
	}
	return (info->direction);
//IRRATIONAL
	else 
	{
		if (res_y + 1 < info->height / 2)
			info->direction = res_x + 1 < info->width / 2 ? DOWNRIGHT : DOWNLEFT;
		else
			info->direction = res_x + 1 < info->width / 2 ? UPRIGHT : UPLEFT;
	}
	ft_printf("dir: %d [%d %d]\n", info->direction, res_y, res_x);
*/
