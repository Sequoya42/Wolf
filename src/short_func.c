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
	S->xmov = 0;
	S->ymov = 0;
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
	double 	x;
	double	wh;
	double	z;

	ft_putstr(KMAG);
	wh = WALL / length * DIST;
	 x = (HEIGHT / 2) - (wh / 2);

	// SDL_SetRenderDrawColor(S->renderer, 255, 255, 0, 255); //YELLOW
	// while (x < z)
	// {
	// 	SDL_RenderDrawPoint(S->renderer, i, x);
	// 	x += 0.10;
	// }
	SDL_SetRenderDrawColor(S->renderer, 0, 128, 0, 255); // GREEN
	z = ((HEIGHT / 2) + (wh / 2));//DRAW WALL
	ft_putendl(KGRN);
		 printf("\t\twh = %f\t\tx = %f\t\tz = %f\n", wh, x, z);
//	printf("%f\t\t%f\n", x, z);
	while (x < z)
	{
		SDL_RenderDrawPoint(S->renderer, i, x);
		x += 1;
	}
	 SDL_SetRenderDrawColor(S->renderer, 255, 250, 205, 255); // PINK
	// while (x < WIDTH)
	// {
	// 	SDL_RenderDrawPoint(S->renderer, i, x);
	// 	x += 0.10;
	// }
	return (0);
}