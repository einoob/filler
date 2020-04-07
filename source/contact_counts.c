/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact_counts.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elindber <elindber@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/07 13:22:26 by elindber          #+#    #+#             */
/*   Updated: 2020/04/07 13:45:56 by elindber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int		own_char(t_info *info, char board)
{
	return (board == info->own_char[0] || board == info->own_char[1]);
}

void	further_corners(t_info *info, int x, int y)
{
	double	count;

	count = 0;
	if (y > 1 && x > 1 && (info->board[y - 2][x - 2] == info->enemy_char[0]
	|| info->board[y - 2][x - 2] == info->enemy_char[1]))
		count += 0.5;
	if (y > 1 && x + 2 < info->width
	&& (info->board[y - 2][x + 2] == info->enemy_char[0]
	|| info->board[y - 2][x + 2] == info->enemy_char[1]))
		count += 0.5;
	if (y + 2 < info->height && x > 1
	&& (info->board[y + 2][x - 2] == info->enemy_char[0]
	|| info->board[y + 2][x - 2] == info->enemy_char[1]))
		count += 0.5;
	if (y + 2 < info->height && x + 2 < info->width
	&& (info->board[y + 2][x + 2] == info->enemy_char[0]
	|| info->board[y + 2][x + 2] == info->enemy_char[1]))
		count += 0.5;
	info->contacts += count;
}

void	further_contacts(t_info *info, int x, int y)
{
	double count;

	count = 0;
	if (x + 3 < info->width && (info->board[y][x + 3] == info->enemy_char[0] ||
	info->board[y][x + 3] == info->enemy_char[1]))
		count += 0.5;
	if (x > 2 && (info->board[y][x - 3] == info->enemy_char[0] ||
	info->board[y][x - 3] == info->enemy_char[1]))
		count += 0.5;
	if (y + 3 < info->height && (info->board[y + 3][x] == info->enemy_char[0] ||
	info->board[y + 3][x] == info->enemy_char[1]))
		count += 0.5;
	if (y > 2 && (info->board[y - 3][x] == info->enemy_char[0] ||
	info->board[y - 3][x] == info->enemy_char[1]))
		count += 0.5;
	info->contacts += count;
	further_corners(info, x, y);
}

void	count_corners(t_info *info, int x, int y)
{
	int		count;

	count = 0;
	if (y > 0 && x > 0 && (info->board[y - 1][x - 1] == info->enemy_char[0]
	|| info->board[y - 1][x - 1] == info->enemy_char[1]))
		count++;
	if (y > 0 && x + 1 < info->width
	&& (info->board[y - 1][x + 1] == info->enemy_char[0]
	|| info->board[y - 1][x + 1] == info->enemy_char[1]))
		count++;
	if (y + 1 < info->height && x > 0
	&& (info->board[y + 1][x - 1] == info->enemy_char[0]
	|| info->board[y + 1][x - 1] == info->enemy_char[1]))
		count++;
	if (y + 1 < info->height && x + 1 < info->width
	&& (info->board[y + 1][x + 1] == info->enemy_char[0]
	|| info->board[y + 1][x + 1] == info->enemy_char[1]))
		count++;
	info->contacts += count;
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
	count_corners(info, x, y);
	further_contacts(info, x, y);
	return (1);
}
