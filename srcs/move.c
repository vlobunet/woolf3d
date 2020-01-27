/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlobunet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 22:25:11 by vlobunet          #+#    #+#             */
/*   Updated: 2019/10/26 22:25:14 by vlobunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	go_forward(t_wolf *m)
{
	int	x[4];

	m->mlx.move.move_f = 0;
	x[0] = m->map.user.x + m->mlx.cam_pl.x *
	m->mlx.s_move + 0.33 * m->mlx.cam_pl.x;
	x[1] = m->map.user.y;
	x[2] = m->map.user.x;
	x[3] = m->map.user.y + m->mlx.cam_pl.y *
	m->mlx.s_move + 0.33 * m->mlx.cam_pl.y;
	if (is_movable(x[0], x[1], m))
		m->map.user.x += m->mlx.cam_pl.x * m->mlx.s_move;
	if (is_movable(x[2], x[3], m))
		m->map.user.y += m->mlx.cam_pl.y * m->mlx.s_move;
}

void	go_backwards(t_wolf *m)
{
	int	x[4];

	m->mlx.move.move_b = 0;
	x[0] = m->map.user.x - m->mlx.cam_pl.x *
	m->mlx.s_move - 0.33 * m->mlx.cam_pl.x;
	x[1] = m->map.user.y;
	x[2] = m->map.user.x;
	x[3] = m->map.user.y - m->mlx.cam_pl.y *
	m->mlx.s_move - 0.33 * m->mlx.cam_pl.y;
	if (is_movable(x[0], x[1], m))
		m->map.user.x -= m->mlx.cam_pl.x * m->mlx.s_move;
	if (is_movable(x[2], x[3], m))
		m->map.user.y -= m->mlx.cam_pl.y * m->mlx.s_move;
}

t_vect	rotate(t_vect v, double ang)
{
	double	temp;

	temp = v.x;
	v.x = v.x * cos(ang) - v.y * sin(ang);
	v.y = temp * sin(ang) + v.y * cos(ang);
	return (v);
}

void	rot_left(t_wolf *m)
{
	m->mlx.move.move_l = 0;
	m->mlx.cam_pl = rotate(m->mlx.cam_pl, -m->mlx.s_rot);
	m->mlx.cam_vector = rotate(m->mlx.cam_vector, -m->mlx.s_rot);
}

void	rot_right(t_wolf *m)
{
	m->mlx.move.move_r = 0;
	m->mlx.cam_pl = rotate(m->mlx.cam_pl, m->mlx.s_rot);
	m->mlx.cam_vector = rotate(m->mlx.cam_vector, m->mlx.s_rot);
}
