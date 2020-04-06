/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   most_empty.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elindber <elindber@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/03 13:13:45 by elindber          #+#    #+#             */
/*   Updated: 2020/04/06 13:18:47 by elindber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

static int	top_left(t_info *info, int x, int y)
{
	int		count;

	count = 0;
	while (y + 1 < info->height / 2)
	{
		while (x + 1 < info->width / 2)
		{
			if (info->board[y][x] != info->own_char[0]
			&& info->board[y][x] != info->own_char[1])
				count++;
			x++;
		}
		y++;
		x = 0;
	}
	return (count);
}

static int	top_right(t_info *info, int x, int y)
{
	int		count;

	count = 0;
	while (y + 1 < info->height / 2)
	{
		while (x < info->width)
		{
			if (info->board[y][x] != info->own_char[0]
			&& info->board[y][x] != info->own_char[1])
				count++;
			x++;
		}
		y++;
		x = info->width / 2;
	}
	return (count);
}

static int	bottom_left(t_info *info, int x, int y)
{
	int		count;

	count = 0;
	while (y < info->height)
	{
		while (x + 1 < info->width / 2)
		{
			if (info->board[y][x] != info->own_char[0]
			&& info->board[y][x] != info->own_char[1])
				count++;
			x++;
		}
		y++;
		x = 0;
	}
	return (count);
}

static int	bottom_right(t_info *info, int x, int y)
{
	int		count;

	count = 0;
	while (y < info->height)
	{
		while (x < info->width)
		{
			if (info->board[y][x] != info->own_char[0]
			&& info->board[y][x] != info->own_char[1])
				count++;
			x++;
		}
		y++;
		x = info->width / 2;
	}
	return (count);
}

int			most_empty(t_info *info, int max, int res)
{
	res = top_left(info, 0, 0);
	if (max < res)
	{
		max = res;
		info->direction = 2;
	}
	res = top_right(info, info->width / 2, 0);
	if (max < res)
	{
		max = res;
		info->direction = 1;
	}
	res = bottom_left(info, 0, info->height / 2);
	if (max < res)
	{
		max = res;
		info->direction = 4;
	}
	res = bottom_right(info, info->width / 2, info->height / 2);
	if (max < res)
	{
		max = res;
		info->direction = 3;
	}
	return (info->direction);
}
