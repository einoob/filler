/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_vertical_or_middle.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elindber <elindber@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/30 02:06:31 by elindber          #+#    #+#             */
/*   Updated: 2020/04/06 12:47:49 by elindber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int		enemy_direction(t_info *info, int character)
{
	if (character == 1)
		info->direction = most_enemy(info, 0, 0);
	else
		info->direction = most_empty(info, 0, 0);
	return (info->direction);
}

int		far_side(t_info *info, int row, int count, int own)
{
	int		column;
	int		incre_y;

	column = info->own_x < info->width / 2 ? info->width - 1 : 0;
	row = info->direction < 3 ? info->height - 1 : 0;
	incre_y = row == 0 ? 1 : -1;
	while (row < info->height)
	{
		if (info->board[row][column] != '.')
			count++;
		if (info->board[row][column] == info->own_char[0])
			own++;
		row += incre_y;
		if (row == ((info->height / 2) - 1))
			break ;
	}
	return (count > info->height / 3 ||
	own >= info->height / 10);
}

void	place_piece_prior_y(t_info *info, t_piece *piece, int x, int y)
{
	int		incre_y;
	int		incre_x;

	y = info->direction < 3 ? 0 : info->height - piece->height;
	x = info->direction % 2 == 0 ? 0 : info->width - piece->width;
	incre_y = y == 0 ? 1 : -1;
	incre_x = x == 0 ? 1 : -1;
	while (!(check_fit(info, piece, x, y)))
	{
		y += incre_y;
		if (y < 0 || y > info->height - piece->height)
		{
			x += incre_x;
			y = y == -1 ? info->height - piece->height : 0;
		}
		if (x < 0 || x > info->width - piece->width)
		{
			ft_printf("0 0\n");
			info->stop = 1;
			return ;
		}
	}
	ft_printf("%d %d\n", y, x);
}

int		place_middle(t_info *info, t_piece *piece, int x, int direction)
{
	int		incre_x;
	int		incre_y;
	int		y;

	if (direction < 1 || direction > 4)
		direction = direction > 4 ? 1 : 4;
	incre_x = direction % 2 == 0 ? -1 : 1;
	incre_y = direction < 3 ? -1 : 1;
	x = -2 + info->width / 2;
	y = -1 + info->height / 2;
	if (x + piece->width > info->width || y + piece->height > info->height)
		return (0);
	while (!(check_fit(info, piece, x, y)))
	{
		x += incre_x;
		if (x < 0 || x + piece->width > info->width)
		{
			y += incre_y;
			x = -1 + info->width / 2;
		}
		if (y == info->height / 5 || y == 4 * (info->height / 5) || 
		y + piece->height > info->height)
			return (0);
	}
	ft_printf("%d %d\n", y, x);
	return (1);
}
