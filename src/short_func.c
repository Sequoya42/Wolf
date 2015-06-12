/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/12 23:47:44 by rbaum             #+#    #+#             */
/*   Updated: 2015/06/12 23:49:07 by rbaum            ###   ########.fr       */
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

Uint32		couleur(int r, int g, int b, int m)
{
	while (m > 255)
		m -= 255;
	return (((((r << 8) + g) << 8) + b) * m / 100);
}

t_color		choose_color(double dx, double dy, t_wolf *t)
{
	t_color c;

	if (dx < dy && ALPHA >= 0 && ALPHA < 180)
		c = set_color(138, 111, 226);
	else if (dx < dy && ALPHA >= 180 && ALPHA < 360)
		c = set_color(165, 42, 42);
	else if (dy < dx && ALPHA >= 90 && ALPHA < 270)
		c = set_color(205, 117, 0);
	else
		c = set_color(0, 102, 124);
	return (c);
}

void		create_new_renderer(t_wolf *t)
{
	t->p = (Uint32*)malloc(sizeof(Uint32) * (WIDTH * HEIGHT));
	t->screen = SDL_CreateTexture(t->renderer, SDL_PIXELFORMAT_ARGB8888,
		SDL_TEXTUREACCESS_STREAMING, WIDTH, HEIGHT);
}

t_color		shad(t_color c, double dist)
{
	if (dist > MAX_DISTANCE)
		return (set_color(0, 0, 0));
	c.r = (unsigned char)((double)c.r * (1.0 - (dist / MAX_DISTANCE)));
	c.g = (unsigned char)((double)c.g * (1.0 - (dist / MAX_DISTANCE)));
	c.b = (unsigned char)((double)c.b * (1.0 - (dist / MAX_DISTANCE)));
	return (c);
}
