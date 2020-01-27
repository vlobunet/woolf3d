/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlobunet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 20:35:22 by vlobunet          #+#    #+#             */
/*   Updated: 2019/10/26 20:35:24 by vlobunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

int	main(int argc, char **argv)
{
	t_wolf	*wolf;

	if (argc == 2)
	{
		g_number = 0;
		if (!(wolf = validation_atributes(argv[1], 0)))
			return (0);
		return (1);
	}
	print_error(ERR_INVALID);
	ft_putstrc_fd(GREEN, ERR_EXPLANATION_USE, 2);
	return (1);
}

int	is_movable(double x, double y, t_wolf *m)
{
	if (m->map.src[(int)y][(int)x] == EMPT || m->map.src[(int)y][(int)x] == '#')
		return (1);
	return (0);
}
