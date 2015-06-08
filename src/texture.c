
#include "wolf.h"

double		start_value(t_wolf *t)
{
	double start;

	start = 0.0;
	if (t->wh >= 600)
	{
		start = ((int)t->wh - 600) / 2;
		start = (start / t->wh);
		start = t->surf->h * start;
	}
	return (start);
}

void		textured_wall(t_wolf *t, int x)
{
	double 		z;
	double 		y;
	double		i;
	Uint32 		**img;
	int 		offset;
	double		inc;

	z = ((HEIGHT / 2) + (t->wh / 2));
	y = (HEIGHT / 2) - ((int)t->wh / 2);
	y = (y < 0) ? 0 : y;
	offset  = (t->dx > t->dy) ? 
	(abs((int)(t->ryv)) % 64) : (abs((int)(t->rxh)) % 64);
	img = (Uint32**)(t->surf->pix);
	i = start_value(t);
	inc = (double)t->surf->h / t->wh;
	while (y < 600 && y < z - 2)	
	{
		t->p[x + ((int)y * 800)] = 
		 img[(int)i % t->surf->h][offset % t->surf->w];
		i += inc;
		y++;
	}
}

int		find_floor(t_wolf *t)
{
	int fx;
	int fy;
	int ix;
	int iy;
	int os;

	fx = (t->dx < t->dy) ? t->rxh : t->rxv;
	fy = (t->dx < t->dy) ? t->ryh : t->ryv;
	ix = (t->dx < t->dy) ? t->ixh : t->ixv;
	iy = (t->dx < t->dy) ? t->iyh : t->iyv;
	if (t->dx < t->dy)
		os = (fx - ix) % 64;
	else
		os = (fy - iy) % 64;
	return (os);

}

void		textured_floor(t_wolf *t, int x)
{
	double 		z;
	double 		y;
	double		i;
	Uint32 		**img;
	int 		offset;
	double		inc;

	z = ((HEIGHT / 2) + (t->wh / 2));
	y = (HEIGHT / 2) - ((int)t->wh / 2);
	y = (y < 0) ? 0 : y;
	img = (Uint32**)(t->surf3->pix);
	inc = (double)t->surf2->h / ((HEIGHT - z));
	offset = find_floor(t);
	while (z < HEIGHT)
	{
		i = 0.0;//MODIFY
	t->p[x + (int)z * 800]=
	 img[(int)i % t->surf3->h][offset % t->surf3->w];
		i += inc;
		z++;
	}
}

void		textured_ceiling(t_wolf *t, int x)
{
	double 		z;
	double 		y;
	double		i;
	Uint32 		**img;
	int 		offset;
	double		inc;

	z = ((HEIGHT / 2) + (t->wh / 2));
	y = (HEIGHT / 2) - ((int)t->wh / 2);
	y = (y < 0) ? 0 : y;
	offset  = (t->dx > t->dy) ? 
	(abs((int)(t->ryv)) % 64) : (abs((int)(t->rxh)) % 64);
	img = (Uint32**)(t->surf2->pix);
	i = 0.0;
	inc = (double)t->surf2->h / y;
	int toto = 0;
	while (toto < y)
	{
		t->p[x + ((int)toto * 800)] = 
		 img[(int)i % t->surf2->h][offset % t->surf2->w];
		i += inc;
		toto++;
	}
}