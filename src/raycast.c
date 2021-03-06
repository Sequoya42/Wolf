/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/12 23:43:28 by rbaum             #+#    #+#             */
/*   Updated: 2015/06/12 23:45:33 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static double		raycast_horizontal(double tang, t_wolf *t)
{
	double			dx;
	int				tx;
	int				ty;

	tx = (int)POSX;
	ty = (int)POSY;
	t->iyh = (ALPHA > 180.0) ? WALL : -WALL;
	t->ixh = -t->iyh / tang;
	t->ryh = (double)(ty - ((int)ty % (int)WALL));
	t->ryh = (ALPHA < 180.0) ? t->ryh - 0.0001 : t->ryh + WALL;
	t->rxh = tx + ((ty - t->ryh) / tang);
	while (SAFE && (VALUE != 1))
	{
		if (t->text == 0 && (VALUE == 2 || VALUE == 3))
		{
			t->test = (VALUE == 2) ? 1 : 2;
			break ;
		}
		t->rxh += t->ixh;
		t->ryh += t->iyh;
	}
	dx = fabs(((tx - t->rxh) / cos(ALPHA * D)));
	dx *= (cos(((ALPHA - ANG) * D)));
	return (dx);
}

static double		raycast_vertical(double tang, t_wolf *t)
{
	double			dy;
	int				tx;
	int				ty;

	tx = (int)POSX;
	ty = (int)POSY;
	t->ixv = (ALPHA >= 90.0 && ALPHA <= 270.0) ? -WALL : WALL;
	t->iyv = -t->ixv * tang;
	t->rxv = (double)(tx - ((int)tx % (int)WALL));
	t->rxv = (ALPHA < 90.0 || ALPHA > 270.0) ? t->rxv + WALL : t->rxv - 0.0001;
	t->ryv = ty + ((tx - t->rxv) * tang);
	while (SAFE2 && (VALUE2 != 1))
	{
		if (t->text == 0 && (VALUE2 == 2 || VALUE2 == 3))
		{
			t->test2 = (VALUE2 == 2) ? 1 : 2;
			break ;
		}
		t->rxv += t->ixv;
		t->ryv += t->iyv;
	}
	dy = fabs(((tx - t->rxv) / cos(ALPHA * D)));
	dy *= (cos(((ALPHA - ANG)) * D));
	return (dy);
}

void				raycast(t_wolf *t)
{
	int				i;
	double			arc;
	double			tang;

	i = WIDTH;
	arc = 0.075;
	ALPHA = ANG - 30.0;
	tang = (double)tan(ALPHA * D);
	while (i >= 0)
	{
		t->test = 0;
		t->test2 = 0;
		t->dx = raycast_horizontal(tang, t);
		t->dy = raycast_vertical(tang, t);
		draw_ray(i, t);
		ALPHA += arc;
		ALPHA = (ALPHA >= 360) ? ALPHA - 360 : ALPHA;
		ALPHA = (ALPHA < 0) ? ALPHA + 360 : ALPHA;
		tang = (double)tan(ALPHA * D);
		i--;
	}
	SDL_UpdateTexture(t->screen, NULL, t->p, WIDTH * sizeof(Uint32));
	SDL_RenderCopy(t->renderer, t->screen, NULL, NULL);
	ft_bzero(t->p, sizeof(Uint32) * WIDTH * HEIGHT);
}
