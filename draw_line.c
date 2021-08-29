/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bojamee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/29 15:26:18 by bojamee           #+#    #+#             */
/*   Updated: 2021/08/29 20:25:19 by bojamee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static	int	get_y(int x, t_vector start, t_vector end)
{
	double	y;

	y = (double)(end.y - start.y) * ((double)x - start.x)
		/ (end.x - start.x) - start.y;
	if (y - (int)y >= 0.5f)
		return ((int)y + 1);
	return ((int)y);
}

void	draw_line(t_vector start, t_vector end, t_data *data, t_camera camera)
{
	int		x;
	int		y;
	int		size;

	x = (int)start.x;
	while (x != (int)end.x)
	{
		size = LINE_SIZE;
		y = get_y(x, start, end);
		while (size)
		{
			if (y < 0 || y >= data->height || x < 0 || x > data->width)
				break ;
			_mlx_pixel_put(data, x, y, 0x00ffffff);
			if (size % 2 == 1)
				y = -(y - 1);
			else
				y *= -1;
			size--;
		}
		if (x > (int)end.x)
			x--;
		else
			x++;
	}
}
