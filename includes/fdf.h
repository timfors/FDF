#ifndef FDF_H
# define FDF_H
# define S_WIDTH 1920
# define S_HEIGHT 1080
# define LINE_SIZE 2
# define LINE_COLOR 0x00ffffff
# define COLOR_BACKGROUND 0x00000000


# include "libft.h"
# include "mlx.h"
# include <math.h>

typedef struct s_vector
{
	double	x;
	double	y;
	double	z;
}			t_vector;

t_vector	vector_create(int x, int y, int z);

typedef struct s_point
{
	t_vector	pos;
	t_vector	local_pos;
	t_list		*connected;
	int			line;
	int			col;
}				t_point;

typedef struct s_object
{
	t_vector	pos;
	t_vector	rot;
	t_vector	scale;
	t_list		*points;
}			t_object;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		width;
	int		endian;
}			t_data;

t_data			*data_create(void *mlx, int width, int height);
void			data_clear(t_data **data);

void			fill_image(t_data *data, int color);
void			draw_line(t_point start, t_point end, t_data *data);

t_object		*object_create(t_list *points);
void			object_add(t_object object, t_point *point);
t_point			*object_get(t_object object, int col, int line);
void			object_calc_points_pos(t_object *object);
void			object_draw(t_object object, t_data *data);
void			object_translate(t_object *object, t_vector delta);
void			object_clear(t_object **lst);


void			_mlx_pixel_put(t_data *data, int x, int y, int color);

t_point			*point_create(t_vector local_pos, int line, int col);
t_point			*to_point(t_list *lst);

t_object		*parse(const char *filename);

#endif
