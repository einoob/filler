/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piece_placement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elindber <elindber@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/19 14:16:23 by elindber          #+#    #+#             */
/*   Updated: 2020/04/03 18:41:27 by elindber         ###   ########.fr       */
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
	int		row;

	row = 0;
	while (info->phase == 0 && row < info->height)
	{
		if (ft_strstr(info->board[row], "XO") || ft_strstr(info->board[row], "OX") ||
		ft_strstr(info->board[0], "OO") || ft_strstr(info->board[0], "XX"))
			info->phase = 1;
		row++;
	}
}

int		count_contacts(t_info *info, int x, int y)
{
	int		count;

	count = 0;
	if (x + 2 < info->width && (info->board[y][x + 2] == info->enemy_char[0] ||
	info->board[y][x + 2] == info->enemy_char[1]))
		count++;
	if (x > 1 && (info->board[y][x - 2] == info->enemy_char[0] ||
	info->board[y][x - 2] == info->enemy_char[1]))
		count++;
	if (y + 2 < info->height && (info->board[y + 2][x] == info->enemy_char[0] ||
	info->board[y + 2][x] == info->enemy_char[1]))
		count++;
	if (y > 1 && (info->board[y - 2][x] == info->enemy_char[0] ||
	info->board[y - 2][x] == info->enemy_char[1]))
		count++;
	info->contacts += count;
	return (1);
}

int		check_fit(t_info *info, t_piece *piece, int x, int y)
{
	int		overlap;
	int		px;
	int		py;

	overlap = 0;
	px = -1;
	py = -1;
	info->contacts = 0;
	while (++py < piece->height)
	{
		while (piece->piece[py][++px] != '\0')
		{
			if (piece->piece[py][px] == '*' && (info->board[y][x] ==
			info->own_char[0] || info->board[y][x] == info->own_char[1])
			&& count_contacts(info, x, y))
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
	if (info->phase < 1)
		direction_change(info);
	ft_printf("%d %d\n", y, x);
}

int		block_enemy(t_info *info, t_piece *piece, int x, int y)
{
	int		contacts;
	int		incre_x;
	int		incre_y;

	contacts = 0;
	incre_y = y == 0 ? 1 : -1;
	incre_x = x == 0 ? 1 : -1;
	while (y >= 0 && y <= info->height - piece->height)
	{
		while (x >= 0 && x <= info->width - piece->width)
		{
			if (check_fit(info, piece, x, y))
			{
				if (info->contacts > contacts)
				{
					info->put_x = x;
					info->put_y = y;
					contacts = info->contacts;
				}
			}
			x += incre_x;
		}
		y += incre_y;
		x = incre_x < 0 ? info->width - piece->width : 0;
	}
	return (contacts > 0);
}

void	reach_enemy(t_info *info, t_piece *piece, int x, int y)
{
	info->put_x = 0;
	info->put_y = 0;
	if (info->phase > 0) 
		enemy_direction(info, 1);
	y = info->direction < 3 ? 0 : info->height - piece->height;
	x = info->direction % 2 == 0 ? 0 : info->width - piece->width;
	if (info->phase > 0 && block_enemy(info, piece, x, y))
	{
		ft_printf("%d %d\n", info->put_y, info->put_x);
		return ;
	}
	if (info->phase > 0)
		place_piece_prior_y(info, piece, x, y);
	else
		place_piece(info, piece, x, y);
}
