/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast->c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student->42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/16 17:52:30 by rbaum             #+#    #+#             */
/*   Updated: 2015/05/19 22:28:22 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static double		raycast_horizontal(double tang, t_wolf *t)
{
	double			dx;

	int tx = (int)POSX;
	int ty = (int)POSY;
	t->iyh = (ALPHA > 180.0) ? 64.0 : -64.0;
	t->ixh = - t->iyh / tang;
	t->ryh = (double)(ty - ((int)ty % 64));
	t->ryh = (ALPHA < 180.0) ? t->ryh - 0.0001 : t->ryh + 64.0;
	t->rxh = tx + ((ty - t->ryh) / tang);
	while (SAFE && VALUE != 1)
	{
		t->rxh += t->ixh;
		t->ryh += t->iyh;
	}
	dx = fabs(((tx - t->rxh) / cos(ALPHA  D)));
	dx *= (cos(((ALPHA - ANG) D)));
	return (dx);
}

static double		raycast_vertical(double tang, t_wolf *t)
{
	double			dy;

	int	tx = (int)POSX;
	int	ty = (int)POSY;
	t->ixv = (ALPHA >= 90.0 && ALPHA <= 270.0) ? -64.0 :  64.0;
	t->iyv = - t->ixv * tang;
	t->rxv = (double)(tx - ((int)tx % 64));
	t->rxv = (ALPHA < 90.0 || ALPHA > 270.0) ? t->rxv + 64.0 : t->rxv - 0.0001;
	t->ryv = ty + ((tx - t->rxv) * tang);
	while (SAFE2 && VALUE2 != 1)
	{
		t->rxv += t->ixv;
		t->ryv += t->iyv;
	}
	dy = fabs(((tx - t->rxv) / cos(ALPHA D)));
	dy *= (cos(((ALPHA - ANG)) D));
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
	tang = (double)tan(ALPHA D);
	while (i >= 0)
	{
		t->dx = raycast_horizontal(tang, t);
		t->dy = raycast_vertical(tang, t);
		draw_ray(i, t);
		ALPHA += arc;
		ALPHA = (ALPHA >= 360) ? ALPHA - 360 : ALPHA;
		ALPHA = (ALPHA < 0) ? ALPHA + 360 : ALPHA;
		tang = (double)tan(ALPHA D);
		i--;
	}
// for (i = 0; i < t->surf->h; i++)
// ft_memmove(t->p + i * WIDTH, t->surf->pix[i], t->surf->w * sizeof(t_color));
	SDL_UpdateTexture(t->screen, NULL, t->p, WIDTH * sizeof(Uint32));
	SDL_RenderCopy(t->renderer, t->screen, NULL, NULL);
	SDL_RenderPresent(t->renderer);
	ft_bzero(t->p, sizeof(Uint32) * WIDTH * HEIGHT);
}
