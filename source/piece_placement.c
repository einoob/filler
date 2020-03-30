/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piece_placement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elindber <elindber@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/19 14:16:23 by elindber          #+#    #+#             */
/*   Updated: 2020/03/30 02:57:50 by elindber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int		character_count(t_info *info, int line)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (info->map[line][i])
	{
		if (info->map[line][i] != '.' || info->map[line][i] != '.')
			count++;
		i++;
	}
	return (count > info->width / 3);
}

void	direction_change(t_info *info, int line)
{
	while (!info->phase && line < info->height)
	{
		if ((info->direction < 3 && 
		(ft_strchr(info->map[0], info->own_char[0]) || character_count(info, 0)))
		|| (info->direction > 2 && (ft_strchr(info->map[info->height - 1], info->own_char[0]) ||
		character_count(info, info->height - 1))))
		{
			if (info->direction == DOWNRIGHT || info->direction == UPRIGHT)
				info->direction = info->direction == UPRIGHT ? DOWNRIGHT : UPRIGHT;
			else if (info->direction == UPLEFT || info->direction == DOWNLEFT)
				info->direction = info->direction == UPLEFT ? DOWNLEFT : UPLEFT;
			info->phase = 1;
		}
		line++;
	}
	if (info->phase == 1 && (((character_count(info, 0) || ft_strchr(info->map[0], info->own_char[0]))
	&& info->direction < 3) || (info->direction > 2 && (ft_strchr(info->map[info->height - 1], info->own_char[0])
	|| character_count(info, info->height - 1)))))
	{
		if (info->direction == UPLEFT || info->direction == UPRIGHT)
			info->direction = info->direction == UPLEFT ? DOWNLEFT : DOWNRIGHT;
		else if (info->direction == DOWNLEFT || info->direction == DOWNRIGHT)
			info->direction = info->direction == DOWNLEFT ? UPLEFT : UPRIGHT;
		info->phase++;
	}
}

int		check_fit(t_info *info, t_piece *piece, int x, int y)
{
	int		overlap;
	int		px;
	int		py;
	
	overlap = 0;
	px = 0;
	py = 0;
	while (py < piece->height)
	{
		while (piece->piece[py][px] != '\0')
		{
			if (piece->piece[py][px] == '*' && (info->map[y][x] ==
			info->own_char[0] || info->map[y][x] == info->own_char[1]))
				overlap++;
			if (overlap > 1)
				return (0);
			if (piece->piece[py][px] == '*' && (info->map[y][x]
			!= info->own_char[0] && info->map[y][x] != info->own_char[1]
			&& info->map[y][x] != '.'))
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
	int		incre_y;
	int		incre_x;
	
	incre_y = y == 0 ? 1 : -1;
	incre_x = x == 0 ? 1 : -1;
	if (info->phase == 3 && place_middle(info, piece, 0, 0) == 1)
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
	direction_change(info, 0);
//	int i = 0;
//	while (i < 42424242)
//		i++;
	ft_printf("%d %d\n", y, x);
}

void	reach_enemy(t_info *info, t_piece *piece, int x, int y)
{
	if (info->direction == UPLEFT || info->direction == UPRIGHT)
		y = 0;	
	else if (info->direction == DOWNRIGHT || info->direction == DOWNLEFT)
		y = info->height - piece->height;
	if (info->direction == UPLEFT || info->direction == DOWNLEFT)
		x = 0;
	else if (info->direction == UPRIGHT || info->direction == DOWNRIGHT)
		x = info->width - piece->width;
	if (info->phase == 3)
		most_enemy(info, 0);
	if (info->phase == 2)//&& character_count(info, 0) && character_count(info, info->height - 1))
		place_piece_prior_y(info, piece, x, y);
	else
		place_piece(info, piece, x, y);
}