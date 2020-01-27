/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlobunet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 20:41:01 by vlobunet          #+#    #+#             */
/*   Updated: 2019/10/26 20:41:03 by vlobunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	add_floor(t_wolf *m)
{
	m->mlx.data[4 * (W * m->mlx.r.y + m->mlx.r.x) + 1] =
	m->t[1].img_ptr[(4 * (m->t->w * m->mlx.r.floor_texy +
		m->mlx.r.floor_texx)) + 1];
	m->mlx.data[4 * (W * m->mlx.r.y + m->mlx.r.x) + 2] =
	m->t[1].img_ptr[(4 * (m->t->w * m->mlx.r.floor_texy +
		m->mlx.r.floor_texx)) + 2];
	m->mlx.data[4 * (W * m->mlx.r.y + m->mlx.r.x)] =
	m->t[1].img_ptr[(4 * (m->t->w * m->mlx.r.floor_texy +
		m->mlx.r.floor_texx))];
}

void	ceiling(t_wolf *m)
{
	m->mlx.data[4 * (W * (H - m->mlx.r.y) + m->mlx.r.x)] =
	m->t[2].img_ptr[(4 * (m->t->w * m->mlx.r.floor_texy +
		m->mlx.r.floor_texx))];
	m->mlx.data[4 * (W * (H - m->mlx.r.y) + m->mlx.r.x) + 1] =
	m->t[2].img_ptr[(4 * (m->t->w * m->mlx.r.floor_texy +
		m->mlx.r.floor_texx)) + 1];
	m->mlx.data[4 * (W * (H - m->mlx.r.y) + m->mlx.r.x) + 2] =
	m->t[2].img_ptr[(4 * (m->t->w * m->mlx.r.floor_texy +
		m->mlx.r.floor_texx)) + 2];
}

void	floor_render_2(t_wolf *m)
{
	double	dist;
	double	w;
	double	fx;
	double	fy;

	m->mlx.r.wall_dst = m->mlx.r.pwd;
	m->mlx.r.player_dst = 0.0;
	m->mlx.r.y = m->mlx.r.end + 1;
	(m->mlx.r.end < 0) ? (m->mlx.r.end = H) : 0;
	while (m->mlx.r.y < H)
	{
		dist = H / (2.0 * m->mlx.r.y - H);
		w = (dist - m->mlx.r.player_dst) /
		(m->mlx.r.wall_dst - m->mlx.r.player_dst);
		fx = w * m->mlx.r.floorxwall + (1.0 - w) * m->mlx.r.pos.x;
		fy = w * m->mlx.r.floorywall + (1.0 - w) * m->mlx.r.pos.y;
		m->mlx.r.floor_texx = (int)(fx * m->t->w) % m->t->w;
		m->mlx.r.floor_texy = (int)(fy * m->t->h) % m->t->h;
		add_floor(m);
		ceiling(m);
		m->mlx.r.y++;
	}
}

void	floor_render(t_wolf *m)
{
	if (!m->mlx.r.hit_side && m->mlx.r.dir.x > 0)
	{
		m->mlx.r.floorxwall = m->mlx.r.map.x;
		m->mlx.r.floorywall = m->mlx.r.map.y + m->mlx.r.wall_x;
	}
	else if (!m->mlx.r.hit_side && m->mlx.r.dir.x < 0)
	{
		m->mlx.r.floorxwall = m->mlx.r.map.x + 1.0;
		m->mlx.r.floorywall = m->mlx.r.map.y + m->mlx.r.wall_x;
	}
	else if (m->mlx.r.hit_side == 1 && m->mlx.r.dir.y > 0)
	{
		m->mlx.r.floorxwall = m->mlx.r.map.x + m->mlx.r.wall_x;
		m->mlx.r.floorywall = m->mlx.r.map.y;
	}
	else
	{
		m->mlx.r.floorxwall = m->mlx.r.map.x + m->mlx.r.wall_x;
		m->mlx.r.floorywall = m->mlx.r.map.y + 1.0;
	}
	floor_render_2(m);
}
