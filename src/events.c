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
		if (KEY == SDLK_RIGHT)
		{
					ANG -= 5;
			while (ANG < 0)
				ANG += 360;

		}
}

void		move_left(void)
{
		if (KEY == SDLK_LEFT)
		{
					ANG += 5;
			while (ANG >= 360)
				ANG -= 360;

		}
}

void		move_backward(void)
{
		if (KEY == SDLK_UP && MOVE)// && SAFE)
		{

				POSX += (cos(ANG) * 64);
				POSY += (sin(ANG) * 64);
				printf("%d\t\t%d\n", POSX, POSY);
		}
}

void		move_forward(void)
{
		if (KEY == SDLK_DOWN && MOVE)// && SAFE)
		{
			// if (ANG < 180)
			// {
			POSX += (cos(ANG) * 10);
			POSY += (sin(ANG) * 10);
	printf("%d\t\t%d\n", POSX, POSY);
			// }
			// else
			// {
			// }
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

