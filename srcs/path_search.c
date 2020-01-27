/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_search.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlobunet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 22:34:23 by vlobunet          #+#    #+#             */
/*   Updated: 2019/10/26 22:34:25 by vlobunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void		mlx_create(t_wolf *w)
{
	mlx_clear_window(w->mlx.mlx, w->mlx.win);
	mlx_put_image_to_window(w->mlx.mlx, w->mlx.win, w->mlx.img, 0, 0);
}

int			cycle_hooks(t_wolf *m)
{
	if (m->mlx.move.move_f)
		go_forward(m);
	if (m->mlx.move.move_b)
		go_backwards(m);
	if (m->mlx.move.move_l)
		rot_left(m);
	if (m->mlx.move.move_r)
		rot_right(m);
	m->mlx.r.x = 0;
	m->mlx.r.y = 0;
	m->mlx.r.d = 0;
	raycasting(m);
	mlx_create(m);
	return (0);
}

void		init_variables(t_wolf *w)
{
	w->mlx.s_shift = 0.5;
	w->mlx.shift = 0;
	w->mlx.txr = 0;
	w->mlx.cam_pl.x = 1;
	w->mlx.cam_pl.y = 0;
	w->mlx.cam_vector.x = 0;
	w->mlx.cam_vector.y = 0.66;
	w->mlx.move.move_f = 0;
	w->mlx.move.move_b = 0;
	w->mlx.move.move_l = 0;
	w->mlx.move.move_r = 0;
	w->mlx.time = 0;
	w->mlx.oldtime = 0;
	w->mlx.r.tx_num = 0;
	w->t = (t_texture *)malloc(sizeof(t_texture) * 3);
	w->t->scheme_type = 2;
}

static void	mlx_initialization(t_wolf *m)
{
	m->mlx.mlx = mlx_init();
	m->mlx.win = mlx_new_window(m->mlx.mlx, W, H, "by @vlobunet");
	m->mlx.img = mlx_new_image(m->mlx.mlx, W, H);
	m->mlx.data = mlx_get_data_addr(m->mlx.img, &m->mlx.bpp,
		&m->mlx.sizeline, &m->mlx.endian);
	system("afplay songs/song1.mp3&");
	init_variables(m);
	create_texture(m);
	mlx_hook(m->mlx.win, 2, (1L << 0), key_hook_on, m);
	mlx_hook(m->mlx.win, 3, (1L << 1), key_hook_off, m);
	mlx_loop_hook(m->mlx.mlx, cycle_hooks, m);
	mlx_hook(m->mlx.win, 17, 1L << 17, exit_cl, m);
	mlx_loop(m->mlx.mlx);
}

int			shortest_path_search(t_wolf *wolf)
{
	char	**map_tmp;
	int		i;

	i = -1;
	wolf->map.user.x += 0.5;
	wolf->map.user.y += 0.5;
	if (!(map_tmp = (char **)malloc(sizeof(char *) * (wolf->map.row + 1))))
		return (0);
	map_tmp[wolf->map.row] = NULL;
	while (wolf->map.src[++i])
		map_tmp[i] = ft_strdup(wolf->map.src[i]);
	if ((wolf->path = create_tree(wolf, map_tmp, NULL, 0)))
		mlx_initialization(wolf);
	else
		return (0);
	return (1);
}
