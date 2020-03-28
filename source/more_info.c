/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elindber <elindber@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/18 14:42:36 by elindber          #+#    #+#             */
/*   Updated: 2020/03/27 13:55:30 by elindber         ###   ########.fr       */
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
//	ft_printf("direction: %d\n", info->direction);
}

void	get_positions(t_info *info, int x, int y)
{
	if (info->own_char && info->enemy_char)
		return ;
	info->own_char = info->player == 1 ? "Oo" : "Xx";
	info->enemy_char = info->player == 1 ? "Xx" : "Oo";
	while (info->map[y] != NULL)
	{
		while (info->map[y][x] != '\0')
		{
			if (info->map[y][x] == info->own_char[0]
			|| info->map[y][x] == info->own_char[1])
			{
				info->own_x = x;
				info->own_y = y;
			}
			if (info->map[y][x] == info->enemy_char[0]
			|| info->map[y][x] == info->enemy_char[1])
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