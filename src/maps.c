/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/12 22:21:55 by rbaum             #+#    #+#             */
/*   Updated: 2015/06/12 22:37:07 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void		map_one(t_wolf *t)
{
	clean_surface(t);
	t->name = ("maps/map02");
	t->sw = ft_loadbmp("./bitmap/thewall.bmp");
	t->sf = ft_loadbmp("./bitmap/elephant.bmp");
	t->sc = ft_loadbmp("./bitmap/cath.bmp");
	t->st = ft_loadbmp("./bitmap/shroom.bmp");
}

void		map_two(t_wolf *t)
{
	clean_surface(t);
	t->name = ("maps/map03");
	t->sw = ft_loadbmp("./bitmap/floating.bmp");
	t->sf = ft_loadbmp("./bitmap/thewall.bmp");
	t->sc = ft_loadbmp("./bitmap/batman.bmp");
	t->st = ft_loadbmp("./bitmap/damier.bmp");
}

void		map_three(t_wolf *t)
{
	clean_surface(t);
	t->name = ("maps/map04");
	t->sw = ft_loadbmp("./bitmap/floor.bmp");
	t->sf = ft_loadbmp("./bitmap/floor.bmp");
	t->sc = ft_loadbmp("./bitmap/floor.bmp");
	t->st = ft_loadbmp("./bitmap/batman.bmp");
}

void		map_four(t_wolf *t)
{
	clean_surface(t);
	t->name = ("maps/map05");
	t->sw = ft_loadbmp("./bitmap/win.bmp");
	t->sf = ft_loadbmp("./bitmap/win.bmp");
	t->sc = ft_loadbmp("./bitmap/win.bmp");
	t->st = ft_loadbmp("./bitmap/batman.bmp");
}

void		map_five(t_wolf *t)
{
	clean_surface(t);
	t->name = ("maps/map01");
	t->sw = ft_loadbmp("./bitmap/vang.bmp");
	t->sf = ft_loadbmp("./bitmap/fox.bmp");
	t->sc = ft_loadbmp("./bitmap/floor.bmp");
	t->st = ft_loadbmp("./bitmap/batman.bmp");
}
