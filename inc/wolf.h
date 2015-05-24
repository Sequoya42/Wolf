/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
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
# include <stdio.h> // REMOVE THIS

# define S (singleton())

#define WIDTH 	800
#define HEIGHT	600
#define	WALL	(double)(64.0)
 #define POV		32
#define	FOV		60
#define	DIST	(double)(400.0 / tan(30 D))

#define KEY 	S->event.key.keysym.sym
#define	ANG 	S->angle
#define POSX 	S->posx
#define	POSY 	S->posy
#define FORW 	S->forward
#define BACK 	S->backward

#define	ALPHA	(S->alpha)
#define XA 		(64.0 / (tan(ALPHA D)))
#define YA		(64.0 * (tan(ALPHA D)))

#define D 		 * (double)(M_PI / 180.0)

#define MH 		S->map_height
#define	MW 		S->map_width

#define MAPX 	(abs((int)(x / WALL)))
#define MAPY	(abs((int)(y / WALL)))
#define PX  	(abs((int)(POSX / WALL)))
#define PY  	(abs((int)(POSY / WALL)))

#define	VALUE	(S->map[MAPY][MAPX])
#define SAFE	(MAPX > 0 && MAPX < MW && MAPY > 0 && MAPY < MH)
#define	MOVEUP	(S->map[PX][PY] != 1 && S->map[PX + 4][PY] != 1 && S->map[PX][PY + 4] != 1)
#define	MOVEDW	(S->map[PX][PY] != 1 && S->map[PX - 4][PY] != 1 && S->map[PX][PY - ] != 1)

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
	char				g;
	char				b;
	char				r;
}						t_color;

typedef struct 			s_wolf
{
			// SDL STUFF
	SDL_Window			*window;
	SDL_Event			event;
	SDL_Renderer		*renderer;
	SDL_Rect			rect;
	SDL_Point			points;
			// MAP STUFF
	int					**map;
	int					map_height;
	int					map_width;
			// CAMERA STUFF
	double				angle;
	double				alpha;
	int 				posx;
	int 				posy;
}						t_wolf;

t_wolf		*singleton(void);

void		running(void);
int			get_map(char *s);
int			ft_init(void);
void		raycast(void);
void		key_events(void);


int			draw_ray(double dx, double dy, int i);
double		raycast_vertical(double tang);
double		raycast_horizontal(double tang);

/* TEMPORAIRE */
void		aff_map_term(void);
void		test_rendering(void);
/* TEMPORAIRE */

#endif
