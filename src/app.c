
#include <mlx.h>
#include "tools.h"

#define width 270
#define height 240

int	close_mlx(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	return (0);
}

void	fractal_calc(t_data *img, int w, int h);

int	main(int argc, char *argv)
{
	t_vars vars;
	t_data img;
	
	vars.mlx = mlx_init();
	if(!vars.mlx)
		return (0);

	vars.win = mlx_new_window(vars.mlx, width, height, "fractal");
	if(!vars.win)
		return (0);

	img.img = mlx_new_image(vars.mlx, width, height);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	
	fractal_calc(&img, width, height);

	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);

	mlx_hook(vars.win, 17, 1L << 2, close_mlx, &vars);
	mlx_loop(vars.mlx);

	return (0);
}
