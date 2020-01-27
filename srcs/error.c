/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlobunet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 20:17:21 by vlobunet          #+#    #+#             */
/*   Updated: 2019/10/26 20:17:23 by vlobunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

int	print_error(char *str)
{
	ft_putstrc_fd(RED, EER_HEADER, 2);
	ft_putstrc_fd(WHITE, str, 2);
	return (1);
}
