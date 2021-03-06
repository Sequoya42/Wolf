/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/12 22:31:44 by rbaum             #+#    #+#             */
/*   Updated: 2015/06/12 22:31:46 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

t_color		cren(double y, t_color c, t_color s, t_wolf *t)
{
	double	cren;
	t_color	f;

	if (t->cren == 0)
		return (s);
	cren = (y - (double)(int)y);
	cren *= 100;
	f.r = (s.r * (cren) / 100) + ((c.r * (100 - cren)) / 100);
	f.g = (s.g * (cren) / 100) + ((c.g * (100 - cren)) / 100);
	f.b = (s.b * (cren) / 100) + ((c.b * (100 - cren)) / 100);
	return (f);
}

void		draw_ceiling(t_wolf *t, double y, int x)
{
	double	i;
	t_color	s;
	t_color s2;
	t_color	f;
	int		m;

	i = 0;
	m = (t->trip == 0) ? t->wh : 100;
	s = set_color(44, 47, 94);
	s2 = set_color(255, 255, 255);
	while (i < y - 1)
	{
		t->p[(x + ((int)i * 800))] = couleur(s.r, s.g, s.b, m);
		i++;
	}
	f = (t->test == 0 || t->test2 == 0) ?
	cren(y, t->c, s, t) : cren(y, s2, s, t);
	t->p[(x + ((int)i * 800))] = couleur(f.r, f.g, f.b, m);
}

void		draw_walls(t_wolf *t, int x, t_color s)
{
	t_color	f;
	double	z;
	double	y;
	int		m;

	m = (t->trip == 0) ? t->wh : 100;
	z = ((HEIGHT / 2) + (t->wh / 2));
	y = (HEIGHT / 2) - ((int)t->wh / 2);
	y = (y < 0) ? 0 : y;
	while (y < 800 && y < z - 2)
	{
		if ((t->dx < t->dy) ? t->test == 1 : t->test2 == 1)
			t->p[(x + ((int)y * 800))] = couleur(0, 0, 0, m);
		else if ((t->dx < t->dy) ? t->test == 2 : t->test2 == 2)
		{
			f = set_color(255, 255, 255);
			f = cren(z, t->c, f, t);
			t->p[(x + ((int)y * 800))] = couleur(f.r, f.g, f.b, m);
		}
		else
			t->p[(x + ((int)y * 800))] = couleur(t->c.r, t->c.g, t->c.b, m);
		y++;
	}
	f = cren(z, s, t->c, t);
	t->p[(x + ((int)y * 800))] = couleur(f.r, f.g, f.b, m);
}

void		draw_floor(t_wolf *t, int x, double z, t_color s)
{
	t_color f;
	t_color	tmp;
	int		m;

	m = (t->trip == 0) ? (t->wh / 4) : 100;
	tmp = set_color(11, 255, 255);
	if (t->neon && z < 600)
	{
		f = cren(z, tmp, t->c, t);
		t->p[(x + ((int)z * 800))] = couleur(f.r, f.g, f.b, 100);
		z++;
		t->p[(x + ((int)z * 800))] = couleur(tmp.r, tmp.g, tmp.b, 100);
		z++;
		f = cren(z, s, tmp, t);
		t->p[(x + ((int)z * 800))] = couleur(f.r, f.g, f.b, 100);
		z++;
	}
	while (z < 600)
	{
		t->p[(x + ((int)z * 800))] = couleur(s.r, s.g, s.b, m);
		z++;
	}
}

void		draw_ray(int x, t_wolf *t)
{
	double	y;
	double	z;
	t_color s;

	t->c = choose_color(t->dx, t->dy, t);
	s = set_color(0, 36, 17);
	t->wh = (t->dx < t->dy) ? t->dx : t->dy;
	t->c = shad(t->c, t->wh);
	t->wh = (WALL / t->wh) * DIST;
	y = (HEIGHT / 2) - (t->wh / 2);
	z = ((HEIGHT / 2) + (t->wh / 2));
	if (t->text == 0 || y <= 0)
		draw_ceiling(t, y, x);
	else
		textured_ceiling(t, x);
	if (t->text == 0)
		draw_walls(t, x, s);
	else
		textured_wall(t, x, z);
	if (t->text == 0 || z >= 600)
		draw_floor(t, x, z, s);
	else
		textured_floor(t, x);
}
