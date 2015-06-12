/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/12 22:31:30 by rbaum             #+#    #+#             */
/*   Updated: 2015/06/12 22:34:26 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void		rotate(t_wolf *t)
{
	if (t->keystate[SDL_SCANCODE_RIGHT])
	{
		ANG -= 1.4;
		while (ANG < 0)
			ANG += 360;
	}
	else if (t->keystate[SDL_SCANCODE_LEFT])
	{
		ANG += 1.4;
		while (ANG >= 360)
			ANG -= 360;
	}
	if (t->keystate[SDL_SCANCODE_W] && t->height < 1000)
		t->height += 5;
	if (t->keystate[SDL_SCANCODE_Q] && t->height > 600)
		t->height -= 5;
}

void		move(t_wolf *t, int ix, int iy)
{
	if (t->keystate[SDL_SCANCODE_UP])
	{
		if (t->map[((int)(POSY / WALL))][PX] != 1)
			POSX += ix;
		if (t->map[PY][((int)(POSX / WALL))] != 1)
			POSY -= iy;
	}
	else if (t->keystate[SDL_SCANCODE_DOWN])
	{
		if (t->map[((int)(POSY / WALL))][PX2] != 1)
			POSX -= ix;
		if (t->map[PY2][((int)(POSX / WALL))] != 1)
			POSY += iy;
	}
	change_map(t);
}

void		teleport(t_wolf *t)
{
	int x;
	int y;

	while (1)
	{
		POSX = rand() % MW * WALL;
		POSY = rand() % MH * WALL;
		y = (int)(POSX / WALL);
		x = (int)(POSY / WALL);
		if (t->map[x][y] == 0
			&& (t->map[x + 1][y + 1] == 0)
			&& (t->map[x + 1][y] == 0)
			&& (t->map[x][y + 1] == 0)
			&& (t->map[x - 1][y - 1] == 0)
			&& (t->map[x - 1][y] == 0)
			&& (t->map[x][y - 1] == 0)
			&& (t->map[x + 1][y - 1] == 0)
			&& (t->map[x - 1][y + 1] == 0))
			break ;
	}
}

void		trip(t_wolf *t)
{
	if (KEY == SDLK_p)
		teleport(t);
	if (KEY == SDLK_c)
		t->cren = (t->cren == 0) ? 1 : 0;
	if (KEY == SDLK_t)
		t->text = (t->text == 0) ? 1 : 0;
}

void		key_events(t_wolf *t, int ix, int iy)
{
	(void)ix;
	(void)iy;
	if (t->event.type == SDL_KEYDOWN)
	{
		if (KEY == 27)
		{
			SDL_DestroyWindow(t->window);
			SDL_Quit();
			exit(1);
		}
		if (KEY == SDLK_s && PYN < MH && PXN < MW && PYN > 0 && PXN > 0)
			if (t->map[PYN][PXN] == 0)
				t->map[PYN][PXN] = 2;
		if (KEY == SDLK_d && PYN < MH && PXN < MW && PYN > 0 && PXN > 0)
			if (t->map[PYN][PXN] == 0)
				t->map[PYN][PXN] = 3;
		if (KEY == SDLK_n)
			t->neon = (t->neon == 0) ? 1 : 0;
		trip(t);
	}
}
