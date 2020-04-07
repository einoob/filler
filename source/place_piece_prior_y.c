/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_piece_prior_y.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elindber <elindber@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/07 22:17:07 by elindber          #+#    #+#             */
/*   Updated: 2020/04/07 22:17:12 by elindber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

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
