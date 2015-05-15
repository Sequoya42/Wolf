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

t_wolf		*singleton(void)
{
	static t_wolf wolf;

	return (&wolf);
}

int		ft_init(void)
{
	S->rect.x = 50;
	S->rect.y = 50;
	S->rect.w = 10;
	S->rect.h = 10;
	ft_bzero(S, 1);
	if ((SDL_Init(SDL_INIT_EVERYTHING)) == -1)
	return (ft_error(NULL, NULL, "Cannot init SDL"));
	S->window = SDL_CreateWindow
	("test", 500, 300, WIDTH, HEIGHT, 0);
	S->renderer = SDL_CreateRenderer(S->window, -1, SDL_RENDERER_ACCELERATED);
	SDL_RenderSetLogicalSize(S->renderer, WIDTH, HEIGHT);
	SDL_SetRenderDrawColor(S->renderer, 255, 128, 0, 255);
	return (0);
}

int			main(int ac, char **av)
{
	if (ac < 1)//Change to two to change maps
		return (0);
	if ((ft_init()) == -1)
		return (-1);
	
	if (get_map(av[1]) == -1)
		return (-1);
//	aff_map_term();
	running();
	return 0;
}
