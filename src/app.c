
#include <stdio.h>
#include <mlx.h>
#include "tools.h"


#define width 1980
#define height 1980

void	fractal_calc(t_vars *vars, int w, int h);

int	close_mlx(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	return (0);
}

int	key_event_mlx(int keycode, t_vars *vars)
{
	printf("keycode =>%d \n", keycode);

	if(keycode == 65451)
		vars->scale *= 1.5;
	else if(keycode == 65453)
		vars->scale *= 0.15;

	else if(keycode == 65362)
		vars->moveY -= 0.15;
	else if(keycode == 65364)
		vars->moveY += 0.15;
	
	else if(keycode == 65363)
		vars->moveX += 0.15;
	else if(keycode == 65361)
		vars->moveX -= 0.15;

	vars->iteration = 2;

	return (0);
}

int	render_next_frame(t_vars *vars)
{

	printf("new frame to create =>\n\toptions => \n\tscale =>%f\n\tmoveX=>%f\n\tmoveY=>%f\n", vars->scale, vars->moveX, vars->moveY);
	fractal_calc(vars, width, height);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img->img, 0, 0);

	vars->iteration++;
//	printf("iteration => %d\n", i);

	return (1);
}

int	main(int argc, char *argv)
{
	t_vars vars;
	t_data img;

	vars.moveX = -0.5;
	vars.moveY = 0;
	vars.scale = 1;
	vars.iteration = 2;

	vars.mlx = mlx_init();
	if(!vars.mlx)
		return (0);

	vars.win = mlx_new_window(vars.mlx, width, height, "fractal");
	if(!vars.win)
		return (0);

	img.img = mlx_new_image(vars.mlx, width, height);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);

	vars.img = &img;

	mlx_hook(vars.win, 17, 1L << 2, close_mlx, &vars);
	mlx_hook(vars.win, 2, 1L << 0, key_event_mlx, &vars);
	mlx_loop_hook(vars.mlx, render_next_frame, &vars);

	mlx_loop(vars.mlx);

	return (0);
}
