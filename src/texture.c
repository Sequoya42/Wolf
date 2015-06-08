
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

void		textured_floor(t_wolf *t, int x)
{
	double 		z;
	double 		y;
	double		ix;
	double		iy;
	double		rx;
	double		ry;
	Uint32 		**img;



	z = ((HEIGHT / 2) + (t->wh / 2));
	y = (HEIGHT / 2) - ((int)t->wh / 2);
	y = (y < 0) ? 0 : y;
	img = (Uint32**)(t->surf3->pix);
	rx = (t->dx < t->dy) ? t->rxh : t->rxv;
	ry = (t->dx < t->dy) ? t->ryh : t->ryv;
	// double test = cos((ALPHA - ANG) D);
	double tro = (HEIGHT - z);
	ix = fabs(rx - POSX) / tro;
	iy = fabs(ry - POSY) / tro;
	ft_putnbrn(ALPHA);
	ft_putchar('\n');
	while (z < HEIGHT)
	{
		t->p[x + (int)z * 800] =
	 img[((int)(ry )) % t->surf3->h][((int)(rx)) % t->surf3->w];
		z++;
		rx = (ALPHA > 90 && ALPHA < 270) ? rx + ix : rx - ix;
		ry = (ALPHA < 180) ? ry + iy : ry - iy;
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