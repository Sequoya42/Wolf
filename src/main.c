/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/26 19:19:29 by rbaum             #+#    #+#             */
/*   Updated: 2015/05/14 20:24:12 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int			main(int ac, char **av)
{
	t_wolf	t;

	if (ac < 1)//Change to two to change maps
		return (0);
	if ((ft_init(&t)) == -1)
		return (-1);
	if (get_map(av[1], &t) == -1)
		return (-1);
	running(&t);
	return 0;
}

int		ft_init(t_wolf *t)
{
	ANG = 90.4;
	t->trip = 0;
	t->neon = 0;
	t->height = 600;
	t->cren = 0;
	t->text = 0;

	srand(time(NULL));
	if ((SDL_Init(SDL_INIT_VIDEO)) == -1)
		return (ft_error(NULL, NULL, "Cannot init SDL"));
	t->window = SDL_CreateWindow
	("Labyrinth", 500, 300, WIDTH, HEIGHT, 0);
	t->renderer = SDL_CreateRenderer(t->window, -1, 
		SDL_RENDERER_ACCELERATED);
	t->surf = ft_loadbmp("./maps/nounours.bmp");
	t->surf2 = ft_loadbmp("./maps/wall.bmp");
	t->surf3 = ft_loadbmp("./maps/test.bmp");
	SDL_RenderSetLogicalSize(t->renderer, WIDTH, HEIGHT);
	create_new_renderer(t);
	return (0);
}

void		running(t_wolf *t)
{
	unsigned int	ti;
	unsigned int	dif;
	int 			inc;
	int				ix;
	int				iy;

	inc = 8;
	t->keystate = SDL_GetKeyboardState(NULL);
	while (1)
	{
		ti = SDL_GetTicks();
		ix = cos(ANG D) * inc;
		iy = sin(ANG D) * inc;
		while (SDL_PollEvent(&t->event))
			key_events(t, ix, iy);
		move(t, ix, iy);
		rotate(t);
		raycast(t);
		dif = (SDL_GetTicks() - ti);
		if (dif < 20)
			SDL_Delay(20 - dif);
	}
}