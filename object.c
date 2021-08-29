/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bojamee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/29 20:05:59 by bojamee           #+#    #+#             */
/*   Updated: 2021/08/29 20:23:43 by bojamee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_object	*object_create(t_list *points, t_vector pos,
		t_vector rot, t_vector scale)
{
	t_object	*object;

	object = ft_calloc(sizeof(t_object), 1);
	if (!object)
		return (0);
	object->points = points;
	object->pos = pos;
	object->rot = rot;
	object->scale = scale;
	return (object);
}

t_point	*object_get(t_object object, int col, int line)
{
	t_list	tmp;
	t_point	*point;

	tmp = object.points;
	while (tmp)
	{
		point = (t_point *)(tmp->content);
		if (point->line == line && point.col == col)
			return (point);
		tmp = tmp->next;
	}
	return (0);
}

void	object_translate(t_object *object, t_vector delta)
{
	object->pos.x += delta.x;
	object->pos.y += delta.y;
	object->pos.z += delta.z;
}

void	object_rotate(t_object *object, t_vector delta)
{
	object->rot.x += delta.x;
	object->rot.y += delta.y;
	object->rot.z += delta.z;
}

void	object_scale(t_object *object, t_vector delta)
{
	object->scale.x += delta.x;
	object->scale.y += delta.y;
	object->scale.z += delta.z;
}
