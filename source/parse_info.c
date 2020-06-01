/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elindber <elindber@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 15:37:14 by elindber          #+#    #+#             */
/*   Updated: 2020/05/29 16:50:25 by elindber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void	piece_values(t_info *info, t_piece *piece, int x, int y)
{
	int		first_x;

	first_x = piece->width - 1;
	while (piece->piece[y] != NULL)
	{
		while (piece->piece[y][x] != '\0')
		{
			if (piece->piece[y][x] == '*' && piece->y_start > 0)
				piece->y_start = 0 - y;
			if (piece->piece[y][x] == '*' && first_x > x)
				first_x = x;
			if (piece->piece[y][x] == '*' && piece->x_end <= x)
				piece->x_end = info->width - x - 1;
			if (piece->piece[y][x] == '*')
				piece->y_end = info->height - y - 1;
			x++;
		}
		x = 0;
		y++;
	}
	piece->x_start = 0 - first_x;
}

int		dup_piece(t_piece *piece, int y)
{
	char	*line;

	while (y < piece->height && get_next_line(0, &line))
	{
		if (!(piece->piece[y] = ft_strdup(line)))
			return (0);
		free(line);
		y++;
	}
	piece->piece[y] = NULL;
	return (1);
}

int		read_piece(t_info *info, t_piece *piece, int x)
{
	char	*line;

	while (get_next_line(0, &line))
	{
		if (ft_strstr(line, "Piece"))
		{
			while (!(ft_isdigit(line[x])))
				x++;
			piece->height = ft_atoi(&(line[x]));
			x += ft_nbrcount(piece->height) + 1;
			piece->width = ft_atoi(&(line[x]));
			if (!(piece->piece =
			(char**)malloc(sizeof(char*) * (piece->height + 1))))
				return (0);
			free(line);
			break ;
		}
		free(line);
	}
	if (!dup_piece(piece, 0))
		return (0);
	piece_values(info, piece, 0, 0);
	return (1);
}

int		dup_board(t_info *info, int y)
{
	char	*line;

	get_next_line(0, &line);
	free(line);
	while (y < info->height && get_next_line(0, &line))
	{
		if (!(info->board[y] = ft_strsub(line, 4, info->width)))
			return (0);
		free(line);
		y++;
	}
	info->board[y] = NULL;
	return (1);
}

int		read_output(t_info *info, t_piece *piece, int x)
{
	char	*line;

	while (get_next_line(0, &line))
	{
		if (ft_strstr(line, "elindber.filler"))
			info->player = ft_strstr(line, "p1") ? 1 : 2;
		if (ft_strstr(line, "Plateau"))
		{
			while (!(ft_isdigit(line[x])))
				x++;
			info->height = ft_atoi(&(line[x]));
			x += ft_nbrcount(info->height) + 1;
			info->width = ft_atoi(&(line[x]));
			if (!(info->board =
			(char**)malloc(sizeof(char*) * (info->height + 1))))
				return (0);
			free(line);
			break ;
		}
		free(line);
	}
	if (!(dup_board(info, 0)) || !(read_piece(info, piece, 0)))
		return (0);
	return (1);
}
