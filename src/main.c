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
	t->trip2 = 1;
	t->trip3 = 800;
	t->choose = 0;
	if ((SDL_Init(SDL_INIT_EVERYTHING)) == -1)
	return (ft_error(NULL, NULL, "Cannot init SDL"));
	t->window = SDL_CreateWindow
	("test", 500, 300, WIDTH, HEIGHT, 0);
	t->renderer = SDL_CreateRenderer(t->window, -1, 
		SDL_RENDERER_ACCELERATED);
	SDL_RenderSetLogicalSize(t->renderer, WIDTH, HEIGHT);
	create_new_renderer(t);
	return (0);
}

void		running(t_wolf *t)
{
	raycast(t);
	while (1)
	{
		while (SDL_PollEvent(&t->event))
		{
			key_events(t);
			if (t->choose == 0)
			raycast(t);
			else
			vector(t);
		}

	}
}