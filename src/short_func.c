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
	ANG = 90;
	if ((SDL_Init(SDL_INIT_EVERYTHING)) == -1)
	return (ft_error(NULL, NULL, "Cannot init SDL"));
	S->window = SDL_CreateWindow
	("test", 500, 300, WIDTH, HEIGHT, 0);
	S->renderer = SDL_CreateRenderer(S->window, -1, SDL_RENDERER_ACCELERATED);
	SDL_RenderSetLogicalSize(S->renderer, WIDTH, HEIGHT);
	SDL_SetRenderDrawColor(S->renderer, 255, 128, 0, 255);
	return (0);
}

int			draw_ray(double length, int i)
{
	int 	x;
	double	wh;
	int		z;

	ft_putstr(KMAG);
	wh = WALL / length * DIST;
	z = (HEIGHT / 2) - (wh / 2);
	x = 0;
//	z = 300;

	SDL_SetRenderDrawColor(S->renderer, 255, 255, 0, 255); //YELLOW
	while (x < z)
	{
		SDL_RenderDrawPoint(S->renderer, i, x);
		x++;
	}
	SDL_SetRenderDrawColor(S->renderer, 0, 128, 0, 255); // GREEN
	z = (HEIGHT / 2) + (wh / 2);//DRAW WALL
//	z = 500;
		while (x < z)
	{
		SDL_RenderDrawPoint(S->renderer, i, x);
		x++;
	}
	SDL_SetRenderDrawColor(S->renderer, 255, 100, 205, 255); // PINK
		while (x < WIDTH)
	{
		SDL_RenderDrawPoint(S->renderer, i, x);
		x++;
	}
	return (0);
}