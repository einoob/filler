/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_funcs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elindber <elindber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 12:48:32 by elindber          #+#    #+#             */
/*   Updated: 2020/06/08 16:45:09 by elindber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"

void	free_board(t_board *board, int y)
{
	while (y <= board->height)
	{
		ft_strdel(&(board->board[y]));
		y++;
	}
	free(board->board);
}

int		re_allocate(t_board *board)
{
	if (!(board->board =
	(char**)malloc(sizeof(char*) * (board->height + 1))))
		return (0);
	return (1);
}

void	set_start_values(t_board *board)
{
	if (board->height < 50)
		board->increment = board->height < 25 ? 28 : 18;
	else
		board->increment = 8;
	board->x_half = board->width * board->increment / 2;
	board->y_half = board->height * board->increment / 2;
}

void	score_bar(t_board *board, int y, int x)
{
	void	*img_ptr;
	int		*img_data;
	int		score_sum;
	int		own_share;

	score_sum = board->own_score + board->enemy_score;
	own_share = 200 * board->own_score / score_sum;
	img_ptr = mlx_new_image(board->mlx, 200, 50);
	img_data = (int*)mlx_get_data_addr(img_ptr, &board->bpp, &board->bar_width,
	&board->endian);
	while (y <= 25)
	{
		while (x < 200)
		{
			board->color = x < own_share ? 0XFF9900 : 0X9580FF;
			img_data[y * 200 + x] = board->color;
			x++;
		}
		x = 0;
		y++;
	}
	mlx_put_image_to_window(board->mlx, board->win, img_ptr, 600, 100);
}

void	get_final_result(t_board *board, char *line, int i)
{
	while (!ft_isdigit(line[i]))
		i++;
	if (board->player == -1)
		board->own_result = ft_atoi(&(line[i]));
	else
		board->enemy_result = ft_atoi(&(line[i]));
	i = 0;
	free(line);
	get_next_line(0, &line);
	while (!ft_isdigit(line[i]))
		i++;
	if (board->player == -2)
		board->own_result = ft_atoi(&(line[i]));
	else
		board->enemy_result = ft_atoi(&(line[i]));
	free(line);
	board->stop = 1;
}
