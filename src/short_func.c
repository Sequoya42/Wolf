/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student->42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/16 17:56:09 by rbaum             #+#    #+#             */
/*   Updated: 2015/05/16 17:56:13 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

t_color		set_color(char r, char g, char b)
{
	t_color		c;

	c.r = r;
	c.g = g;
	c.b = b;
	return (c);
}


Uint32 couleur(int r, int g, int b, int m)
{ 
	while (m > 255)
		m -= 255;
	return (((((r << 8) + g) << 8)+ b) * m / 100);
}

int			shade(t_wolf *t, double wh)
{
	int m;

	if (t->trip == 1)
		m = wh;
	else
		m = 100;
		return (m);
}

