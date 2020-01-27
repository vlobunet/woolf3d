/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlobunet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 09:00:13 by vlobunet          #+#    #+#             */
/*   Updated: 2019/10/27 09:00:15 by vlobunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	init_struct(t_wolf *wolf)
{
	(*wolf).fm.fd = 0;
	(*wolf).fm.str = NULL;
	(*wolf).map.row = 0;
	(*wolf).map.col = 0;
	(*wolf).map.user.en = 0;
	(*wolf).map.user.x = 0;
	(*wolf).map.user.y = 0;
	(*wolf).map.src = NULL;
}

void	ft_freestrarr(char **arr)
{
	int	i;

	if (!arr)
		return ;
	i = -1;
	while (arr[++i])
		free(arr[i]);
	free(arr);
	arr = NULL;
}

void	destroy_struct(t_wolf *wolf)
{
	ft_freestrarr(wolf->map.src);
	ft_strdel(&wolf->fm.str);
	lst_dell_all(wolf->path);
	free(wolf->t);
	free(wolf);
	exit(0);
}
