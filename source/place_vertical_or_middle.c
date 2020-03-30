/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_vertical_or_middle.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elindber <elindber@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/30 02:06:31 by elindber          #+#    #+#             */
/*   Updated: 2020/03/30 02:58:08 by elindber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int		far_side(t_info *info, int row, int count, int own)
{
	int		column;

	column = info->own_x < info->width / 2 ? info->width - 1 : 0;
	while (row < info->height)
	{
		if (info->map[row][column] != '.')
			count++;
		if (info->map[row][column] == info->own_char[0])
			own++;
		row++;
	}
	return (count > info->height / 3 ||
	own >= info->height / 4);
}

void	place_piece_prior_y(t_info *info, t_piece *piece, int x, int y)
{
	int		incre_y;
	int		incre_x;
	
	incre_y = y == 0 ? 1 : -1;
	incre_x = x == 0 ? 1 : -1;
	while (!(check_fit(info, piece, x, y)))
	{
		y += incre_y;
		if (y < 0 || y> info->height - piece->height)
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
	if (info->phase == 2 && far_side(info, 0, 0, 0))
		info->phase++;
//	int i = 0;
//	while (i < 42424242)
//		i++;
	ft_printf("%d %d\n", y, x);
}

int		place_middle(t_info *info, t_piece *piece, int x, int y)
{
	int		incre_x;
	int		incre_y;

	incre_x = info->direction % 2 == 0 ? 1 : -1;
	incre_y = info->direction < 3 ? 1 : -1;
	x = incre_x == 1 ? info->width / 4 : 3 * (info->width / 4);
	y = incre_y == 1 ? info->height / 4 : 3 * (info->height / 4);
	if (x + piece->width > info->width || y + piece->height > info->height)
		return (0);
	while (!(check_fit(info, piece, x, y)))
	{
		x += incre_x;
		if (x < info->width / 4 || x > 3 * (info->width / 4))
		{
			y += incre_y;
			x = incre_x == 1 ? info->width / 4 : 3 * (info->width / 4);
		}
		if (y < info->height / 4 || y > 3 * (info->height / 4))
			return (0);
		if (x + piece->width > info->width || y + piece->height > info->height)
			return (0);
	}
//	int i = 0;
//	while (i < 42424242)
//		i++;
	ft_printf("%d %d\n", y, x);
	return (1);
}