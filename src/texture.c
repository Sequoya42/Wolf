
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
	Uint32 		**img2;
	int 		offset;
	double		inc;

	z = ((HEIGHT / 2) + (t->wh / 2));
	y = (HEIGHT / 2) - ((int)t->wh / 2);
	y = (y < 0) ? 0 : y;
	offset  = (t->dx > t->dy) ? 
	(abs((int)(t->ryv)) % (int)WALL) : (abs((int)(t->rxh)) % (int)WALL);
	img = (Uint32**)(t->sw->pix);
	img2 = (Uint32**)(t->sw2->pix);
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
		Uint32 	**img2;
	double 	z;
	double 	angle; 
	double 	tro;
	double sinus;
	double cosinus;

	sinus = sin(ALPHA D);
	cosinus = cos(ALPHA D);
	img = (Uint32**)(t->sf->pix);
	img2 = (Uint32**)(t->st->pix);
	angle = cos((ALPHA - ANG) D);
	z = ((HEIGHT / 2) + (t->wh / 2));
	while (z < HEIGHT)
	{
		tro = ((double)z - (HEIGHT / 2));
		dp = (WALL / 2) / tro * DIST / angle;
		dy = -dp * sinus + POSY;
		dx = dp * cosinus + POSX;
		int tx = (int)dx / (int)WALL;
		int ty = (int)dy / (int)WALL;
	if (tx < MW && ty < MH && t->map[ty][tx] != 2)
			t->p[x + (int)z * 800] = img[TX][TY];
	else
			t->p[x + (int)z * 800] = img2[TX][TY];
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
	double sinus;
	double cosinus;
	double 		y;
	Uint32 		**img;

	sinus = sin(ALPHA D);
	cosinus = cos(ALPHA D);
	img = (Uint32**)(t->sc->pix);
	angle = cos((ALPHA - ANG) D);
	y = (HEIGHT / 2) - ((int)t->wh / 2);
	tro = t->wh / 2;
	while (y > 0)
	{
		dp = (WALL / 2)  / tro * DIST / angle;
		dy = -dp * sinus + POSY;
		dx = dp * cosinus + POSX;
 		t->p[x + (int)y * 800] = img[TX][TY];
		tro++;
		y--;
	}
}