/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_draw.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bojamee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/29 20:24:13 by bojamee           #+#    #+#             */
/*   Updated: 2021/09/02 13:14:26 by bojamee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_point	*to_point(t_list *lst)
{
	return ((t_point *)(lst->content));
}

double	radian(double angle)
{
	return ((angle * 3.141592654f) / 180);
}

void	apply_iso(t_point *point)
{
	t_vector	res;

	res.z = 0;
	res.x = (point->pos.x - point->pos.y) * cos(radian(30));
	res.y = -point->pos.z + (point->pos.x + point->pos.y) * sin(radian(30));
	point->pos = res;
}

void	object_draw(t_object points, t_data *data)
{
	t_list	*p1;
	t_list	*connected;

	p1 = points.points;
	while (p1)
	{
		connected = to_point(p1)->connected;
		while (connected)
		{
			draw_line(to_point(p1)->pos, to_point(connected)->pos, data);
			connected = connected->next;
		}
		p1 = p1->next;
	}
}
