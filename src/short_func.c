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

t_wolf		*singleton(void)
{
	static t_wolf wolf;

	return (&wolf);
}

int		ft_init(t_wolf *t)
{
//	ft_bzero(t, 1 * sizeof(t_wolf));
	ANG = 90.4;
	if ((SDL_Init(SDL_INIT_EVERYTHING)) == -1)
	return (ft_error(NULL, NULL, "Cannot init SDL"));
	t->window = SDL_CreateWindow
	("test", 500, 300, WIDTH, HEIGHT, 0);
	t->renderer = SDL_CreateRenderer(t->window, -1, SDL_RENDERER_ACCELERATED);
	SDL_RenderSetLogicalSize(t->renderer, WIDTH, HEIGHT);
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

t_color		choose_color(double dx, double dy, t_wolf *t)
{
	t_color c;
	if (dx < dy && ALPHA >= 0 && ALPHA < 180)
		c = set_color(138, 43, 226);//blue violet
	else if (dx < dy && ALPHA >= 180 && ALPHA < 360)
		c = set_color(165, 42, 42); // brown red
	else if (dy < dx && ALPHA >= 90  && ALPHA < 270)
		c = set_color(205, 173, 0); // gold 3
	else //if (dy > dx && (ALPHA >= 270 || ALPHA < 90))
		c = set_color(85, 107, 47);// green olive
	// if (dx < dy)
	// 	c = set_color(85, 107, 47);// green olive
	// else
 // 		c = set_color(205, 173, 0); // gold 3
	return (c);

}

int			draw_ray(double dx, double dy, int x, t_wolf *t)
{
	t_color	c;
	double 	y;
	double	wh;
	double	z;

	ft_putstr(KMAG);
	wh = dx < dy ? (WALL / dx) : (WALL / dy);
	// dx < dy ? ft_putendl(KCYN) : ft_putendl(KGRN);
	// printf("dx: %f\t\tdy: %f\n", dx, dy);
	// ft_putendl(KNRM);
	wh *= DIST;
	 y = (HEIGHT / 2) - (wh / 2);
	 c = choose_color(dx, dy, t);
 	SDL_SetRenderDrawColor(t->renderer, c.r, c.g, c.b, 255);
	z = ((HEIGHT / 2) + (wh / 2));
	while (y < z)
	{
		SDL_RenderDrawPoint(t->renderer, x, y);
		y += 1;
	}
	SDL_SetRenderDrawColor(t->renderer, 0, 102, 0, 255);
	while (y < WIDTH)
	{
	SDL_RenderDrawPoint(t->renderer, x, y);
		y += 1;
	}
	 SDL_SetRenderDrawColor(t->renderer, 0, 191, 255, 255);
	return (0);
}