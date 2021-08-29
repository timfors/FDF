/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bojamee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/29 16:30:09 by bojamee           #+#    #+#             */
/*   Updated: 2021/08/29 16:35:44 by bojamee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_point	*point_create(t_vector local_pos, int col, int line)
{
	t_point *point;

	point = ft_calloc(sizeof(t_point), 1);
	if (!point)
		return (0);
	point->local_pos = local_pos;
	point->col = col;
	point->line = line;
	return (point);
}
