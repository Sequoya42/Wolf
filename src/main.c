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

void		running(t_wolf *t)
{
	while (1)
	{
		while (SDL_PollEvent(&t->event))
		{
			key_events(t);
			raycast(t);
		}
	}
}