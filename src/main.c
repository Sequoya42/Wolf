/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/12 22:16:16 by rbaum             #+#    #+#             */
/*   Updated: 2015/06/12 22:56:10 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int					ft_init(t_wolf *t)
{
	ANG = 90.4;
	t->trip = 1;
	t->neon = 0;
	t->height = 600;
	t->cren = 0;
	t->text = 0;
	t->test = 0;
	srand(time(NULL));
	if ((SDL_Init(SDL_INIT_VIDEO)) == -1)
		return (ft_error(NULL, NULL, "Cannot init SDL"));
	t->window = SDL_CreateWindow
		("Labyrinth", 500, 300, WIDTH, HEIGHT, 0);
	t->renderer = SDL_CreateRenderer(t->window, -1,
									SDL_RENDERER_ACCELERATED);
	t->sw = ft_loadbmp("./bitmap/vang.bmp");
	t->sw2 = ft_loadbmp("./bitmap/dali.bmp");
	t->sf = ft_loadbmp("./bitmap/thewall.bmp");
	t->sc = ft_loadbmp("./bitmap/floor.bmp");
	t->st = ft_loadbmp("./bitmap/damier.bmp");
	t->sd = ft_loadbmp("./bitmap/shroom.bmp");
	SDL_RenderSetLogicalSize(t->renderer, WIDTH, HEIGHT);
	create_new_renderer(t);
	return (0);
}

void				running(t_wolf *t)
{
	unsigned int	ti;
	unsigned int	dif;
	int				inc;
	int				ix;
	int				iy;

	inc = 96;
	t->keystate = SDL_GetKeyboardState(NULL);
	while (inc < 100)
	{
		SDL_RenderClear(t->renderer);
		ti = SDL_GetTicks();
		ix = cos(ANG * D) * inc;
		iy = sin(ANG * D) * inc;
		while (SDL_PollEvent(&t->event))
			key_events(t, ix, iy);
		move(t, ix, iy);
		rotate(t);
		raycast(t);
		SDL_RenderPresent(t->renderer);
		dif = (SDL_GetTicks() - ti);
		if (dif < 20)
			SDL_Delay(20 - dif);
	}
}

int					main(void)
{
	t_wolf			*t;

	if ((t = malloc(sizeof(t_wolf))) == NULL)
		return (0);
	if ((ft_init(t)) == -1)
		return (-1);
	t->name = ("maps/map01");
	if (get_map(t->name, t) == -1)
		return (-1);
	running(t);
	return (0);
}
