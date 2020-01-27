/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filecheck.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlobunet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 20:20:47 by vlobunet          #+#    #+#             */
/*   Updated: 2019/10/26 20:20:48 by vlobunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

int		check_line(char *line, t_wolf *wolf, int i)
{
	while (line[i])
	{
		if ((line[i] != '*' && line[i] != '#' &&
			line[i] != ' ' && line[i] != 'x') ||
			(line[i] == 'x' && wolf->map.user.en))
		{
			print_error(ERR_MAPINVALID);
			return (0);
		}
		if (line[i] == 'x')
		{
			wolf->map.user.en = 1;
			wolf->map.user.x = i;
			wolf->map.user.y = wolf->map.row - 1;
		}
		i++;
	}
	return (1);
}

int		map_validation(t_wolf **wolf, char *line)
{
	while (get_next_line((*wolf)->fm.fd, &line) > 0)
	{
		(*wolf)->map.row++;
		if ((*wolf)->map.col == 0)
			(*wolf)->map.col = ft_strlen(line);
		if ((*wolf)->map.col > 3 && (*wolf)->map.col == (int)ft_strlen(line))
		{
			if (check_line(line, *wolf, 0))
				ft_strdel(&line);
			else
				return (0);
		}
		else
		{
			print_error(ERR_MAPINVALID);
			return (0);
		}
	}
	if ((*wolf)->map.row < 3 || !(*wolf)->map.user.en)
	{
		print_error(ERR_MAPINVALID);
		return (0);
	}
	return (1);
}

t_wolf	*validation_atributes(char *name, int fd)
{
	t_wolf	*wolf;

	if ((fd = open(name, O_RDONLY)) == -1)
	{
		print_error(ERR_FILE);
		ft_putstrc_fd(GREEN, ERR_EXPLANATION_FILE, 2);
		return (NULL);
	}
	if ((wolf = (t_wolf *)malloc(sizeof(t_wolf))))
	{
		init_struct(wolf);
		wolf->fm.fd = fd;
		wolf->fm.str = ft_strdup(name);
		if (map_validation(&wolf, NULL))
		{
			wolf->map.src = map_create(wolf, NULL, 0, NULL);
			if (shortest_path_search(wolf))
				return (wolf);
		}
		close(fd);
	}
	return (NULL);
}
