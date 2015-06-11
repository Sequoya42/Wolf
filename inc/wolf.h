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
# define WOLF_H

# include <fcntl.h>
# include <math.h>
# include "libft.h"
# include "SDL2/SDL.h"
# include <time.h>
# include <stdio.h> // REMOVE THIS

# define WIDTH 	800
# define HEIGHT	(t->height)
# define WALL	512.0
# define FOV		60
# define DIST	(((double)(400) / tan((FOV / 2) D)))

# define KEY 	t->event.key.keysym.sym
# define ANG 	t->angle
# define POSX 	t->posx
# define POSY 	t->posy

# define ALPHA	(t->alpha)

# define D 		* (double)(M_PI / 180.0)
# define MH 	t->map_height
# define MW 	t->map_width

# define MAPX 	(abs((int)(t->rxh / WALL)))
# define MAPY	(abs((int)(t->ryh / WALL)))
# define MAPXV 	(abs((int)(t->rxv / WALL)))
# define MAPYV	(abs((int)(t->ryv / WALL)))

# define VALUE	(t->map[MAPY][MAPX])
# define VALUE2	(t->map[MAPYV][MAPXV])
# define SAFE	(MAPX > 0 && MAPX < MW && MAPY > 0 && MAPY < MH)
# define SAFE2	(MAPXV > 0 && MAPXV < MW && MAPYV > 0 && MAPYV < MH)
# define MAX_DISTANCE ((double)25000.0)

//MOVEMENT
# define PX  	(((int)((POSX  + (4  * ix))/ WALL)))
# define PY  	(((int)((POSY - (4 * iy))/ WALL)))
# define PX2  	(((int)((POSX  - (4  * ix))/ WALL)))
# define PY2  	(((int)((POSY + (4 * iy))/ WALL)))
// CREATE BLOCK
# define PXN  	(((int)((POSX  + (17 * ix))/ WALL)))
# define PYN  	(((int)((POSY - (17 * iy))/ WALL)))


# define MOVEUP	(t->map[PY][PX] != 1)
# define MOVEDW	(t->map[PY2][PX2] != 1)

# define TX 	((int)(dx)) % t->sf->w
# define TY 	((int)(dy)) % t->sf->h

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

typedef struct			s_surface
{
	SDL_Surface			*surf;
	int					w;
	int					h;
	t_color				**pix;
}						t_surface;

typedef struct 			s_wolf
{
			// SDL STUFF
	SDL_Window			*window;
	t_surface			*sw;
	t_surface			*sw2;
	t_surface			*sf;
	t_surface			*sc;
	t_surface			*st;
	SDL_Event			event;
	SDL_Renderer		*renderer;
	Uint32				*p;
	SDL_Texture			*screen;
	const Uint8			*keystate;
			// MAP STUFF
	int					**map;
	int					map_height;
	int					map_width;
	char				*name;
			// CAMERA STUFF
	double				angle;
	double				alpha;
	double				posx;
	double				posy;
			//INTERSECTION RAY
	double				ryv;
	double				rxv;
	double				ryh;
	double				rxh;
		// WALL HEIGHT AND DIST WALL
	double				wh;
	double				dx;
	double				dy;
			//INCREMENT RAY VALUE
	double				ixv;
	double				iyv;
	double				ixh;
	double 				iyh;
			// EFFECTS
	int 				trip;
	int 				neon;
	int 				height;
	int  				cren;
	int 				text;
	t_color				c;
}						t_wolf;


int			get_map(char *s, t_wolf *t);
int			ft_init(t_wolf *t);
void		draw_ray(int i, t_wolf *t);

void		raycast(t_wolf *t);
void		vector(t_wolf *t);
void		key_events(t_wolf *t, int ix, int iy);
void		move(t_wolf *t, int ix, int iy);
void		rotate(t_wolf *t);
void		create_new_renderer(t_wolf *t);
void		running(t_wolf *t);


Uint32 		couleur(int r, int g, int b, int m);
t_color		set_color(char r, char g, char b);
t_color 	shad(t_color c, double dist);
t_color		choose_color(double dx, double dy, t_wolf *t);
int			shade(t_wolf *t, double wh);
void		create_new_renderer(t_wolf *t);


void				del_surface(t_surface **surface);
t_surface			*ft_loadbmp(const char *path);

void		textured_wall(t_wolf *t, int x);
void		textured_floor(t_wolf *t, int x);
void		textured_ceiling(t_wolf *t, int x);

void		teleport(t_wolf *t);

void		choose_map(t_wolf *t);
void		change_map(t_wolf *t);
void				del_surface(t_surface **surface);

#endif
// 