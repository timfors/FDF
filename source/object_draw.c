/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_draw.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bojamee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/29 20:24:13 by bojamee           #+#    #+#             */
/*   Updated: 2021/08/29 20:35:03 by bojamee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

t_point	*to_point(t_list *lst)
{
	return ((t_point *)(lst->content));
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
