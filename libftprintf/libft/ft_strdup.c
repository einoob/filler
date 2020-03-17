/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elindber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 13:10:35 by elindber          #+#    #+#             */
/*   Updated: 2019/11/12 18:24:51 by elindber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	int		c;
	char	*dst;

	i = 0;
	c = 0;
	while (s1[i])
		i++;
	dst = (char*)ft_memalloc(sizeof(*dst) * (i + 1));
	if (!dst)
		return (NULL);
	while (c < i)
	{
		dst[c] = s1[c];
		c++;
	}
	dst[c] = '\0';
	return (dst);
}
