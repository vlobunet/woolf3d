/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_create.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlobunet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 20:41:35 by vlobunet          #+#    #+#             */
/*   Updated: 2019/10/26 20:41:37 by vlobunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

char	**map_create(t_wolf *wolf, char **ret, int i, char *line)
{
	close(wolf->fm.fd);
	if ((wolf->fm.fd = open(wolf->fm.str, O_RDONLY)) != -1)
	{
		ret = (char **)malloc(sizeof(char *) * wolf->map.row + 1);
		while (get_next_line(wolf->fm.fd, &line) > 0)
		{
			ret[i++] = ft_strdup(line);
			ft_strdel(&line);
		}
		ret[i] = NULL;
		ret[(int)wolf->map.user.y][(int)wolf->map.user.x] = ' ';
		close(wolf->fm.fd);
		return (ret);
	}
	return (NULL);
}
