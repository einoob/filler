/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_output.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elindber <elindber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/02 13:48:57 by elindber          #+#    #+#             */
/*   Updated: 2020/06/08 12:52:31 by elindber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"

void	out_of_moves(char *line)
{
	while (get_next_line(0, &line))
	{
		if (ft_strstr(line, "Plateau"))
		{
			free(line);
			get_next_line(0, &line);
			free(line);
			return ;
		}
		free(line);
	}
}

void	check_game_end(t_board *board)
{
	char	*line;

	while (get_next_line(0, &line))
	{
		if (ft_strstr(line, "<got"))
		{
			free(line);
			get_next_line(0, &line);
			if (ft_strstr(line, "fin:"))
				get_final_result(board, line, 0);
			else if (ft_strstr(line, "Plateau"))
			{
				free(line);
				get_next_line(0, &line);
				free(line);
			}
			else
			{
				free(line);
				out_of_moves(line);
			}
			return ;
		}
		free(line);
	}
}

int		dup_board(t_board *board, int y)
{
	char	*line;

	while (y < board->height && get_next_line(0, &line))
	{
		if (!(board->board[y] = ft_strsub(line, 4, board->width)))
			return (0);
		free(line);
		y++;
	}
	board->board[y] = NULL;
	check_game_end(board);
	if (board->player < 0)
		return (1);
	board->own_char = board->player == 1 ? "Oo" : "Xx";
	board->enemy_char = board->player == 1 ? "Xx" : "Oo";
	board->player = board->player == 1 ? -1 : -2;
	set_start_values(board);
	return (1);
}

void	get_board_size(t_board *board, char *line, int x)
{
	while (!(ft_isdigit(line[x])))
		x++;
	board->height = ft_atoi(&(line[x]));
	x += ft_nbrcount(board->height) + 1;
	board->width = ft_atoi(&(line[x]));
}

int		read_output(t_board *board, int x)
{
	char	*line;

	if (board->height != 0)
	{
		x = re_allocate(board) == 1 ? 1 : 0;
		return (x);
	}
	while (get_next_line(0, &line) && board->height == 0)
	{
		if (ft_strstr(line, "elindber.filler"))
			board->player = ft_strstr(line, "p1") ? 1 : 2;
		if (ft_strstr(line, "Plateau"))
		{
			get_board_size(board, line, x);
			if (!(board->board =
			(char**)malloc(sizeof(char*) * (board->height + 1))))
				return (0);
			free(line);
			get_next_line(0, &line);
			free(line);
			break ;
		}
		free(line);
	}
	return (1);
}
