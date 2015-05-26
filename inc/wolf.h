/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student->42.fr>                +#+  +:+       +#+        */
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


#define WIDTH 	800
#define HEIGHT	600
#define	WALL	64.0
#define POV	    32
#define	FOV		60
#define	DIST	(double)(400.0 / tan(30 D))

#define KEY 	t->event.key.keysym.sym
#define	ANG 	t->angle
#define POSX 	t->posx
#define	POSY 	t->posy

#define	ALPHA	(t->alpha)

#define D 		 * (double)(M_PI / 180.0)

#define MH 		t->map_height
#define	MW 		t->map_width

#define MAPX 	(abs((int)(x / WALL)))
#define MAPY	(abs((int)(y / WALL)))


#define	VALUE	(t->map[MAPY][MAPX])
#define SAFE	(MAPX > 0 && MAPX < MW && MAPY > 0 && MAPY < MH)

#define PX  	(((int)((POSX  + ix)/ WALL)))
#define PY  	(((int)((POSY - iy)/ WALL)))
#define PX2  	(((int)((POSX  - ix)/ WALL)))
#define PY2  	(((int)((POSY + iy)/ WALL)))
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
			// MAP STUFF
	int					**map;
	int					map_height;
	int					map_width;
			// CAMERA STUFF
	double				angle;
	double				alpha;
	double				posx;
	double				posy;
//lol
	Uint32				*p;
	SDL_Texture			*screen;
}						t_wolf;

void		running(t_wolf *t);
int			get_map(char *s, t_wolf *t);
int			ft_init(t_wolf *t);
void		raycast(t_wolf *t);
void		key_events(t_wolf *t);


int			draw_ray(double dx, double dy, int i, t_wolf *t);
// static double		raycast_vertical(double tang, t_wolf *t);
// static double		raycast_horizontal(double tang, t_wolf *t);


// modif raph
void	create_new_renderer(t_wolf *t);

#endif
// 