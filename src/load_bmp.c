
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
	if (!(surf->surf = SDL_ConvertSurfaceFormat(tmp, SDL_PIXELFORMAT_ARGB8888, 0)))
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

void		load_bmp(t_wolf *t, int x, double wh, double dx, double dy)
{
	double z;
	double y;
	double		i;
	Uint32 **img;
	int offset;

	z = ((HEIGHT / 2) + (wh / 2));
	y = (HEIGHT / 2) - ((int)wh / 2);
	y = (y < 0) ? 0 : y;
	offset  = (dx > dy) ? 
	(abs((int)(t->ryv)) % 64) : (abs((int)(t->rxh)) % 64);
	// if (dx > dy)
	// offset = (abs((int)t->ryv % 64));
	// else
	// offset = (abs((int)t->rxh % 64));
	img = (Uint32**)(t->surf->pix);
	i = 0.0;
	printf("Offset :%d\n", offset);
	while (y < 600 && y < z - 2)	
	{
		t->p[x + ((int)y * 800)] = img[(int)i][offset];
		// img[(int)i % t->surf->h][offset % t->surf->w];
		// i *= wh / (double)t->surf->h;
		i += (double)t->surf->h / wh;
		y++;
	}
}
