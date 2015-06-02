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

void		draw_ceiling(t_wolf *t, t_color s, int y, int x)
{
	int 	i;

	i = 0;
		s = set_color(44, 47, 94);
	while (i++ < y)
		 t->p[(x + (i * t->trip3))] = couleur(s.r, s.g, s.b, 100);
}

void		draw_walls(t_wolf *t, t_color c, int x, int wh)
{
	int z;
	int y;
	int m;

	m = shade(t, wh);
	z = ((HEIGHT / 2) + (wh / 2));
	y = (HEIGHT / 2) - (wh / 2);
	y = (y < 0) ? 0 : y;
	while (y < t->trip3 && y < z)
	{
		t->p[(x + (y * t->trip3))] = couleur(c.r , c.g, c.b,m);
		y += sin(3 * (M_PI / 4)) + t->trip2;
	}
}

void		draw_floor(t_wolf *t, t_color s, int x, int z)
{
	int i = 0;

	while (z < t->trip3)
	{
		s = set_color(102, 51, 0);
		if (i == 0)
			s = set_color(100, 47, 0);
		if (i < 2)
		s = set_color(88, 44, 0);
		t->p[(x + (z * t->trip3))] = couleur(s.r, s.g, s.b, 1);
		z++;
		i++;
	}

}
void		draw_ray(double dx, double dy, int x, t_wolf *t)
{
	t_color	c;
	t_color	s;
	double	wh;
	int 	y;
	int		z;

	c = choose_color(dx, dy, t);
	wh = (dx < dy) ? dx : dy;
	c = shad(c, wh);
	wh = (WALL / wh) * DIST;
	y = (HEIGHT / 2) - (wh / 2);
	z = ((HEIGHT / 2) + (wh / 2));
	draw_ceiling(t, s, y, x);
	draw_walls(t, c, x , wh);
	draw_floor(t, s, x, z);
}