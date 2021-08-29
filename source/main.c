#include "../includes/fdf.h"

void	_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;
	dst =data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	fill_image(t_data *data, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->height)
	{
		j = 0;
		while (j < data->width)
			_mlx_pixel_put(data, j++, i, color);
		i++;
	}
}

t_data	data_create(void *mlx, int width, int height, int color)
{
	t_data	img;

	img.img = mlx_new_image(mlx, width, height);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.width,
			&img.endian);
	img.height = height;
	foll_image(&data, color);
	return (image);
}

int main(void)
{
	void	*mlx;
	t_data	img;
	void	*mlx_window;
	t_point	p1;
	t_point	p2;

	p1 = *point_create(0, 0, 0);

	mlx = mlx_init();
	img = data_create(mlx, S_WIDTH, S_HEIGHT, COLOR_BACKGROUND);
	mlx_window = mlx_new_window(mlx, S_WIDTH, S_HEIGHT, "Hi");
	mlx_put_image_to_window(mlx, mlx_window, img.img, 0, 0);
	mlx_loop(mlx);
}
