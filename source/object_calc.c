/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_calc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bojamee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/29 20:35:12 by bojamee           #+#    #+#             */
/*   Updated: 2021/09/02 13:14:02 by bojamee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	apply_scale(t_object object, t_point *point)
{
	point->pos.x = point->pos.x * object.scale.x;
	point->pos.y = point->pos.y * object.scale.y;
	point->pos.z = point->pos.z * object.scale.z;
}

void	apply_pos(t_object object, t_point *point)
{
	point->pos.x += object.pos.x;
	point->pos.y += object.pos.y;
	point->pos.z += object.pos.z;
}

void	apply_rotation(t_object object, t_point *point)
{
	point->pos.x = point->pos.x;
	point->pos.y = point->pos.y * cos(radian(object.rot.x))
		+ point->pos.z * sin(radian(object.rot.x));
	point->pos.z = point->pos.z * cos(radian(object.rot.x))
		- point->pos.y * sin(radian(object.rot.x));
	point->pos.x = point->pos.x * cos(radian(object.rot.y))
		+ point->pos.z * sin(radian(object.rot.y));
	point->pos.y = point->pos.y;
	point->pos.z = point->pos.z * cos(radian(object.rot.y))
		- point->pos.x * sin(radian(object.rot.y));
	point->pos.x = point->pos.x * cos(radian(object.rot.z))
		- point->pos.y * sin(radian(object.rot.z));
	point->pos.y = point->pos.y * cos(radian(object.rot.z))
		+ point->pos.x * sin(radian(object.rot.z));
}

void	object_calc_point(t_object *object, t_point *point, int is_iso)
{
	point->pos = point->local_pos;
	apply_rotation(*object, point);
	if (is_iso)
		apply_iso(point);
	apply_scale(*object, point);
	apply_pos(*object, point);
}

void	object_calc_points_pos(t_object *object, int is_iso)
{
	t_point	*point;
	t_list	*tmp;

	tmp = object->points;
	while (tmp)
	{
		point = to_point(tmp);
		object_calc_point(object, point, is_iso);
		tmp = tmp->next;
	}
	set_to_center(object);
}
