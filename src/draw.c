/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/31 14:52:53 by rbaum             #+#    #+#             */
/*   Updated: 2015/05/31 14:52:57 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

t_color		cren(double y, t_color c, t_color s, t_wolf *t)
{
	if (t->cren == 0)
		return (s);
	double	cren;
	t_color	f;

	cren = (y - (double)(int)y);
	cren *= 100;
	f.r = (s.r * (cren) / 100) + ((c.r * (100 - cren)) / 100);
	f.g = (s.g * (cren) / 100) + ((c.g * (100 - cren)) / 100);
	f.b = (s.b * (cren) / 100) + ((c.b * (100 - cren)) / 100);
	return (f);
}

void		draw_ceiling(t_wolf *t, double y, int x)
{
	double 	i;
	t_color	s;
	t_color	f;

	i = 0;
	s = set_color(44, 47, 94);
	while (i < y - 1)
	{
		 t->p[(x + ((int)i * 800))] = couleur(s.r, s.g, s.b, 100);
		i++;
	}
	f = cren(y, t->c, s, t);
	t->p[(x + ((int)i * 800))] = couleur(f.r, f.g, f.b, 100);
}

void		draw_walls(t_wolf *t, int x, double wh)
{
	t_color f;
	t_color s;
	double z;
	double y;

	s = set_color(0, 112, 0);
	z = ((HEIGHT / 2) + (wh / 2));
	y = (HEIGHT / 2) - ((int)wh / 2);
	y = (y < 0) ? 0 : y;
	while (y < 800 && y < z - 2)
	{
		t->p[(x + ((int)y * 800))] = couleur(t->c.r , t->c.g, t->c.b, 100);
		y++;
	}
	f = cren(z, s, t->c, t);
	t->p[(x + ((int)y * 800))] = couleur(f.r, f.g, f.b, 100);
}

void		draw_floor(t_wolf *t, int x, double z)
{
	t_color s;
	t_color f;
	t_color	tmp;

	s = set_color(0, 112,  0);
	tmp = set_color(11,255,255);
	if (t->neon == 1)
	{
		f = cren(z, t->c, tmp, t);
		t->p[(x + ((int)z * 800))] = couleur(f.r, f.g, f.b, 100);
		z++;
		t->p[(x + ((int)z * 800))] = couleur(tmp.r, tmp.g, tmp.b, 100);
		z++;
		f = cren(z, tmp, s, t);
		t->p[(x + ((int)z * 800))] = couleur(f.r, f.g, f.b, 100);
		z++;
	}
	while (z < 800)
	{
		t->p[(x + ((int)z * 800))] = couleur(s.r, s.g, s.b, 100);
		z++;
	}

}
void		draw_ray(double dx, double dy, int x, t_wolf *t)
{
	double	wh;
	double 	y;
	double	z;

	t->c = choose_color(dx, dy, t);
	wh = (dx < dy) ? dx : dy;
	t->c = shad(t->c, wh);
	wh = (WALL / wh) * DIST;
	y = (HEIGHT / 2) - (wh / 2);
	z = ((HEIGHT / 2) + (wh / 2));
	draw_ceiling(t, y, x);
	if (t->text == 0)
		draw_walls(t, x , wh);
	else
		load_bmp(t, x, wh);
	if (z < WIDTH)
		draw_floor(t, x, z);
}