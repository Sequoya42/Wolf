/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_bmp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/05 18:59:47 by rbaum             #+#    #+#             */
/*   Updated: 2015/06/05 18:59:48 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void				del_surface(t_surface **surface)
{
	if ((*surface)->surf)
	{
		SDL_FreeSurface((*surface)->surf);
		if ((*surface)->pix)
			free((*surface)->pix);
	}
	free(*surface);
	free(*surface = NULL);
}

static t_color		**alloc_pix(SDL_Surface *surf)
{
	int			i;
	t_color		**pix;

	if (!(pix = malloc(sizeof(t_color *) * surf->h)))
		return (NULL);
	pix[0] = (t_color *)surf->pixels;
	i = 0;
	while (i < surf->h)
	{
		pix[i] = (t_color *)(((char *)surf->pixels) + surf->pitch * i);
		i++;
	}
	return (pix);
}

t_surface			*ft_loadbmp(const char *path)
{
	SDL_Surface	*tmp;	
	t_surface	*surf;

	if (!(surf = malloc(sizeof(t_surface))))
		return (NULL);
	if (!(tmp = SDL_LoadBMP(path)))
	{
		ft_memdel((void **)&surf);
		return (NULL);
	}
	if (!(surf->surf = 
		SDL_ConvertSurfaceFormat(tmp, SDL_PIXELFORMAT_ARGB8888, 0)))
	{
		SDL_FreeSurface(tmp), ft_memdel((void **)&surf);
		return (NULL);
	}
	SDL_FreeSurface(tmp);
	surf->h = surf->surf->h;
	surf->w = surf->surf->w;
	if (!(surf->pix = alloc_pix(surf->surf)))
		del_surface(&surf);
	return (surf);

}

