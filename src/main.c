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
	if (ac < 1)//Change to two to change maps
		return (0);
		if ((ft_init()) == -1)
		return (-1);
	if (get_map(av[1]) == -1)
		return (-1);

	 aff_map_term();
	running();
	return 0;
}

void		running(void)
{
	S->rect.x = 50;
	S->rect.y = 50;
	S->rect.w = 10;
	S->rect.h = 10;
	while (1)
	{
		while (SDL_PollEvent(&S->event))
		{
			key_events();
			raycast();
		}

	}
}