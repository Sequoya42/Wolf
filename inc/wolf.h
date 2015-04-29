/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/26 19:09:40 by rbaum             #+#    #+#             */
/*   Updated: 2015/04/29 12:13:03 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
#define WOLF_H

# include <fcntl.h>
# include <math.h>
# include "libft.h"
# include "SDL2.framework/Headers/SDL.h"

# define S (singleton())

#define WIDTH 	800
#define HEIGHT	600

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
	SDL_Window			*window;
	SDL_Event			event;
	SDL_Renderer		*render;
	int					**map;

}						t_wolf;

#endif