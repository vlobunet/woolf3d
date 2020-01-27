/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_sheme.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlobunet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 15:46:11 by vlobunet          #+#    #+#             */
/*   Updated: 2019/10/27 15:46:13 by vlobunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

int		create_scheme_1(t_wolf *w, int i, int ret)
{
	int fd[4];

	fd[0] = open("textures/wall.xpm", O_RDONLY);
	fd[1] = open("textures/stone.xpm", O_RDONLY);
	fd[2] = open("textures/ceilling.xpm", O_RDONLY);
	if (fd[0] != -1 && fd[1] != -1 && fd[2] != -1)
	{
		w->t->scheme[i].wall = ft_strdup("textures/wall.xpm");
		w->t->scheme[i].floor = ft_strdup("textures/stone.xpm");
		w->t->scheme[i].ceiling = ft_strdup("textures/ceilling.xpm");
		ret = 1;
	}
	fd[0] != -1 ? close(fd[0]) : 0;
	fd[1] != -1 ? close(fd[1]) : 0;
	fd[2] != -1 ? close(fd[2]) : 0;
	return (ret);
}

int		create_scheme_2(t_wolf *w, int i, int ret)
{
	int fd[4];

	fd[0] = open("textures/green.xpm", O_RDONLY);
	fd[1] = open("textures/trava.xpm", O_RDONLY);
	fd[2] = open("textures/ise.xpm", O_RDONLY);
	if (fd[0] != -1 && fd[1] != -1 && fd[2] != -1)
	{
		w->t->scheme[i].wall = ft_strdup("textures/green.xpm");
		w->t->scheme[i].floor = ft_strdup("textures/trava.xpm");
		w->t->scheme[i].ceiling = ft_strdup("textures/ise.xpm");
		ret = 1;
	}
	fd[0] != -1 ? close(fd[0]) : 0;
	fd[1] != -1 ? close(fd[1]) : 0;
	fd[2] != -1 ? close(fd[2]) : 0;
	return (ret);
}

int		create_scheme_3(t_wolf *w, int i, int ret)
{
	int fd[4];

	fd[0] = open("textures/getty.xpm", O_RDONLY);
	fd[1] = open("textures/ice.xpm", O_RDONLY);
	fd[2] = open("textures/starssky.xpm", O_RDONLY);
	if (fd[0] != -1 && fd[1] != -1 && fd[2] != -1)
	{
		w->t->scheme[i].wall = ft_strdup("textures/getty.xpm");
		w->t->scheme[i].floor = ft_strdup("textures/ice.xpm");
		w->t->scheme[i].ceiling = ft_strdup("textures/starssky.xpm");
		ret = 1;
	}
	fd[0] != -1 ? close(fd[0]) : 0;
	fd[1] != -1 ? close(fd[1]) : 0;
	fd[2] != -1 ? close(fd[2]) : 0;
	return (ret);
}

void	get_sheme(t_wolf *w)
{
	int i;

	i = 0;
	w->t->scheme = (t_scheme *)malloc(sizeof(t_scheme) * 4);
	i += (create_scheme_1(w, i, 0) ? 1 : 0);
	i += (create_scheme_2(w, i, 0) ? 1 : 0);
	i += (create_scheme_3(w, i, 0) ? 1 : 0);
}
