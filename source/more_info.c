/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elindber <elindber@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/18 14:42:36 by elindber          #+#    #+#             */
/*   Updated: 2020/04/06 16:20:34 by elindber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void	determine_direction(t_info *info)
{
	if (info->own_y >= info->enemy_y && info->own_x >= info->enemy_x)
		info->direction = UPLEFT;
	else if (info->own_y >= info->enemy_y && info->own_x <= info->enemy_x)
		info->direction = UPRIGHT;
	else if (info->own_y <= info->enemy_y && info->own_x <= info->enemy_x)
		info->direction = DOWNRIGHT;
	else if (info->own_y <= info->enemy_y && info->own_x >= info->enemy_x)
		info->direction = DOWNLEFT;
	if (info->own_y > info->height / 2 && info->own_x < info->width / 2
	&& info->height < 20)
		info->direction = UPRIGHT;
	else if (info->own_y > info->height / 2 && info->height == 24)
		info->direction = DOWNRIGHT;
}

void	get_positions(t_info *info, int x, int y)
{
	if (info->own_char && info->enemy_char)
		return ;
	info->own_char = info->player == 1 ? "Oo" : "Xx";
	info->enemy_char = info->player == 1 ? "Xx" : "Oo";
	while (info->board[y] != NULL)
	{
		while (info->board[y][x] != '\0')
		{
			if (info->board[y][x] == info->own_char[0])
			{
				info->own_x = x;
				info->own_y = y;
			}
			if (info->board[y][x] == info->enemy_char[0])
			{
				info->enemy_x = x;
				info->enemy_y = y;
			}
			x++;
		}
		x = 0;
		y++;
	}
	determine_direction(info);
}
