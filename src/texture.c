/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/12 23:49:18 by rbaum             #+#    #+#             */
/*   Updated: 2015/06/13 00:12:56 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

double			start_value(t_wolf *t)
{
	double		start;

	start = 0.0;
	if (t->wh >= 600)
	{
		start = ((int)t->wh - 600) / 2;
		start = (start / t->wh);
		start = t->sw->h * start;
	}
	return (start);
}

void			textured_wall(t_wolf *t, int x, double z)
{
	double		y;
	double		i;
	Uint32		**img;
	int			offset;
	double		inc;

	y = (HEIGHT / 2) - ((int)t->wh / 2);
	y = (y < 0) ? 0 : y;
	offset = (t->dx > t->dy) ?
		(abs((int)(t->ryv)) % (int)WALL) : (abs((int)(t->rxh)) % (int)WALL);
	img = (Uint32**)(t->sw->pix);
	i = start_value(t);
	inc = (double)t->sw->h / t->wh;
	while (y < 600 && y < z - 2)
	{
		t->p[x + ((int)y * 800)] =
			img[(int)i % t->sw->h][offset % t->sw->w];
		i += inc;
		y++;
	}
}

void			init_floor(t_floor *f, t_wolf *t)
{
	f->sinus = sin(ALPHA * D);
	f->cosinus = cos(ALPHA * D);
	f->angle = cos((ALPHA - ANG) * D);
}

void			textured_floor(t_wolf *t, int x)
{
	t_floor		f;

	init_floor(&f, t);
	f.img = (Uint32**)(t->sf->pix);
	f.img2 = (Uint32**)(t->st->pix);
	f.img3 = (Uint32**)(t->sd->pix);
	f.z = ((HEIGHT / 2) + (t->wh / 2));
	while (f.z < HEIGHT)
	{
		f.tro = ((double)f.z - (HEIGHT / 2));
		f.dp = (WALL / 2) / f.tro * DIST / f.angle;
		f.dy = -f.dp * f.sinus + POSY;
		f.dx = f.dp * f.cosinus + POSX;
		f.tx = (int)f.dx / (int)WALL;
		f.ty = (int)f.dy / (int)WALL;
		if (f.tx > 0 && f.ty > 0 && f.tx < MW && f.ty < MH && VAL == 2)
			t->p[x + (int)f.z * 800] = f.img2[TX][TY];
		else if (f.tx > 0 && f.ty > 0 && f.tx < MW && f.ty < MH && VAL == 3)
			t->p[x + (int)f.z * 800] = f.img3[TX][TY];
		else
			t->p[x + (int)f.z * 800] = f.img[TX][TY];
		f.z++;
	}
}

void			textured_ceiling(t_wolf *t, int x)
{
	t_floor		f;

	init_floor(&f, t);
	f.img = (Uint32**)(t->sc->pix);
	f.img2 = (Uint32**)(t->st->pix);
	f.img3 = (Uint32**)(t->sd->pix);
	f.z = (HEIGHT / 2) - ((int)t->wh / 2);
	f.tro = t->wh / 2;
	while (f.z > 0)
	{
		f.dp = (WALL / 2) / f.tro * DIST / f.angle;
		f.dy = -f.dp * f.sinus + POSY;
		f.dx = f.dp * f.cosinus + POSX;
		f.tx = (int)f.dx / (int)WALL;
		f.ty = (int)f.dy / (int)WALL;
		if (f.tx > 0 && f.ty > 0 && f.tx < MW && f.ty < MH && VAL == 2)
			t->p[x + (int)f.z * 800] = f.img2[TX][TY];
		else if (f.tx > 0 && f.ty > 0 && f.tx < MW && f.ty < MH && VAL == 3)
			t->p[x + (int)f.z * 800] = f.img3[TX][TY];
		else
			t->p[x + (int)f.z * 800] = f.img[TX][TY];
		f.tro++;
		f.z--;
	}
}
