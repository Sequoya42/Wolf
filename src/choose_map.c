/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/10 17:56:25 by rbaum             #+#    #+#             */
/*   Updated: 2015/06/10 17:56:29 by rbaum            ###   ########.fr       */
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

void		map_one(t_wolf *t)
{
		clean_surface(t);
		t->name = ("maps/map02");
		t->sw = ft_loadbmp("./bitmap/thewall.bmp");
		t->sf = ft_loadbmp("./bitmap/elephant.bmp");
		t->sc = ft_loadbmp("./bitmap/cath.bmp");
		t->st = ft_loadbmp("./bitmap/fish.bmp");
}

void		map_two(t_wolf *t)
{
	clean_surface(t);
	t->name = ("maps/map03");
	t->sw = ft_loadbmp("./bitmap/elephant.bmp");
	t->sf = ft_loadbmp("./bitmap/fox.bmp");
	t->sc = ft_loadbmp("./bitmap/fox.bmp");
	t->st = ft_loadbmp("./bitmap/batman.bmp");

}

void		map_three(t_wolf *t)
{
	clean_surface(t);
	t->name = ("maps/map05");
	t->sw = ft_loadbmp("./bitmap/floating.bmp");
	t->sf = ft_loadbmp("./bitmap/thewall.bmp");
	t->sc = ft_loadbmp("./bitmap/batman.bmp");
	t->st = ft_loadbmp("./bitmap/damier.bmp");

}

void		map_four(t_wolf *t)
{
	clean_surface(t);
	t->name = ("maps/map05");
	t->sw = ft_loadbmp("./bitmap/floor.bmp");
	t->sf = ft_loadbmp("./bitmap/floor.bmp");
	t->sc = ft_loadbmp("./bitmap/floor.bmp");
	t->st = ft_loadbmp("./bitmap/batman.bmp");

}


void		map_five(t_wolf *t)
{
	clean_surface(t);
	t->name = ("maps/map01");
	t->sw = ft_loadbmp("./bitmap/win.bmp");
	t->sf = ft_loadbmp("./bitmap/win.bmp");
	t->sc = ft_loadbmp("./bitmap/win.bmp");
	t->st = ft_loadbmp("./bitmap/batman.bmp");

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
}