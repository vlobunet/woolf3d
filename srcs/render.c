/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlobunet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 08:36:36 by vlobunet          #+#    #+#             */
/*   Updated: 2019/10/27 08:36:38 by vlobunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	init_step_2(t_wolf *m)
{
	while (!m->mlx.r.hit)
	{
		if (m->mlx.r.side.x < m->mlx.r.side.y)
		{
			m->mlx.r.side.x += m->mlx.r.delta.x;
			m->mlx.r.map.x += m->mlx.r.step_x;
			m->mlx.r.hit_side = 0;
		}
		else
		{
			m->mlx.r.side.y += m->mlx.r.delta.y;
			m->mlx.r.map.y += m->mlx.r.step_y;
			m->mlx.r.hit_side = 1;
		}
		if (m->map.src[m->mlx.r.map.y][m->mlx.r.map.x] &&
			m->map.src[m->mlx.r.map.y][m->mlx.r.map.x] > 32)
			m->mlx.r.hit = 1;
	}
	if (!m->mlx.r.hit_side)
		m->mlx.r.pwd = (m->mlx.r.map.x - m->mlx.r.pos.x +
			(1 - m->mlx.r.step_x) / 2) / m->mlx.r.dir.x;
	else
		m->mlx.r.pwd = (m->mlx.r.map.y - m->mlx.r.pos.y +
			(1 - m->mlx.r.step_y) / 2) / m->mlx.r.dir.y;
}

void	init_step(t_wolf *m)
{
	if (m->mlx.r.dir.y < 0)
	{
		m->mlx.r.step_y = -1;
		m->mlx.r.side.y =
		(m->mlx.r.pos.y - (int)m->mlx.r.pos.y) * m->mlx.r.delta.y;
	}
	else
	{
		m->mlx.r.step_y = 1;
		m->mlx.r.side.y =
		((int)m->mlx.r.pos.y + 1.0 - m->mlx.r.pos.y) * m->mlx.r.delta.y;
	}
	if (m->mlx.r.dir.x < 0)
	{
		m->mlx.r.step_x = -1;
		m->mlx.r.side.x =
		(m->mlx.r.pos.x - (int)m->mlx.r.pos.x) * m->mlx.r.delta.x;
	}
	else
	{
		m->mlx.r.step_x = 1;
		m->mlx.r.side.x =
		((int)m->mlx.r.pos.x + 1.0 - m->mlx.r.pos.x) * m->mlx.r.delta.x;
	}
	init_step_2(m);
}

void	set_variables(t_wolf *m)
{
	m->mlx.r.camera = 2 * m->mlx.r.x / (double)W - 1;
	m->mlx.r.dir.x = m->mlx.cam_pl.x +
	m->mlx.cam_vector.x * m->mlx.r.camera;
	m->mlx.r.dir.y = m->mlx.cam_pl.y +
	m->mlx.cam_vector.y * m->mlx.r.camera;
	m->mlx.r.pos.x = m->map.user.x;
	m->mlx.r.pos.y = m->map.user.y;
	m->mlx.r.delta.x = SQRT(m->mlx.r.dir.y, m->mlx.r.dir.x);
	m->mlx.r.delta.y = SQRT(m->mlx.r.dir.x, m->mlx.r.dir.y);
	m->mlx.r.map.x = m->mlx.r.pos.x;
	m->mlx.r.map.y = m->mlx.r.pos.y;
}

void	raycasting(t_wolf *m)
{
	while (m->mlx.r.x < W)
	{
		set_variables(m);
		init_step(m);
		m->mlx.r.height = (int)(H / m->mlx.r.pwd);
		m->mlx.r.start = -m->mlx.r.height / 2 + H / 2;
		m->mlx.r.start = CLAMP(m->mlx.r.start, 1, H - 1);
		m->mlx.r.end = m->mlx.r.height / 2 + H / 2;
		m->mlx.r.end = CLAMP(m->mlx.r.end, 1, H - 1);
		m->mlx.r.tx_num = 0;
		get_texture(m);
		set_texture(m);
		floor_render(m);
		m->mlx.r.hit = 0;
		m->mlx.r.x++;
	}
}
