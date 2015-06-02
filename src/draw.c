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

void		draw_ceiling(t_wolf *t, t_color c, double y, int x)
{
	double 	i;
	t_color	s;
	t_color	f;

	i = 0;
	s = set_color(44, 47, 94);
	while (i < y - 1)
	{
		 t->p[(x + ((int)i * t->trip3))] = couleur(s.r, s.g, s.b, 100);
		i++;
	}
	double cren = (y - (double)(int)y);
	cren *= 100;
	f.r = (s.r * (cren) / 100) + ((c.r * (100 - cren)) / 100);
	f.g = (s.g * (cren) / 100) + ((c.g * (100 - cren)) / 100);
	f.b = (s.b * (cren) / 100) + ((c.b * (100 - cren)) / 100);
	t->p[(x + ((int)i * t->trip3))] = couleur(f.r, f.g, f.b, 100);
}

void		draw_walls(t_wolf *t, t_color c, int x, double wh)
{
	t_color f;
	t_color s;
	double z;
	double y;

	s = set_color(0, 0, 0);
	z = ((HEIGHT / 2) + (wh / 2));
	y = (HEIGHT / 2) - ((int)wh / 2);
	y = (y < 0) ? 0 : y;
	(void)c;
	while (y < t->trip3 && y < z - 2)
	{
		t->p[(x + ((int)y * t->trip3))] = couleur(c.r , c.g, c.b, 100);
		y++;
	}
	double cren = (z - (double)(int)z);
	cren *= 100;
	f.r = (s.r * (100 - cren) / 100) + ((c.r * (cren)) / 100);
	f.g = (s.g * (100 - cren) / 100) + ((c.g * (cren)) / 100);
	f.b = (s.b * (100 - cren) / 100) + ((c.b * (cren)) / 100);
	t->p[(x + ((int)y * t->trip3))] = couleur(f.r, f.g, f.b, 100);
}

void		draw_floor(t_wolf *t, t_color c, int x, int z)
{
	t_color s;
	// t_color f;
	// double i;

	// i  = 0;
	(void)c;
	int bl = z;
	while (z < t->trip3)
	{
		if (z == bl)
		s = set_color(0,255,255);
	else
			s = set_color(0, 0, 0);
		t->p[(x + ((int)z * t->trip3))] = couleur(s.r, s.g, s.b, 100);
		z++;
		// i++;
	}

}
void		draw_ray(double dx, double dy, int x, t_wolf *t)
{
	t_color	c;
	double	wh;
	double 	y;
	double	z;

	c = choose_color(dx, dy, t);
	wh = (dx < dy) ? dx : dy;
	c = shad(c, wh);
	wh = (WALL / wh) * DIST;
	y = (HEIGHT / 2) - (wh / 2);
	z = ((HEIGHT / 2) + (wh / 2));
	draw_ceiling(t, c, y, x);
	draw_walls(t, c, x , wh);
	draw_floor(t, c, x, z);
}