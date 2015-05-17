/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/16 17:52:30 by rbaum             #+#    #+#             */
/*   Updated: 2015/05/16 17:52:37 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

double		raycast_horizontal(void)
{
	int		y;
	int		x;
	int		w;
	double	dx;

	w = (ALPHA > 180) ? - 64 : 64;
	x = POSX + (POSY - IY)/tan(ALPHA);
	y = (w > 0) ? (POSY / WALL) * (WALL) - 1 : (POSY / WALL) * (WALL) + 64;
	while (S->map[y / WALL][x / WALL] == 0)
	{
		x += XA;
		y += WALL;
	}
	dx = abs((PX - x) / cos(ALPHA));
	dx *= cos (ALPHA - ANG);
	return (dx);
}

double		raycast_vertical(void)
{
	int 	x;
	int		y;
	int		w;
	double	dy;

	w = (ALPHA < 90 || ALPHA > 270) ? 64 : - 64;
	x = (ALPHA < 90 || ALPHA > 270) ?
	 (POSX / WALL) * WALL + 64 : (POSX / WALL) * WALL - 1;
	y = POSY + (POSX - x) * tan(ALPHA);
	while (S->map[y / WALL][x / WALL] == 0)
	{
		x += WALL;
		y += YA;
	}
	dy = abs((POSY - y) / sin(ALPHA));
	dy *= cos (ALPHA - ANG);
	return (dy);
}

int			draw_ray(double length, int i)
{
	int 	x;
	double	wh;

	wh = WALL / length * DIST;
	z = (WIDTH / 2) - (length / 2);
	x = 0;
	while (x < )

}

void		raycast(void)
{
	int		i;
	double	length;

	i = WIDTH;
	if (ANG > 360)
		ANG -= 360;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      
	ALPHA = ANG - 30;
	while (i > 0)
	{
		length = (raycast_horizontal() > raycast_vertical()) ?
		raycast_horizontal() : raycast_vertical();
		draw_ray(length, i);
		ALPHA += arc;
		i--;
	}
}
