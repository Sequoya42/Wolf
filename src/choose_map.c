/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/12 22:31:37 by rbaum             #+#    #+#             */
/*   Updated: 2015/06/12 22:31:40 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void		clean_surface(t_wolf *t)
{
	del_surface(&t->sw);
	del_surface(&t->sf);
	del_surface(&t->sc);
	del_surface(&t->st);
}

void		choose_map(t_wolf *t)
{
	if (ft_strcmp(t->name, "maps/map01") == 0)
		map_one(t);
	else if (ft_strcmp(t->name, "maps/map02") == 0)
		map_two(t);
	else if (ft_strcmp(t->name, "maps/map03") == 0)
		map_three(t);
	else if (ft_strcmp(t->name, "maps/map04") == 0)
		map_four(t);
	else if (ft_strcmp(t->name, "maps/map05") == 0)
		map_five(t);
}

void		change_map(t_wolf *t)
{
	if (t->map[(int)POSY / (int)WALL][(int)POSX / (int)WALL] == 2)
	{
		choose_map(t);
		get_map(t->name, t);
		teleport(t);
	}
	else if (t->map[(int)POSY / (int)WALL][(int)POSX / (int)WALL] == 3)
	{
		t->text = 0;
		t->trip = (t->trip == 0) ? 1 : 0;
		t->map[(int)POSY / (int)WALL][(int)POSX / (int)WALL] = 0;
	}
}
