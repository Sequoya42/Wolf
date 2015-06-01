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

t_color		choose_color(double dx, double dy, t_wolf *t)
{
	t_color c;
	if (dx < dy && ALPHA >= 0 && ALPHA < 180)
		c = set_color(138, 111 , 226);//blue violet
	else if (dx < dy && ALPHA >= 180 && ALPHA < 360)
		c = set_color(165, 42, 42); // brown red
	else if (dy < dx && ALPHA >= 90  && ALPHA < 270)
		c = set_color(205, 117, 0); // gold 3
	else
		c = set_color(0, 102, 124);// mellow blue
	return (c);

}

void		create_new_renderer(t_wolf *t)
{
	t->p = (Uint32 *)malloc(sizeof(Uint32) * WIDTH * HEIGHT);
	t->screen = SDL_CreateTexture(t->renderer, SDL_PIXELFORMAT_ARGB8888,
		SDL_TEXTUREACCESS_STREAMING, WIDTH, HEIGHT);
}

t_color shad(t_color c, double dist)
{
	if (dist > MAX_DISTANCE)
		return (set_color(0, 0, 0));
	c.r = (unsigned char)((double)c.r * (1.0 - (dist / MAX_DISTANCE)));
	c.g = (unsigned char)((double)c.g * (1.0 - (dist / MAX_DISTANCE)));
	c.b = (unsigned char)((double)c.b * (1.0 - (dist / MAX_DISTANCE)));
	return (c);
}

int			draw_ray(double dx, double dy, int x, t_wolf *t)
{
	t_color	c;
	t_color	s;
	double	wh;
	int 	y;
	int		z;
	int		i;
	int		m;

	c = choose_color(dx, dy, t);
	wh = (dx < dy) ? dx : dy;
	c = shad(c, wh);
	s = shad(s, wh);
	m = shade(t, wh);
	wh = (WALL / wh) * DIST;
	y = (HEIGHT / 2) - (wh / 2);
	z = ((HEIGHT / 2) + (wh / 2));
	i = 0;
	s = set_color(44, 47, 94);
	while (i++ < y)
		 t->p[(x + (i * t->trip3))] = couleur(s.r, s.g, s.b, 100);
	y = (y < 0) ? 0 : y;
	while (y < t->trip3 && y < z)
	{
		t->p[(x + (y * t->trip3))] = couleur(c.r , c.g, c.b,m);
		y += sin(3 * (M_PI / 4)) + t->trip2;
	}
	s = set_color(102, 51, 0);
	while (z < t->trip3)
	{
		s = shad(s, z);
		t->p[(x + (z * t->trip3))] = couleur(s.r, s.g, s.b, 1);
		z++;
	}
	return (0);
}