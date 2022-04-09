#include <mlx.h>
#include <stdio.h>

typedef	struct	s_data {
	void	*img;
	char	*addr;
	int	bits_per_pixel;
	int	line_length;
	int	endian;
}		t_data;

typedef	struct	s_pos {
	int x;
	int y;
}	t_pos;

typedef	struct	s_vars {
	void *mlx;
	void *win;
}	t_vars;

int	key_event_mlx(int keycode, t_vars *vars)
{
	printf("key => %d\n", keycode);	
	//mlx_destroy_window(vars->mlx, vars->win);
	return 0;
}

int	close_mlx(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	return (0);
}


void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char 	*dst;

	dst = data->addr;
	dst += (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	render_next_frame(void *data)
{
	t_data img;
	img = *(t_data *)data;

}


void	my_mlx_create_line(t_data *data, t_pos from, t_pos dest, int color)
{
	while(from.x <= dest.x)
	{
		my_mlx_pixel_put(data, from.x, from.y, color);
		from.x += 1;
	}
}


int	main(void)
{
	t_vars vars;
	t_data img;
	
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 500, 500, "Hello world!");
	img.img = mlx_new_image(vars.mlx, 500, 500);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);

	my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
	
	int color;

	color = create_trgb(0, 255, 0, 0);
	t_pos from;
	t_pos dest;

	from.x = 0;
	from.y = 250;

	dest.x = 500;
	dest.y = 250;

	my_mlx_create_line(&img, from, dest, color);
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);

//	mlx_hook(vars.win, 2, 1L << 0, key_event_mlx, &vars);
	mlx_hook(vars.win, 17, 1L << 2, close_mlx, &vars);

	mld_loop_hook(vars.mlx, render_next_frame, &img);
	mlx_loop(vars.mlx);

	return (0);
	
}
