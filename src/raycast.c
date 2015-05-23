/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/16 17:52:30 by rbaum             #+#    #+#             */
/*   Updated: 2015/05/19 22:28:22 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

double		raycast_horizontal(double tang)
{
	double	y;
	double	x;
	double	ya;
	double	xa;
	double	dx;

	ya = (ALPHA > 180.0) ? - 64.0 : 64.0;
	xa = (ALPHA < 90.0 || ALPHA > 270.0) ? 
	(64.0 / tang) :  (-64.0 / tang);
	y = (double)((int)(POSY / (double)WALL)) * (double)WALL;
	y = (ya > 0.0) ? y - 0.001 : y + 64.0;
	x = POSX + ((POSY - y) / tang);
	while (SAFE && VALUE != 1)
	{
		x += xa;
		y += ya;
	}
	dx = fabs(((POSX - x) / cos(ALPHA  D)));
	dx *= (cos(((ALPHA - ANG) D)));
	ft_putendl(KYEL);
	printf("dx = %f\n", dx);
	return (dx);
}

double		raycast_vertical(double tang)
{
	double 	x;
	double	y;
	double	xa;
	double	ya;
	double	dy;

	xa = (ALPHA < 90.0 || ALPHA > 270.0) ? 64.0 :  -64.0;
	ya = (ALPHA > 180.0) ? 
	(- 64.0 * tang) : (64.0 * tang);
	x = ((int)(POSX / WALL)) * WALL;
	x = (ALPHA < 90.0 || ALPHA > 270.0) ? x + 64.0 : x - 0.001;
	y = POSY + ((POSX - x) * tang);
	while (SAFE && VALUE != 1)
	{
//	printf("ya: %f\t\txa: %f\ny: %f\t\tx: %f\nposx: %f\t\tposy: %f\n",
//	 ya, xa, y, x, POSX, POSY);
		x += xa;
		y += ya;
//		if (SAFE)
//		printf("MAPX: %d\t\tMAPY: %d\t\tVALUE: %d\n", MAPX, MAPY, VALUE);	
//	ft_putendl("-------------");
	}
	dy = fabs(((POSX - x) / cos(ALPHA D)));
	dy *= (cos(((ALPHA - ANG)) D));
//		ft_putendl(KCYN);
	printf("dy = %f\n", dy);
	return (dy);
}

void		raycast(void)
{
	int		i;
	double	length;
	double	h;
	double	v;
	double	arc;
	double	tang;

	i = WIDTH;
	arc = 0.075;
	ALPHA = ANG - 30.0;
	SDL_RenderClear(S->renderer);
	tang = tan(ALPHA D);
	while (i > 0)
	{
		 if (ALPHA >= 360.0)
		 	ALPHA -= 360.0;
		 if (ALPHA < 0.0)
		 	ALPHA += 360.0;
		h = raycast_horizontal(tang);
		v = raycast_vertical(tang);
		printf("iteration: %d\t\talpha : %f\t\t angle: %f\n",i, ALPHA, ANG);
//		printf("\t\t\t\t\t%f\t\t%f\n", h, v);
		if (h < v)
			length = h;
		else
			length = v;
		draw_ray(length, i);
		ALPHA += arc;
		tang = tan(ALPHA D);
		i--;
	}
	SDL_RenderPresent(S->renderer);
	SDL_Delay(16);
}
