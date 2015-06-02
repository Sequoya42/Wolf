/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student->42.fr>                +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/26 19:09:40 by rbaum             #+#    #+#             */
/*   Updated: 2015/05/14 20:28:06 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
#define WOLF_H

# include <fcntl.h>
# include <math.h>
# include "libft.h"
# include "SDL2.framework/Headers/SDL.h"
#include <time.h>
# include <stdio.h> // REMOVE THIS


#define WIDTH 	800
#define HEIGHT	600
#define	WALL	64.0
#define POV		32
#define	FOV		60
#define	DIST	(double)(400.0 / tan(30 D))

#define KEY 	t->event.key.keysym.sym
#define	ANG 	t->angle
#define POSX 	t->posx
#define	POSY 	t->posy

#define	ALPHA	(t->alpha)

#define D 		* (double)(M_PI / 180.0)
#define MH 		t->map_height
#define	MW 		t->map_width

#define MAPX 	(abs((int)(x / WALL)))
#define MAPY	(abs((int)(y / WALL)))


#define	VALUE	(t->map[MAPY][MAPX])
#define SAFE	(MAPX > 0 && MAPX < MW && MAPY > 0 && MAPY < MH)
# define MAX_DISTANCE ((double)2500.0)

#define PX  	(((int)((POSX  + (8 * ix))/ WALL)))
#define PY  	(((int)((POSY - (8 * iy))/ WALL)))
#define PX2  	(((int)((POSX  - (8 * ix))/ WALL)))
#define PY2  	(((int)((POSY + (8 * iy))/ WALL)))
#define	MOVEUP	(t->map[PY][PX] != 1)
#define	MOVEDW	(t->map[PY2][PX2] != 1)

# define KNRM  "\x1B[0m"
# define KRED  "\x1B[31m"
# define KGRN  "\x1B[32m"
# define KYEL  "\x1B[33m"
# define KBLU  "\x1B[34m"
# define KMAG  "\x1B[35m"
# define KCYN  "\x1B[36m"
# define KWHT  "\x1B[37m"


typedef struct			s_color
{
	unsigned char		g;
	unsigned char		b;
	unsigned char		r;
	unsigned char		buf;
}						t_color;

typedef struct 			s_wolf
{
			// SDL STUFF
	SDL_Window			*window;
	SDL_Event			event;
	SDL_Renderer		*renderer;
	Uint32				*p;
	SDL_Texture			*screen;
	const Uint8			*keystate;
			// MAP STUFF
	int					**map;
	int					map_height;
	int					map_width;
			// CAMERA STUFF
	double				angle;
	double				alpha;
	double				posx;
	double				posy;
			// EFFECTS
	int 				trip;
	int 				trip2;
	int 				trip3;
	int  				choose;
}						t_wolf;


int			get_map(char *s, t_wolf *t);
int			ft_init(t_wolf *t);
void		draw_ray(double dx, double dy, int i, t_wolf *t);

void		raycast(t_wolf *t);
void		vector(t_wolf *t);
void		key_events(t_wolf *t);
void		move(t_wolf *t, int ix, int iy);
void		rotate(t_wolf *t);
void		create_new_renderer(t_wolf *t);
void		running(t_wolf *t);

t_color		set_color(char r, char g, char b);
Uint32 		couleur(int r, int g, int b, int m);
int			shade(t_wolf *t, double wh);
t_color		choose_color(double dx, double dy, t_wolf *t);
void		create_new_renderer(t_wolf *t);
t_color 	shad(t_color c, double dist);


#endif
// 