/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlobunet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 09:02:15 by vlobunet          #+#    #+#             */
/*   Updated: 2019/10/27 09:02:18 by vlobunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	change_song(int key)
{
	system("killall afplay 2&>/dev/null >/dev/null");
	if (key == 18)
		system("afplay songs/song1.mp3&");
	else if (key == 19)
		system("afplay songs/song2.mp3&");
	else if (key == 20)
		system("afplay songs/song3.mp3&");
	else if (key == 21)
		system("afplay songs/song4.mp3&");
	else if (key == 22)
		system("afplay songs/jb.mp3&");
}

int		key_hook_on(int key, t_wolf *m)
{
	key >= 18 && key <= 22 ? change_song(key) : 0;
	key == 126 ? m->mlx.move.move_f = 1 : 0;
	key == 125 ? m->mlx.move.move_b = 1 : 0;
	key == 123 ? m->mlx.move.move_l = 1 : 0;
	key == 124 ? m->mlx.move.move_r = 1 : 0;
	if (key == ESC)
	{
		system("killall -SIGSTOP afplay 2&>/dev/null >/dev/null");
		destroy_struct(m);
		return (0);
	}
	return (0);
}

int		key_hook_off(int key, t_wolf *m)
{
	key == 126 ? m->mlx.move.move_f = 0 : 0;
	key == 125 ? m->mlx.move.move_b = 0 : 0;
	key == 123 ? m->mlx.move.move_l = 0 : 0;
	key == 124 ? m->mlx.move.move_r = 0 : 0;
	if (key == ESC)
	{
		system("killall -SIGSTOP afplay 2&>/dev/null >/dev/null");
		exit(0);
		return (0);
	}
	return (0);
}

int		exit_cl(void *click)
{
	system("killall -SIGSTOP afplay 2&>/dev/null >/dev/null");
	click = NULL;
	exit(1);
	return (0);
}
