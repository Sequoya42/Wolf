/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/15 18:51:17 by rbaum             #+#    #+#             */
/*   Updated: 2015/05/15 18:51:17 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void		move_right(void)
{
	if (KEY == SDLK_RIGHT)
	{
		ANG -= 5;
		while (ANG < 0)
			ANG += 360;

	}
}

void		move_left(void)
{
	if (KEY == SDLK_LEFT)
	{
		ANG += 5;
		while (ANG >= 360)
			ANG -= 360;
	}
}

void		move_backward(int inc)
{
	int	ix;
	int	iy;

	ix = cos(ANG D) * inc;
	iy = sin(ANG D) * inc;
	iy *= -1;
	if (KEY == SDLK_UP)// && MOVEDW && MOVEUP)
	{
		POSX += ix;
		POSY += iy;
	} 
}

void		move_forward(int inc)
{
	int	ix;
	int	iy;

	ix = cos(ANG D) * inc;
	ix *= -1;
	iy = sin(ANG D) * inc;
	if (KEY == SDLK_DOWN)// && MOVEUP && MOVEDW)
	{
		POSX += ix;
		POSY += iy;
	}
}



void		key_events(void)
{
	int inc;

	inc = 20;
	if (S->event.type == SDL_KEYDOWN)
	{
		if (S->event.key.keysym.sym == 27)
		{
			SDL_DestroyWindow(S->window);
			SDL_Quit();
			exit(1);
		}
		move_right();
		move_left();
		move_forward(inc);
		move_backward(inc);
	}
}

