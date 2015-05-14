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

void		running(void)
{
	while (1)
	{
		while (SDL_PollEvent(&S->event))
		{
			if (S->event.type == SDL_KEYDOWN)
			{
				if (S->event.key.keysym.sym == 27)
				{
					SDL_DestroyWindow(S->window);
					SDL_Quit();
					exit(1);
				}
			}
		}
	}
}

int			main(int ac, char **av)
{
//	SDL_Window		*win;

	if (ac != 2)
		return (0);
	ft_bzero(S, 1);
//	SDL_Init(SDL_INIT_EVERYTHING);
//	win = SDL_CreateWindow
//	("test", 0, 0, WIDTH, HEIGHT, 0);
	if (get_map(av[1]) == -1)
		return (-1);
	aff_map_term();
//	running();
	return 0;
}
