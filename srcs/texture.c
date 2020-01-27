/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlobunet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 08:58:13 by vlobunet          #+#    #+#             */
/*   Updated: 2019/10/27 08:58:15 by vlobunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	get_texture(t_wolf *m)
{
	if (m->map.src[m->mlx.r.map.y][m->mlx.r.map.x] == '*')
		m->mlx.r.tx_num = 1;
	else if (m->map.src[m->mlx.r.map.y][m->mlx.r.map.x] == '#')
		m->mlx.r.tx_num = 4;
	else
		m->mlx.r.tx_num = 0;
}

int		init_texture(t_wolf *m, int nbr, char *path)
{
	m->t[nbr].p = mlx_xpm_file_to_image(m->mlx.mlx,
		path, &m->t[nbr].w, &m->t[nbr].h);
	if (!m->t[nbr].p)
		return (0);
	m->t[nbr].img_ptr = mlx_get_data_addr(m->t[nbr].p,
		&m->t[nbr].bit_per_pix, &m->t[nbr].s_line, &m->t[nbr].endian);
	if (!m->t[nbr].img_ptr)
		return (0);
	return (1);
}

void	create_texture(t_wolf *w)
{
	get_sheme(w);
	if (!(init_texture(w, 0, w->t->scheme[w->t->scheme_type].wall)))
		print_error(ERR_TEXTURE);
	if (!(init_texture(w, 1, w->t->scheme[w->t->scheme_type].floor)))
		print_error(ERR_TEXTURE);
	if (!(init_texture(w, 2, w->t->scheme[w->t->scheme_type].ceiling)))
		print_error(ERR_TEXTURE);
}

void	set_texture(t_wolf *m)
{
	if (!m->mlx.r.hit_side)
		m->mlx.r.wall_x = m->mlx.r.pos.y + m->mlx.r.pwd * m->mlx.r.dir.y;
	else
		m->mlx.r.wall_x = m->mlx.r.pos.x + m->mlx.r.pwd * m->mlx.r.dir.x;
	m->mlx.r.wall_x -= floor((m->mlx.r.wall_x));
	m->mlx.r.texture_x = (int)(m->mlx.r.wall_x *
		(float)m->t[m->mlx.r.tx_num].w);
	if (m->mlx.r.hit_side == 1 && m->mlx.r.dir.y < 0)
		m->mlx.r.texture_x = m->t[m->mlx.r.tx_num].w - m->mlx.r.texture_x - 1;
	if (!m->mlx.r.hit_side && m->mlx.r.dir.x > 0)
		m->mlx.r.texture_x = m->t[m->mlx.r.tx_num].w - m->mlx.r.texture_x - 1;
	m->mlx.oldtime = m->mlx.time;
	m->mlx.time = clock();
	m->mlx.frametime = (m->mlx.time - m->mlx.oldtime) / 1000.0;
	m->mlx.s_rot = m->mlx.frametime * 3;
	m->mlx.s_move = m->mlx.frametime * 5;
	wall(m, m->mlx.r.x, 0);
}
