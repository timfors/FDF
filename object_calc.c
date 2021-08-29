/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_calc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bojamee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/29 20:35:12 by bojamee           #+#    #+#             */
/*   Updated: 2021/08/29 21:03:01 by bojamee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static double	radian(double angle)
{
	return ((angle * 3.141592654f) / 180)
}

static void	apply_scale(t_object object, t_point *point)
{
	point->pos.x = point->pos.x * object.scale.x;
	point->pos.y = point->pos.y * object.scale.y;
	point->pos.z = point->pos.z * object.scale.z;
}

static void	apply_pos(t_object object, t_point *point)
{
	point->pos.x += object.pos.x;
	point->pos.y += object.pos.y;
	point->pos.z += object.pos.z;
}

static void	apply_rotation(t_object object, t_point *point)
{
	point->pos.x = point->pos.x;
	point->pos.y = point->pos.y * cos(radian(object.rot.x))
		+ point->pos.z * sin(radian(object.rot.x));
	point->pos.z =  point->pos.z * cos(radian(object.rot.x))
		- point->pos.y * sin(radian(object.rot.x));

	point->pos.x =  point->pos.x * cos(radian(object.rot.y))
		+ point->pos.z * sin(radian(object.rot.y));
	point->pos.y = point->pos.y;
	point->pos.z = point->pos.z * cos(radian(object.rot.y))
		- point->pos.x * sin(radian(object.rot.y));

	point->pos.x = point->pos.x * cos(radian(object.rot.z))
		- point->pos.y * sin(radian(object.rot.z));
	point->pos.y = point->pos.y * cos(radian(object.rot.z))
		+ point->pos.x * sin(radian(object.rot.z));
}

void	object_calc_points_pos(t_object *obj)
{
	t_point	*point;
	t_list	*tmp;

	tmp = obj->points;
	while (tmp)
	{
		point = to_point(tmp);
		point->pos = point->local_pos;
		apply_pos(*object, point);
		apply_scale(*object, point);
		apply_rotation(*object, point);
		tmp = tmp->next;
	}
}
