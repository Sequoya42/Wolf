/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/14 20:25:02 by rbaum             #+#    #+#             */
/*   Updated: 2015/05/14 20:25:05 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void		aff_map_term(void)
{
	ft_putnbrn(S->map_height);
	ft_putnbrn(S->map_width);
		int i = 0;
	int j = 0;
	ft_putchar('\n');
	while (i < S->map_height)
	{
		j = 0;
		while (j < S->map_width)
		{
			ft_putnbrn(S->map[i][j]);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}