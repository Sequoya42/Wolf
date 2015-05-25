/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student->42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/16 17:56:09 by rbaum             #+#    #+#             */
/*   Updated: 2015/05/16 17:56:13 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

t_color		set_color(char r, char g, char b)
{
	t_color		c;

	c.r = r;
	c.g = g;
	c.b = b;
	return (c);
}

t_color		choose_color(double dx, double dy, t_wolf *t)
{
	t_color c;
	if (dx < dy && ALPHA >= 0 && ALPHA < 180)
		c = set_color(138, 43, 226);//blue violet
	else if (dx < dy && ALPHA >= 180 && ALPHA < 360)
		c = set_color(165, 42, 42); // brown red
	else if (dy < dx && ALPHA >= 90  && ALPHA < 270)
		c = set_color(205, 173, 0); // gold 3
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

Uint32 couleur(int r, int g, int b)
{ 
	return (((r<<8)+ g)<<8 )+ b; 
}

int			draw_ray(double dx, double dy, int x, t_wolf *t)
{
	t_color	c;
	double	wh;
	int 	y;
	int		z;
	int		i;

	c = choose_color(dx, dy, t);
	wh = (dx < dy) ? dx : dy;
	wh = (WALL / wh) * DIST;
	y = (HEIGHT / 2) - (wh / 2);
	z = ((HEIGHT / 2) + (wh / 2));
	i = 0;
	while (i++ < y)
		 t->p[x + (i * WIDTH)] = couleur(44, 47, 94);
	if (y < 0)
		y = 0;
	while (y < WIDTH && y < z)
		t->p[x + (y++ * WIDTH)] = couleur(c.r, c.g, c.b);
	while (z++ < WIDTH)
		t->p[x + z * WIDTH] = couleur(102, 51, 0);
	return (0);
	// REPLACE WIDTH PER HEIGHT TO OBTAIN DRUGGY MODE
}