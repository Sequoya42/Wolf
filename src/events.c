/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student->42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/15 18:51:17 by rbaum             #+#    #+#             */
/*   Updated: 2015/05/15 18:51:17 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void		move_right(t_wolf *t)
{
	if (KEY == SDLK_RIGHT)
	{
		ANG -= 5;
		while (ANG < 0)
			ANG += 360;

	}
}

void		move_left(t_wolf *t)
{
	if (KEY == SDLK_LEFT)
	{
		ANG += 5;
		while (ANG >= 360)
			ANG -= 360;
	}
}

void		move_backward(t_wolf *t, int ix, int iy)
{
	if (KEY == SDLK_UP && MOVEDW)// && MOVEUP)
	{
		POSX += ix;
		POSY -= iy;
	} 
}

void		move_forward(t_wolf *t, int ix, int iy)
{
	if (KEY == SDLK_DOWN && MOVEUP)// && MOVEDW)
	{
		POSX -= ix;
		POSY += iy;
	}
}

void		key_events(t_wolf *t)
{
	int inc;
	int	ix;
	int	iy;

	inc = 20;
	ix = cos(ANG D) * inc;
	iy = sin(ANG D) * inc;
	if (t->event.type == SDL_KEYDOWN)
	{
		if (KEY == 27)
		{
			SDL_DestroyWindow(t->window);
			SDL_Quit();
			exit(1);
		}
		move_right(t);
		move_left(t);
		move_forward(t, ix, iy);
		move_backward(t, ix, iy);
	}
}

