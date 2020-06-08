/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elindber <elindber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/02 12:48:27 by elindber          #+#    #+#             */
/*   Updated: 2020/06/08 16:51:18 by elindber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"

int		key_press(int key, void *param)
{
	t_board *board;

	board = (t_board*)param;
	if (key == 53)
		exit(EXIT_SUCCESS);
	return (0);
}

int		handle_loop(void *param)
{
	t_board	*board;
	char	*result;

	board = (t_board*)param;
	mlx_hook(board->win, 2, 0, key_press, board);
	if (board->stop == 0)
	{
		if (!(re_draw(board)))
			return (0);
	}
	else if (board->stop == 1)
	{
		result = board->own_result > board->enemy_result
		? " YOU WON!" : " YOU LOST :(";
		mlx_string_put(board->mlx, board->win, 500, 100, 0XFF9933, "GAME OVER");
		mlx_string_put(board->mlx, board->win, 802, 100, 0X9580FF, result);
		board->stop++;
		return (0);
	}
	return (1);
}

int		re_draw(t_board *board)
{
	mlx_clear_window(board->mlx, board->win);
	free_board(board, 0);
	if (!(read_output(board, 0)) || !(dup_board(board, 0)))
		return (0);
	visualize_game(board, 0, 0);
	return (1);
}

void	init_game_info(t_board *board)
{
	board->height = 0;
	board->width = 0;
	board->player = 0;
	board->stop = 0;
	board->own_char = NULL;
	board->enemy_char = NULL;
	board->bar_width = 800;
	board->bpp = 32;
	board->endian = 0;
	board->mlx = mlx_init();
	board->win = mlx_new_window(board->mlx, 1400, 1200, "FILLER");
}

int		main(void)
{
	t_board		*board;

	if (!(board = (t_board*)malloc(sizeof(t_board))))
		return (-1);
	init_game_info(board);
	if (!(read_output(board, 0)) || !(dup_board(board, 0)))
		return (-1);
	visualize_game(board, 0, 0);
	mlx_loop_hook(board->mlx, handle_loop, board);
	mlx_loop(board->mlx);
	return (0);
}
