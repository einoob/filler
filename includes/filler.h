/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elindber <elindber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 13:26:42 by elindber          #+#    #+#             */
/*   Updated: 2020/03/11 19:02:29 by elindber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include <unistd.h>
# include <stdlib.h>
# include "../libftprintf/includes/ft_printf.h"
# include "../libftprintf/includes/get_next_line.h"
# include "../libftprintf/libft/libft.h"

typedef struct s_piece
{
	char		**piece;
	int			height;
	int			width;
	int			first_x;;
	int			last_x;
	int			first_y;
	int			last_y;
}				t_piece;


typedef struct	s_info
{
	char		**map;
	int			player;
	int			height;
	int			width;
	int			own[2];
	int			enemy[2];
}				t_info;

int				read_output(t_info *info, int x);

#endif