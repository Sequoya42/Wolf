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

void		move_right(void)
{
		if (KEY == SDLK_RIGHT && S->rect.x < (WIDTH - INCR))
		{
			if (ANG < 350)
			ANG += 10;
		}
}

void		move_left(void)
{
		if (KEY == SDLK_LEFT && S->rect.x > 0)
		{
			if (ANG > 10)
			ANG -= 10;
		}
}

void		move_backward(void)
{
		if (KEY == SDLK_DOWN && S->rect.y < (HEIGHT - INCR))
		{
			if (Y < (MH - 1))
				Y += 1;
		}
}

void		move_forward(void)
{
		if (KEY == SDLK_UP && S->rect.y > 0)
		{
			if (Y > 1)
				Y--;
		}
}



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
		move_right();
		move_left();
		move_forward();
		move_backward();
	}
}

