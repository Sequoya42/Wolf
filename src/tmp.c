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
//	X = 0;
//	Y = 0;
	int x = 0;
	int y = 0;
	ft_putchar('\n');
	while (y < MH)
	{
		x = 0;
		while (x < MW)
		{
		//	ft_putnbrn(VALUE);
			ft_putnbrn(S->map[y][x]);
			x++;
		}
		ft_putchar('\n');
		y++;
	}
}
void		test_rendering(void)
{
	SDL_SetRenderDrawColor(S->renderer, 255, 128, 0, 255);
	SDL_RenderClear(S->renderer);
	SDL_SetRenderDrawColor(S->renderer, 0, 0, 255, 255);
	SDL_RenderFillRect(S->renderer, &S->rect);
	SDL_RenderPresent(S->renderer);
}