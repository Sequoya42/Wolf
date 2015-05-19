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
	int		ya;
	double	dx;

	ft_putstr(KYEL);
	ya = (ALPHA > 180) ? - 64 : 64;
	y = ((int)(POSY / WALL)) * WALL;
	y = (ya > 0) ? y - 1 : y + 64;
	x = POSX + (POSY - y) /tan(ALPHA D);
	while (S->map[(int)(x / WALL)][(int)(y / WALL)] != 1)
	{

		x += XA;
		y += ya;
	}
	dx = fabs(((POSX - x) / cos(ALPHA D)));
	dx *= cos(fabs(((ALPHA - ANG) D)));
	return (dx);
}

double		raycast_vertical(void)
{
	double 	x;
	double	y;
	double	xa;
	double	dy;

	ft_putstr(KGRN);
	xa = (ALPHA < 90 || ALPHA > 270) ? - 64 :  64;
	x = ((int)(POSX / WALL)) * WALL;
	x = (ALPHA < 90 || ALPHA > 270) ? x + 64 : x - 1;
	y = POSY + (POSX - x) * tan(ALPHA D);
	while (S->map[(int)(x / WALL)][(int)(y / WALL)] == 0)
		{
					ft_putendl("dans la boucle");
			printf("%d\t\t%d\n", (int)(x / WALL), (int)(y / WALL));
			x += xa;
			y += YA;
		}
		ft_putendl("\t\t\t\tapres");
	dy = fabs(((POSX - x) / cos(ALPHA D)));
	dy *= cos(fabs((ALPHA - ANG)) D);
	return (dy);
}

void		raycast(void)
{
	int		i;
	double	length;
	double	h;
	double	v;
	double	arc;

	i = 0;
	arc = 0.075;
	if (ANG >= 360)
		ANG -= 360;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      
	ALPHA = ANG - 30;
	SDL_RenderClear(S->renderer);
	while (i < WIDTH)
	{
		if (ALPHA > 360)
			ALPHA -= 360;
		if (ALPHA < 0)
			ALPHA += 360;
		h = raycast_horizontal();
//		h = 0;
//		v = raycast_vertical();
		v = 0;
		if (h >= v)
			length = h;
		else
			length = v;
			draw_ray(length, i);
		ALPHA += arc;
		i++;
	}
	SDL_RenderPresent(S->renderer);
//	S->forward = POSX;
	SDL_Delay(16);
}
