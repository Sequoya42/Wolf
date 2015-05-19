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

#define INCR	10
#define WIDTH 	800
#define HEIGHT	600
#define INCR	10
#define	WALL	64
#define POV		32
#define	FOV		60
#define	DIST	(WIDTH / tan(30 D))
#define ARC		(FOV / WIDTH)

#define KEY 	S->event.key.keysym.sym
#define	ANG 	(S->angle)
#define POSX 	(S->posy * WALL + POV)
#define	POSY 	(S->posx * WALL + POV)
#define FORW 	S->forward
#define BACK 	S->backward

#define	ALPHA	(S->alpha)
#define XA 		(WALL / (tan(ALPHA D)))
#define YA		(WALL * (tan(ALPHA D)))

#define W 		64
#define Y		S->posy
#define X 		S->posx
#define D 		/ 57.2
#define	VALUE	S->map[(int)Y][(int)X]
#define MH 		S->map_height
#define	MW 		S->map_width


# define KNRM  "\x1B[0m"
# define KRED  "\x1B[31m"
# define KGRN  "\x1B[32m"
# define KYEL  "\x1B[33m"
# define KBLU  "\x1B[34m"
# define KMAG  "\x1B[35m"
# define KCYN  "\x1B[36m"
# define KWHT  "\x1B[37m"


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
	double				ray_x;
	double				ray_y;
	double				forward;
	double				backward;


}						t_wolf;

t_wolf		*singleton(void);

void		running(void);
int			get_map(char *s);
int			ft_init(void);
void		raycast(void);
void		key_events(void);


int			draw_ray(double length, int i);
double		raycast_vertical(void);
double		raycast_horizontal(void);

/* TEMPORAIRE */
void		aff_map_term(void);
void		test_rendering(void);
/* TEMPORAIRE */

#endif
