/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_piece_prior_y.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elindber <elindber@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/07 22:17:07 by elindber          #+#    #+#             */
/*   Updated: 2020/05/29 16:41:28 by elindber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void	place_piece_prior_y(t_info *info, t_piece *piece, int x, int y)
{
	int		incre_y;
	int		incre_x;

	incre_y = y == piece->y_start ? 1 : -1;
	incre_x = x == piece->x_start ? 1 : -1;
	while (!(check_fit(info, piece, x, y)))
	{
		y += incre_y;
		if (y < piece->y_start || y > piece->y_end)
		{
			x += incre_x;
			y = y < piece->y_start ? piece->y_end : piece->y_start;
		}
		if (x < piece->x_start || x > piece->x_end)
		{
			ft_printf("0 0\n");
			info->stop = 1;
			return ;
		}
	}
	ft_printf("%d %d\n", y, x);
}
