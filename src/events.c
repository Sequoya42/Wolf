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
	if (t->keystate[SDL_SCANCODE_W] && t->height < 1000)
		t->height += 5;
	if (t->keystate[SDL_SCANCODE_Q] && t->height > 200)
		t->height -= 5;
}

void		look_away(t_wolf *t)
{
	if (KEY == SDLK_n)
		t->neon = (t->neon == 0) ? 1 : 0;
}

void		move(t_wolf *t, int ix, int iy)
{

	if (t->keystate[SDL_SCANCODE_UP])
	{
		if (t->map[((int)POSY / 64)][PX] != 1)
			POSX += ix;
		if (t->map[PY][((int)POSX / 64)] != 1)
			POSY -= iy;
	}
	else if (t->keystate[SDL_SCANCODE_DOWN])
	{
		if (t->map[((int)POSY / 64)][PX2] != 1)
			POSX -= ix;
		if (t->map[PY2][((int)POSX / 64)] != 1)
			POSY += iy;
	}
}

void		teleport(t_wolf *t)
{
	int x;
	int y;

	if (KEY == SDLK_p)
	{
		while (1)
		{
			POSX = rand() % MW * 64;
			POSY = rand() % MH * 64;
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
			break;
		}
		printf("x: %d\t\ty: %d\n", x, y);
	}
}
void		trip(t_wolf *t)
{
	teleport(t);
	if (KEY == SDLK_t)
		t->trip = (t->trip == 0) ? 1 : 0;
}

void		key_events(t_wolf *t)
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
		look_away(t);
	}
}
