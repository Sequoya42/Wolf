/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student->42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/15 18:51:17 by rbaum             #+#    #+#             */
/*   Updated: 2015/05/15 18:51:17 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void		move_right(t_wolf *t)
{
	if (KEY == SDLK_RIGHT)
	{
		ANG -= 3.6;
		while (ANG < 0)
			ANG += 360;
	}
}

void		move_left(t_wolf *t)
{
	if (KEY == SDLK_LEFT)
	{
		ANG += 3.6;
		while (ANG >= 360)
			ANG -= 360;
	}
}

void		move_forward(t_wolf *t, int ix, int iy)
{
	if (KEY == SDLK_UP)// && MOVEUP)// && MOVEUP)
	{
		POSX += ix;
		POSY -= iy;
	} 
}

void		move_backward(t_wolf *t, int ix, int iy)
{
	if (KEY == SDLK_DOWN)// && MOVEDW)// && MOVEDW)
	{
		POSX -= ix;
		POSY += iy;
	}
}

void		key_events(t_wolf *t)
{
	int inc;
	int	ix;
	int	iy;

	inc = 16;
	ix = cos(ANG D) * inc;
	iy = sin(ANG D) * inc;
	if (t->event.type == SDL_KEYDOWN)
	{
		if (KEY == 27)
		{
			SDL_DestroyWindow(t->window);
			SDL_Quit();
			exit(1);
		}
		move_right(t);
		move_left(t);
		move_forward(t, ix, iy);
		move_backward(t, ix, iy);
		raycast(t);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student->42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/29 13:08:33 by rbaum             #+#    #+#             */
/*   Updated: 2015/05/14 20:23:22 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	init_map(t_wolf *t)
{
	int i;

	i = 0;
	if ((t->map = malloc(sizeof(int *) * (MH + 1))) == NULL)
		return ;
	while (i <= MH)
	{
		if ((t->map[i] = malloc(sizeof(int) * (MW + 1))) == NULL)
			return ;
		i++;
	}
	
}

int		get_length(char *m, t_wolf *t)
{
	int		fd;
	int		z;
	char	*line;
	
	MH = 0;
	if ((fd = open(m, O_RDONLY)) == -1)
		return (ft_error(NULL, NULL, "Failed to open"));
	while (get_next_line(fd, &line))
	{
		z = 0;
		while (line[z++])
			MW++;
		MH++;
		free(line);
	}
	close(fd);
	free(line);
	MW /= MH;
	init_map(t);
	return (1);
}

void		read_map(char *m, t_wolf *t)
{
	int		fd;
	int		y;
	int		x;
	int		i;
	char	*line;
	
	y = 0;
	x = 0;
	fd = open(m, O_RDONLY);
	while (get_next_line(fd, &line))
	{
		i = 0;
		while (line[i])
		{
			t->map[y][x] = line[i] - 48;
			x++;
			i++;
		}
		free(line);
		y++;
		x = 0;
	}
	free(line);
	close(fd);
}

int		get_map(char *s, t_wolf *t)
{
	s = "maps/map01";//Remove to choose map
	if (get_length(s, t) == -1)
		return (-1);
	read_map(s, t);
	POSX = ((int)WALL * MW / 2);
	POSY = ((int)WALL * MH / 2);
	return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/26 19:19:29 by rbaum             #+#    #+#             */
/*   Updated: 2015/05/14 20:24:12 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int			main(int ac, char **av)
{
	t_wolf	t;

	if (ac < 1)//Change to two to change maps
		return (0);
		if ((ft_init(&t)) == -1)
		return (-1);
	if (get_map(av[1], &t) == -1)
		return (-1);
	running(&t);
	return 0;
}

int		ft_init(t_wolf *t)
{
	ANG = 90.4;
	if ((SDL_Init(SDL_INIT_EVERYTHING)) == -1)
	return (ft_error(NULL, NULL, "Cannot init SDL"));
	t->window = SDL_CreateWindow
	("test", 500, 300, WIDTH, HEIGHT, 0);
	t->renderer = SDL_CreateRenderer(t->window, -1, 
		SDL_RENDERER_ACCELERATED);
	SDL_RenderSetLogicalSize(t->renderer, WIDTH, HEIGHT);
	create_new_renderer(t);
	return (0);
}

void		running(t_wolf *t)
{
	raycast(t);
	while (1)
	{
		while (SDL_PollEvent(&t->event))
			key_events(t);
	}
}/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast->c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student->42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/16 17:52:30 by rbaum             #+#    #+#             */
/*   Updated: 2015/05/19 22:28:22 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static double		raycast_horizontal(double tang, t_wolf *t)
{
	double			y;
	double			x;
	double			ya;
	double			xa;
	double			dx;

	int tx = (int)POSX;
	int ty = (int)POSY;
	 printf("POSX %d\t POSY %d\t", POSX, POSY);
	 	 // printf("POSX %f\t POSY %f\t", POSX, POSY);
	 	printf("tx %d\tty %d\n",tx, ty);
	 	printf("MW : %d\n", MW);
	ya = (ALPHA > 180.0) ? 64.0 : -64.0;
	xa = - ya / tang;
	y = (double)(ty - ((int)ty % 64));
	y = (ALPHA < 180.0) ? y - 0.0001 : y + 64.0;
	x = tx + ((ty - y) / tang);
	while (SAFE && VALUE != 1)
	{
		x += xa;
		y += ya;
	}
	dx = fabs(((tx - x) / cos(ALPHA  D)));
	dx *= (cos(((ALPHA - ANG) D)));
	return (dx);
}

static double		raycast_vertical(double tang, t_wolf *t)
{
	double 			x;
	double			y;
	double			xa;
	double			ya;
	double			dy;

	int	tx = (int)POSX;
	int	ty = (int)POSY;
	xa = (ALPHA > 90.0 && ALPHA < 270.0) ? -64.0 :  64.0;
	ya = - xa * tang;
	x = (double)(tx - ((int)tx % 64));
	x = (ALPHA < 90.0 || ALPHA > 270.0) ? x + 64.0 : x - 0.0001;
	y = ty + ((tx - x) * tang);
	while (SAFE && VALUE != 1)
	{
		x += xa;
		y += ya;
	}
	dy = fabs(((tx - x) / cos(ALPHA D)));
	 dy *= (cos(((ALPHA - ANG)) D));
	return (dy);
}

void				raycast(t_wolf *t)
{
	int				i;
	double			h;
	double			v;
	double			arc;
	double			tang;

	i = WIDTH;
	arc = 0.075;
	ALPHA = ANG - 30.0;
	SDL_RenderClear(t->renderer);
	tang = (double)tan(ALPHA D);
	SDL_RenderClear(t->renderer);
	while (i >= 0)
	{
		h = raycast_horizontal(tang, t);
		v = raycast_vertical(tang, t);
		draw_ray(h, v, i, t);
		ALPHA += arc;
		if (ALPHA >= 360)
			ALPHA -= 360;
		if (ALPHA < 0)
			ALPHA += 360;
		tang = (double)tan(ALPHA D);
		i--;
	}
	SDL_Delay(16);
	SDL_UpdateTexture(t->screen, NULL, t->p, WIDTH * sizeof(Uint32));
	SDL_RenderCopy(t->renderer, t->screen, NULL, NULL);
	SDL_RenderPresent(t->renderer);
	ft_bzero(t->p, sizeof(Uint32) * WIDTH * HEIGHT);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student->42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/16 17:56:09 by rbaum             #+#    #+#             */
/*   Updated: 2015/05/16 17:56:13 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

t_color		set_color(char r, char g, char b)
{
	t_color		c;

	c.r = r;
	c.g = g;
	c.b = b;
	return (c);
}

t_color		choose_color(double dx, double dy, t_wolf *t)
{
	t_color c;
	if (dx < dy && ALPHA >= 0 && ALPHA < 180)
		c = set_color(138, 43, 226);//blue violet
	else if (dx < dy && ALPHA >= 180 && ALPHA < 360)
		c = set_color(165, 42, 42); // brown red
	else if (dy < dx && ALPHA >= 90  && ALPHA < 270)
		c = set_color(205, 173, 0); // gold 3
	else
		c = set_color(0, 102, 124);// mellow blue
	return (c);

}

void		create_new_renderer(t_wolf *t)
{
	t->p = (Uint32 *)malloc(sizeof(Uint32) * WIDTH * HEIGHT);
	t->screen = SDL_CreateTexture(t->renderer, SDL_PIXELFORMAT_ARGB8888,
		SDL_TEXTUREACCESS_STREAMING, WIDTH, HEIGHT);
}

Uint32 couleur(int r, int g, int b)
{ 
	return (((r<<8)+ g)<<8 )+ b; 
}

int			draw_ray(double dx, double dy, int x, t_wolf *t)
{
	t_color	c;
	double	wh;
	int 	y;
	int		z;
	int		i;

	c = choose_color(dx, dy, t);
	wh = (dx < dy) ? dx : dy;
	wh = (WALL / wh) * DIST;
	y = (HEIGHT / 2) - (wh / 2);
	z = ((HEIGHT / 2) + (wh / 2));
	i = 0;
	while (i++ < y)
		 t->p[x + (i * WIDTH)] = couleur(44, 47, 94);
	if (y < 0)
		y = 0;
	while (y < WIDTH && y < z)
		t->p[x + (y++ * WIDTH)] = couleur(c.r, c.g, c.b);
	while (z++ < WIDTH)
		t->p[x + z * WIDTH] = couleur(102, 51, 0);
	return (0);
	// REPLACE WIDTH PER HEIGHT TO OBTAIN DRUGGY MODE
}