/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/12 22:34:44 by rbaum             #+#    #+#             */
/*   Updated: 2015/06/12 22:35:53 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void		free_map(int ***tab, t_wolf *t)
{
	int		i;

	i = MH;
	if (*tab != NULL)
	{
		while (i >= 0)
		{
			free((*tab)[i]);
			(*tab)[i] = NULL;
			i--;
		}
		free(*tab);
		*tab = NULL;
	}
}

void		init_map(t_wolf *t)
{
	int		i;

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

int			get_length(char *m, t_wolf *t)
{
	int		fd;
	int		z;
	char	*line;

	MH = -1;
	MW = -1;
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
	free(line);
	close(fd);
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

int			get_map(char *s, t_wolf *t)
{
	free_map(&t->map, t);
	if (get_length(s, t) == -1)
		return (-1);
	read_map(s, t);
	POSX = ((int)WALL * MW / 2);
	POSY = ((int)WALL * MH / 2);
	return (0);
}
