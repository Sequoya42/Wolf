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

int			main(void) 
{
	SDL_Window		*win;


	SDL_Init(SDL_INIT_EVERYTHING);
	win = SDL_CreateWindow("test", 0, 0, 800, 600, SDL_WINDOW_OPENGL);
	SDL_Delay(3000);  // Pause execution for 3000 milliseconds, for example

    // Close and destroy the window
    SDL_DestroyWindow(win);

    // Clean up
    SDL_Quit();
    return 0;
}
