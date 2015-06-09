
#include "wolf.h"

double		start_value(t_wolf *t)
{
	double start;

	start = 0.0;
	if (t->wh >= 600)
	{
		start = ((int)t->wh - 600) / 2;
		start = (start / t->wh);
		start = t->sw->h * start;
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
	img = (Uint32**)(t->sw->pix);
	i = start_value(t);
	inc = (double)t->sw->h / t->wh;
	while (y < 600 && y < z - 2)	
	{
		t->p[x + ((int)y * 800)] = 
		 img[(int)i % t->sw->h][offset % t->sw->w];
		i += inc;
		y++;
	}
}

void		textured_floor(t_wolf *t, int x)
{
	double 	dx;
	double 	dy;
	double 	dp;
	Uint32 	**img;
	double 	z;
	double 	angle; 
	double 	tro;

	img = (Uint32**)(t->sf->pix);
	angle = cos((ALPHA - ANG) D);
	z = ((HEIGHT / 2) + (t->wh / 2));
	while (z < HEIGHT)
	{
		tro = ((double)z - (HEIGHT / 2));
		dp = (WALL / 2) / tro * DIST / angle;
		dy = -dp * sin(ALPHA D) + POSY;
		dx = dp * cos(ALPHA D) + POSX;
		t->p[x + (int)z * 800] = img[TX][TY];
		z++;
	}
}

void		textured_ceiling(t_wolf *t, int x)
{
	double dx;
	double dy;
	double dp;
	double angle; 
	double tro;
	double 		y;
	Uint32 		**img;

	img = (Uint32**)(t->sc->pix);
	angle = cos((ALPHA - ANG) D);
	y = (HEIGHT / 2) - ((int)t->wh / 2);
	y = (y < 0) ? 0 : y;
	tro = t->wh / 2;
	while (y > 0)
	{
		dp = (WALL / 2)  / tro * DIST / angle;
		dy = -dp * sin(ALPHA D) + POSY;
		dx = dp * cos(ALPHA D) + POSX;
		t->p[x + (int)y * 800] = img[TX][TY];
		tro++;
		y--;
	}
}