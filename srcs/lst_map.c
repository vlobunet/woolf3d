/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlobunet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 20:33:36 by vlobunet          #+#    #+#             */
/*   Updated: 2019/10/26 20:33:38 by vlobunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

t_list	*lstnew(int y, int x, t_list *lst, char **map)
{
	t_list	*new;

	new = (t_list *)ft_memalloc(sizeof(t_list));
	new->next = NULL;
	new->prev = NULL;
	new->f = lst;
	new->x = x;
	new->y = y;
	new->num = g_number++;
	map[y][x] = '#';
	return (new);
}

void	lst_add(t_list *lst, t_list *new)
{
	while (lst && lst->next)
		lst = lst->next;
	lst->next = new;
	new->prev = lst;
}

int		can_go(char **map, t_list *lst, t_wolf *wolf)
{
	if (lst->x == wolf->map.col - 1 || lst->y == wolf->map.row - 1 ||
		lst->x == 0 || lst->x == 0)
		return (2);
	if ((map[lst->y][lst->x + 1] == '*' || map[lst->y][lst->x + 1] == '#') &&
		(map[lst->y - 1][lst->x] == '*' || map[lst->y - 1][lst->x] == '#') &&
		(map[lst->y][lst->x - 1] == '*' || map[lst->y][lst->x - 1] == '#') &&
		(map[lst->y + 1][lst->x] == '*' || map[lst->y + 1][lst->x] == '#'))
		return (1);
	return (0);
}

t_list	*lst_dell_all(t_list *lst)
{
	t_list	*cur;

	while (lst && lst->prev)
		lst = lst->prev;
	while (lst && lst->next)
	{
		cur = lst->next;
		free(lst);
		lst = cur;
	}
	free(lst);
	return (NULL);
}

t_list	*create_tree(t_wolf *wolf, char **map, t_list *lst, int ret)
{
	lst = lstnew(wolf->map.user.y, wolf->map.user.x, NULL, map);
	while (lst && (ret = can_go(map, lst, wolf)) != 2)
	{
		if (!ret && GO_R(map, lst->y, lst->x + 1))
			lst_add(lst, lstnew(lst->y, lst->x + 1, lst, map));
		if (!ret && GO_T(map, lst->y - 1, lst->x))
			lst_add(lst, lstnew(lst->y - 1, lst->x, lst, map));
		if (!ret && GO_L(map, lst->y, lst->x - 1))
			lst_add(lst, lstnew(lst->y, lst->x - 1, lst, map));
		if (!ret && GO_B(map, lst->y + 1, lst->x))
			lst_add(lst, lstnew(lst->y + 1, lst->x, lst, map));
		if (!lst->next)
			break ;
		lst = lst->next;
	}
	ft_freestrarr(map);
	if (ret == 2)
	{
		print_error(ERR_MAPINVALID);
		return (lst_dell_all(lst));
	}
	return (lst);
}
