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

void		rotate(t_wolf *t)
{
	if (t->keystate[SDL_SCANCODE_RIGHT])
	{
		ANG -= 2.1;
		while (ANG < 0)
			ANG += 360;
	}
	else if (t->keystate[SDL_SCANCODE_LEFT])
	{
		ANG += 2.1;
		while (ANG >= 360)
			ANG -= 360;
	}
}

void		move(t_wolf *t, int ix, int iy)
{

	if (t->keystate[SDL_SCANCODE_UP])
	{
		if (t->map[PY][PX] != 1)
			POSX += ix;
		if (t->map[PY][PX] != 1)
			POSY -= iy;
	}
	else if (t->keystate[SDL_SCANCODE_DOWN] && MOVEDW)
	{
		if (t->map[((int)POSY / 64)][PX] != 1)
			POSX -= ix;
		if (t->map[PY][((int)POSX / 64)] != 1)
			POSY += iy;
	}
}

void		trip(t_wolf *t)
{
	if (KEY == SDLK_p)
	{
		POSX = 4 * 64;
		POSY = 4 * 64;
	}
	if (KEY == SDLK_t)
		t->trip = (t->trip == 0) ? 1 : 0;
	if (KEY == SDLK_r)
		t->trip2 = (t->trip2 == 1) ? 8 : 1;
	if (KEY == SDLK_i)
		t->trip3 = (t->trip3 == 800) ? 600: 800;
	if (KEY == SDLK_c)
		t->choose = (t->choose == 0) ? 1 : 0;
}

void		key_events(t_wolf *t)//, int ix, int iy)
{
	if (t->event.type == SDL_KEYDOWN)
	{
		if (KEY == 27)
		{
			SDL_DestroyWindow(t->window);
			SDL_Quit();
			exit(1);
		}
		trip(t);
	}
}

