/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/16 17:56:09 by rbaum             #+#    #+#             */
/*   Updated: 2015/05/16 17:56:13 by rbaum            ###   ########.fr       */
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
	ft_bzero(S, 1 * sizeof(t_wolf));
	S->rect.x = 50;
	S->rect.y = 50;
	S->rect.w = 10;
	S->rect.h = 10;
	ANG = 0;
	if ((SDL_Init(SDL_INIT_EVERYTHING)) == -1)
	return (ft_error(NULL, NULL, "Cannot init SDL"));
	S->window = SDL_CreateWindow
	("test", 500, 300, WIDTH, HEIGHT, 0);
	S->renderer = SDL_CreateRenderer(S->window, -1, SDL_RENDERER_ACCELERATED);
	SDL_RenderSetLogicalSize(S->renderer, WIDTH, HEIGHT);
	SDL_SetRenderDrawColor(S->renderer, 255, 128, 0, 255);
	return (0);
}