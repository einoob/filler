/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elindber <elindber@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 15:37:14 by elindber          #+#    #+#             */
/*   Updated: 2020/03/27 14:28:26 by elindber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void	piece_values(t_piece *piece, int x, int y, int last_x)
{
	int		first_x;
	int		first_y;

	first_x = piece->width - 1;
	first_y = -1;
	while (piece->piece[y] != NULL)
	{
		while (piece->piece[y][x] != '\0')
		{
			if (piece->piece[y][x] == '*' && first_y < 0)
				first_y = y;
			if (piece->piece[y][x] == '*' && first_x > x)
				first_x = x;
			if (piece->piece[y][x] == '*' && last_x < x)
				last_x = x;
			if (piece->piece[y][x] == '*')
				piece->last_y = y;
			x++;
		}
		x = 0;
		y++;
	}
	piece->first_x = first_x;
	piece->last_x = last_x;
	piece->first_y = first_y;
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

int		read_piece(t_piece *piece, int x)
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
	dup_piece(piece, 0);
	piece_values(piece, 0, 0, 0);
	return (1);
}

int		dup_board(t_info *info, int y)
{
	char	*line;

	get_next_line(0, &line);
//	free(line);
	while (y < info->height && get_next_line(0, &line))
	{
		if (!(info->map[y] = ft_strsub(line, 4, info->width)))
			return (0);
		free(line);
		y++;
	}
	info->map[y] = NULL;
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
			if (!(info->map =
			(char**)malloc(sizeof(char*) * (info->height + 1))))
				return (0);
			free(line);
			break ;
		}
		free(line);
	}
	if (!(dup_board(info, 0)) || !(read_piece(piece, 0)))
		return (0);
	get_positions(info, 0, 0);
	reach_enemy(info, piece, 0, 0);
	return (1);
}

/*
	ft_printf("ph:%d pw:%d\n", piece->height, piece->width);
	ft_printf("fy:%d ly:%d fx:%d lx:%d\n", piece->first_y, piece->last_y, piece->first_x, piece->last_x);
	int	i = 0;
	while (i < piece->height)
	{
		ft_printf("%s\n", piece->piece[i]);
		i++;
	}
**
	ft_printf("mh:%d mw:%d\n", info->height, info->width);
	ft_printf("player:%d\n", info->player);
	int i = 0;
	while (i < info->height)
	{
		ft_printf("%s\n", info->map[i]);
		i++;
	}
*/
