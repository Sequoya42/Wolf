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
	double			y;
	double			x;
	double			ya;
	double			xa;
	double			dx;

	int tx = (int)POSX;
	int ty = (int)POSY;
	ya = (ALPHA > 180.0) ? 64.0 : -64.0;
	xa = - ya / tang;
	y = (double)(ty - ((int)ty % 64));
	y = (ALPHA < 180.0) ? y - 0.0001 : y + 64.0;
	x = tx + ((ty - y) / tang);
	while (SAFE && VALUE != 1)
	{
		x += xa;
		y += ya;
	}
	dx = fabs(((tx - x) / cos(ALPHA  D)));
	dx *= (cos(((ALPHA - ANG) D)));
	return (dx);
}

static double		raycast_vertical(double tang, t_wolf *t)
{
	double 			x;
	double			y;
	double			xa;
	double			ya;
	double			dy;

	int	tx = (int)POSX;
	int	ty = (int)POSY;
	xa = (ALPHA > 90.0 && ALPHA < 270.0) ? -64.0 :  64.0;
	ya = - xa * tang;
	x = (double)(tx - ((int)tx % 64));
	x = (ALPHA < 90.0 || ALPHA > 270.0) ? x + 64.0 : x - 0.0001;
	y = ty + ((tx - x) * tang);
	while (SAFE && VALUE != 1)
	{
		x += xa;
		y += ya;
	}
	dy = fabs(((tx - x) / cos(ALPHA D)));
	dy *= (cos(((ALPHA - ANG)) D));
	return (dy);
}

t_color				get_mix(t_color *buf, int x, int y)
{
	t_color		c;
	unsigned	r;
	unsigned	g;
	unsigned	b;

	ft_bzero(&c, sizeof(t_color));
	r = buf[x + y * WIDTH].r << 1;
	g = buf[x + y * WIDTH].g << 1;
	b = buf[x + y * WIDTH].b << 1;
	if (x >= 1)
	{
		r += buf[x + y * WIDTH - 1].r >> 1;
		g += buf[x + y * WIDTH - 1].g >> 1;
		b += buf[x + y * WIDTH - 1].b >> 1;
	}
	if (x < WIDTH - 1)
	{
		r += buf[x + y * WIDTH + 1].r >> 1;
		g += buf[x + y * WIDTH + 1].g >> 1;
		b += buf[x + y * WIDTH + 1].b >> 1;
	}
	/*if (y >= 1)
	{
		r += buf[x + y * WIDTH - WIDTH].r / 2;
		g += buf[x + y * WIDTH - WIDTH].g / 2;
		b += buf[x + y * WIDTH - WIDTH].b / 2;
	}

	if (y < HEIGHT - 1)
	{
		r += buf[x + y * WIDTH + WIDTH].r / 2;
		g += buf[x + y * WIDTH + WIDTH].g / 2;
		b += buf[x + y * WIDTH + WIDTH].b / 2;
	}*/
	c.r = r / 3;
	c.g = g / 3;
	c.b = b / 3;
	return (c);
}

void				test(t_wolf *t)
{
	int				i;
	int				j;
	t_color			*buf;

	buf = malloc(sizeof(t_color) * WIDTH * HEIGHT);
	if (buf == NULL)
	{
		printf("error");
		return ;
	}
	j = 0;
	while (j < HEIGHT)
	{
		i = 0;
		while (i < WIDTH)
		{
			buf[i + j * WIDTH] = get_mix((t_color *)t->p, i, j);
			i++;
		}
		j++;
	}
	free(t->p);
	t->p = (Uint32 *)buf;
}

void				raycast(t_wolf *t)
{
	int				i;
	double			h;
	double			v;
	double			arc;
	double			tang;

	i = WIDTH;
	arc = 0.075;
	ALPHA = ANG - 30.0;
	tang = (double)tan(ALPHA D);
	while (i >= 0)
	{
		h = raycast_horizontal(tang, t);
		v = raycast_vertical(tang, t);
		draw_ray(h, v, i, t);
		ALPHA += arc;
		ALPHA = (ALPHA >= 360) ? ALPHA - 360 : ALPHA;
		ALPHA = (ALPHA < 0) ? ALPHA + 360 : ALPHA;
		tang = (double)tan(ALPHA D);
		i--;
	}
	// test(t);
	SDL_UpdateTexture(t->screen, NULL, t->p, WIDTH * sizeof(Uint32));
	SDL_RenderCopy(t->renderer, t->screen, NULL, NULL);
	SDL_RenderPresent(t->renderer);
	ft_bzero(t->p, sizeof(Uint32) * WIDTH * HEIGHT);
}
