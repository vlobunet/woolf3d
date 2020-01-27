/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlobunet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 08:59:23 by vlobunet          #+#    #+#             */
/*   Updated: 2019/10/27 08:59:26 by vlobunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	put_texture_to_img(t_wolf *m, int x, int y, int n)
{
	m->mlx.data[4 * (W * y + x) + 1] = m->t[n].img_ptr
	[(4 * (m->t[n].w * m->mlx.r.texture_y + m->mlx.r.texture_x)) + 1];
	m->mlx.data[4 * (W * y + x) + 2] = m->t[n].img_ptr
	[(4 * (m->t[n].w * m->mlx.r.texture_y + m->mlx.r.texture_x)) + 2];
	m->mlx.data[4 * (W * y + x)] = m->t[n].img_ptr
	[(4 * (m->t[n].w * m->mlx.r.texture_y + m->mlx.r.texture_x))];
}

void	wall(t_wolf *m, int x, int n)
{
	int	y;

	y = m->mlx.r.start;
	while (y <= m->mlx.r.end && y < W)
	{
		m->mlx.r.texture_y = ((m->mlx.r.d *
			m->t[n].h / m->mlx.r.height) / 256);
		m->mlx.r.d = y * 256 - H * 128 + m->mlx.r.height * 128;
		put_texture_to_img(m, x, y++, n);
	}
	m->mlx.r.y = y;
}
