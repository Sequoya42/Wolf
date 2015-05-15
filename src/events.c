/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/15 18:51:17 by rbaum             #+#    #+#             */
/*   Updated: 2015/05/15 18:51:17 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void		key_events(void)
{
	if (S->event.type == SDL_KEYDOWN)
	{
		if (S->event.key.keysym.sym == 27)
		{
			SDL_DestroyWindow(S->window);
			SDL_Quit();
			exit(1);
		}
		if (S->event.key.keysym.sym == SDLK_RIGHT && S->rect.x < (WIDTH - INCR))
			S->rect.x += INCR;
		if (S->event.key.keysym.sym == SDLK_LEFT && S->rect.x > 0)
			S->rect.x -= INCR;
		if (S->event.key.keysym.sym == SDLK_DOWN && S->rect.y < (HEIGHT - INCR))
			S->rect.y += INCR;
		if (S->event.key.keysym.sym == SDLK_UP && S->rect.y > 0)
			S->rect.y -= INCR;
	}
}

void		running(void)
{
	while (1)
	{
		while (SDL_PollEvent(&S->event))
		{
			key_events();
			test_rendering();
			printf("%d\n%d\n", S->rect.x, S->rect.y);
		}
		SDL_Delay(16);
	}
}