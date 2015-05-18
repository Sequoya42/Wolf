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
	double	y;
	double	x;
	double	w;
	double	dx;
	int		t;

	ft_putstr(KCYN);
	w = (ALPHA > 180) ? - 64 : 64;
	t = POSY / WALL;
	y = t * 64;
	if (w > 0)
		y -= 1;
	else
		y += 64;
//	y = (w > 0) ? (POSY / WALL)  - 1 : (POSY / WALL) + 64;

	x = POSX + (POSY - y) /tan(ALPHA D);
	if (S->map[(int)y / WALL][(int)x / WALL] == 0)
	{
	 while (S->map[(int)y / WALL][(int)x / WALL] == 0)
	 {
	 	x += XA;
	 	y += WALL;
	 		printf("%f\t\t\t%f\n", ceil(y), floor(y));
	 }
	}
	dx = abs((int)((POSX - x) / cos(ALPHA D)));
//	dx *= cos (abs((int)(ALPHA - ANG)) D);
	return (dx);
}

double		raycast_vertical(void)
{
	double 	x;
	double	y;
	double	w;
	double	dy;
	ft_putstr(KGRN);
	w = (ALPHA < 90 || ALPHA > 270) ? 64 : - 64;
	x = (ALPHA < 90 || ALPHA > 270) ?
	 (POSX / WALL) + 64 : (POSX / WALL) - 1;
	y = POSY + (POSX - x) * tan(ALPHA D);
//	if (S->map[y / WALL][x / WALL] == 0)
	{
//	while (S->map[y / WALL][x / WALL] == 0)
	{
		x += WALL;
		y += YA;
	}
	}
	dy = abs((int)((POSY - y) / sin(ALPHA D)));
//	dy *= cos (abs((int)(ALPHA - ANG)) D);
	return (dy);
}



void		raycast(void)
{
	int		i;
	double	length;
	double	h;
	double	v;
	double	arc;

	i = WIDTH;
	arc = (double)ARC;
	if (ANG >= 360)
		ANG -= 360;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      
	ALPHA = ANG - 30;
	SDL_RenderClear(S->renderer);
	while (i > 0)
	{
		if (ALPHA >= 360)
		ALPHA -= 360;
		if (ALPHA < 0)
		ALPHA += 360;
		h = raycast_horizontal();
//		v = raycast_vertical();
		v = 1;
		if (h > v)
			length = h;
		else
			length = v;
			draw_ray(length, i);
//		ALPHA += arc;
//		printf("%f\n", ALPHA);
		i--;
	}
	SDL_RenderPresent(S->renderer);
//	S->forward = POSX;
	SDL_Delay(16);
}
