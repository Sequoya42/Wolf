/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/29 13:08:33 by rbaum             #+#    #+#             */
/*   Updated: 2015/05/14 20:23:22 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	init_map(void)
{
	int i;

	i = 0;
	if ((S->map = malloc(sizeof(int *) * (S->map_height + 1))) == NULL)
		return ;
	while (i <= S->map_height)
	{
		if ((S->map[i] = malloc(sizeof(int) * (S->map_width + 1))) == NULL)
			return ;
		i++;
	}
	
}

int		get_length(char *m)
{
	int		fd;
	int		z;
	char	*line;
	
	S->map_height = 0;
	if ((fd = open(m, O_RDONLY)) == -1)
		return (ft_error(NULL, NULL, "Failed to open"));
	while (get_next_line(fd, &line))
	{
		z = 0;
		while (line[z++])
			S->map_width++;
		S->map_height++;
	}
	close(fd);
	S->map_width /= S->map_height;
	init_map();
	return (1);
}

void		read_map(char *m)
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
			S->map[y][x] = line[i] - 48;
			x++;
			i++;
		}
		y++;
		x = 0;
	}
	close(fd);
}

int		get_map(char *s)
{
	s = "maps/map01";//Remove to choose map
	if (get_length(s) == -1)
		return (-1);
	read_map(s);
	POSX = MW / 2.0 * (double)WALL;
	POSY = MH / 2.0 * (double)WALL;
	return (0);
}
