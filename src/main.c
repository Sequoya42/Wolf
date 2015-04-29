/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/26 19:19:29 by rbaum             #+#    #+#             */
/*   Updated: 2015/04/26 19:23:05 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

t_wolf		*singleton(void)
{
	static t_wolf wolf;

	return (&wolf);
}

int			main(void) 
{
	SDL_Window		*win;


	SDL_Init(SDL_INIT_EVERYTHING);
	win = SDL_CreateWindow
	("test", 0, 0, WIDTH, HEIGHT, 0);
	SDL_Delay(3000);  // Pause execution for 3000 milliseconds, for example

//    SDL_DestroyWindow(win);

    while (1)
    {
    	while (SDL_PollEvent(&S->event))
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
//    SDL_Quit();
    return 0;
}
