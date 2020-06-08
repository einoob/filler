/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elindber <elindber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/02 14:00:24 by elindber          #+#    #+#             */
/*   Updated: 2020/06/08 13:20:34 by elindber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"

void	fill_square(t_board *board, int x, int y)
{
	int		x_limit;
	int		y_limit;

	x_limit = x + board->increment - 1;
	y_limit = y + board->increment - 1;
	while (y < y_limit)
	{
		while (x < x_limit)
		{
			mlx_pixel_put(board->mlx, board->win, x, y, board->color);
			x++;
		}
		x -= (board->increment - 1);
		y++;
	}
}

void	determine_color(t_board *board, int y, int x)
{
	int		x_start;
	int		y_start;

	x_start = (1400 - (board->x_half * 2)) / 2 + x * board->increment;
	y_start = (1200 - (board->y_half * 2)) / 2 + y * board->increment;
	if (board->board[y][x] == board->own_char[0] ||
	board->board[y][x] == board->own_char[1])
	{
		board->color = board->board[y][x] == board->own_char[0] ?
		0XFF9900 : 0XFFC266;
		fill_square(board, x_start + 1, y_start + 1);
		board->own_score++;
	}
	else if (board->board[y][x] == board->enemy_char[0] ||
	board->board[y][x] == board->enemy_char[1])
	{
		board->color = board->board[y][x] == board->enemy_char[0] ?
		0X6A4DFF : 0X9580FF;
		fill_square(board, x_start + 1, y_start + 1);
		board->enemy_score++;
	}
}

void	iterate_board(t_board *board, int x, int y)
{
	while (y < board->height)
	{
		while (x < board->width)
		{
			if (board->board[y][x] == board->own_char[0] ||
			board->board[y][x] == board->own_char[1] ||
			board->board[y][x] == board->enemy_char[0] ||
			board->board[y][x] == board->enemy_char[1])
			{
				determine_color(board, y, x);
			}
			x++;
		}
		x = 0;
		y++;
	}
}

void	draw_grid(t_board *board, int y, int x)
{
	x = 700 - board->x_half;
	y = 600 - board->y_half;
	while (y <= 600 + board->y_half)
	{
		while (x <= 700 + board->x_half)
		{
			mlx_pixel_put(board->mlx, board->win, x, y, 0X797D7F);
			x++;
		}
		y += board->increment;
		x = 700 - board->x_half;
	}
	y = 600 - board->y_half;
	while (x <= 700 + board->x_half)
	{
		while (y <= 600 + board->y_half)
		{
			mlx_pixel_put(board->mlx, board->win, x, y, 0X797D7F);
			y++;
		}
		x += board->increment;
		y = 600 - board->y_half;
	}
}

void	visualize_game(t_board *board, int y, int x)
{
	char	*enemy_scr;
	char	*own_scr;

	board->own_score = 0;
	board->enemy_score = 0;
	draw_grid(board, y, x);
	iterate_board(board, 0, 0);
	score_bar(board, 0, 0);
	own_scr = ft_itoa(board->own_score);
	enemy_scr = ft_itoa(board->enemy_score);
	mlx_string_put(board->mlx, board->win, 600, 30, 0XFF9900, "YOUR SCORE:");
	mlx_string_put(board->mlx, board->win, 600, 55, 0X9580FF, "ENEMY SCORE:");
	mlx_string_put(board->mlx, board->win, 770, 30, 0XFF9900, own_scr);
	mlx_string_put(board->mlx, board->win, 770, 55, 0X9580FF, enemy_scr);
	free(own_scr);
	free(enemy_scr);
}
