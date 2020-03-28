/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elindber <elindber@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 13:50:16 by elindber          #+#    #+#             */
/*   Updated: 2020/03/27 19:22:49 by elindber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"
#include <fcntl.h>

int		main(void)
{
	t_info	*info;
	t_piece *piece;
	
	if (!(info = (t_info*)malloc(sizeof(t_info)))
	|| !(piece = (t_piece*)malloc(sizeof(t_piece))))
		return (-1);
	while (1)
	{
		read_output(info, piece, 0);
		if (info->stop)
			break ;
		//	free(info->map);
	}
//	free(piece);
//	free(info);
	return (0);
}
