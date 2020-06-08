/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piece_placement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elindber <elindber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/19 14:16:23 by elindber          #+#    #+#             */
/*   Updated: 2020/06/08 16:58:50 by elindber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void	direction_change(t_info *info)
{
	int		row;

	row = 0;
	while (info->phase == 0 && row < info->height)
	{
		if (ft_strstr(info->board[row], "XO") ||
		ft_strstr(info->board[row], "OX") || ft_strstr(info->board[row], "O.X")
		|| ft_strstr(info->board[row], "X.O") || ft_strstr(info->board[row],
		"O..X") || ft_strstr(info->board[row], "X..O") ||
		ft_strstr(info->board[0], "OO") || ft_strstr(info->board[0], "XX")
		|| ft_strstr(info->board[info->height - 1], "OO") ||
		ft_strstr(info->board[info->height - 1], "XX"))
			info->phase = 1;
		row++;
	}
	if (info->height < 20 && info->player == 2 &&
	(ft_strstr(info->board[0], ".................")))
		info->phase = 0;
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
			if (piece->piece[py][px] == '*' &&
			own_char(info, info->board[y][x]) && count_contacts(info, x, y))
				overlap++;
			if (overlap > 1 || (piece->piece[py][px] == '*' &&
			!(own_char(info, info->board[y][x])) && info->board[y][x] != '.'))
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

	incre_y = y == piece->y_start ? 1 : -1;
	incre_x = x == piece->x_start ? 1 : -1;
	while (!(check_fit(info, piece, x, y)))
	{
		x += incre_x;
		if (x < piece->x_start || x > piece->x_end)
		{
			y += incre_y;
			x = x < piece->x_start ? piece->x_end : piece->x_start;
		}
		if (y < piece->y_start || y > piece->y_end)
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
	double	contacts;
	int		incre_x;
	int		incre_y;

	contacts = 0;
	incre_y = y == piece->y_start ? 1 : -1;
	incre_x = x == piece->x_start ? 1 : -1;
	while (y >= piece->y_start && y <= piece->y_end)
	{
		while (x >= piece->x_start && x <= piece->x_end)
		{
			if (check_fit(info, piece, x, y) && info->contacts > contacts)
			{
				info->put_x = x;
				info->put_y = y;
				contacts = info->contacts;
			}
			x += incre_x;
		}
		y += incre_y;
		x = incre_x < 0 ? piece->x_end : piece->x_start;
	}
	return (contacts > 0);
}

void	reach_enemy(t_info *info, t_piece *piece, int x, int y)
{
	info->put_x = 0;
	info->put_y = 0;
	if (info->phase > 0)
		info->direction = most_enemy(info, 0, 0);
	y = info->direction < 3 ? piece->y_start : piece->y_end;
	x = info->direction % 2 == 0 ? piece->x_start : piece->x_end;
	if (info->phase > 0 && block_enemy(info, piece, x, y))
		ft_printf("%d %d\n", info->put_y, info->put_x);
	else if (info->phase > 0)
		place_piece_prior_y(info, piece, x, y);
	else
		place_piece(info, piece, x, y);
}
