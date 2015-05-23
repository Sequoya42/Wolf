/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/16 17:56:09 by rbaum             #+#    #+#             */
/*   Updated: 2015/05/16 17:56:13 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

t_wolf		*singleton(void)
{
	static t_wolf wolf;

	return (&wolf);
}

int		ft_init(void)
{
	ft_bzero(S, 1 * sizeof(t_wolf));
	ANG = 45.0;
	if ((SDL_Init(SDL_INIT_EVERYTHING)) == -1)
	return (ft_error(NULL, NULL, "Cannot init SDL"));
	S->window = SDL_CreateWindow
	("test", 500, 300, WIDTH, HEIGHT, 0);
	S->renderer = SDL_CreateRenderer(S->window, -1, SDL_RENDERER_ACCELERATED);
	SDL_RenderSetLogicalSize(S->renderer, WIDTH, HEIGHT);
	return (0);
}

t_color		set_color(char r, char g, char b)
{
	t_color		c;

	c.r = r;
	c.g = g;
	c.b = b;
	return (c);
}

t_color		choose_color(void)
{
	t_color c;
	if (ALPHA >= 45 && ALPHA < 135)
		c = set_color(138, 43, 226);
	else if (ALPHA >= 135 && ALPHA < 225)
		c = set_color(165, 42, 42);
	else if (ALPHA >=225 && ALPHA <= 315)
		c = set_color(205, 173, 0);
	else
		c = set_color(85, 107, 47);
	return (c);
}

int			draw_ray(double length, int x)
{
	t_color	c;
	double 	y;
	double	wh;
	double	z;

	ft_putstr(KMAG);
	wh = (double)(WALL / length);
	wh *= DIST;
	 y = (HEIGHT / 2) - (wh / 2);
	 c = choose_color();
 	SDL_SetRenderDrawColor(S->renderer, c.r, c.g, c.b, 255);
	z = ((HEIGHT / 2) + (wh / 2));
	while (y < z)
	{
		SDL_RenderDrawPoint(S->renderer, x, y);
		y += 1;
	}
	 SDL_SetRenderDrawColor(S->renderer, 0, 191, 255, 255);
	return (0);
}