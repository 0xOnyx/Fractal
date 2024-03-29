


#include "tools.h"

void	fractal_calc(t_vars *vars, int width, int height)
{
	int color;

	int x;
	int y;
	
	double pr;
	double pi;

	double new_re;
	double new_im;

	double old_re;
	double old_im;
	
	int i;

	x = 0;
	y = 0;

	pr = vars->pr;
	pi = vars->pi;

	while(x < height)
	{
		while(y < width)
		{
			new_re = 1.5 * (x - width / 2) / (0.5 * vars->scale * width) + vars->moveX;
			new_im = (y - height / 2) / (0.5 * vars->scale * height) + vars->moveY;
			
			i = 0;
			while( i < vars->iteration )
			{
				old_re = new_re;
				old_im = new_im;

				new_re = old_re * old_re - old_im * old_im + pr;
				new_im = 2 * old_re * old_im + pi;

				i++;

				if((new_re * new_re + new_im * new_im) > 4)
					break;
			}

			if(i == vars->iteration)
				color = 0x0;

			else
				color = create_trgb(0, 3, 255 - (255 * i / vars->iteration) , 255 );

			my_mlx_pixel_put(vars->img, x, y, color);

			y++;
		}
		y = 0;
		x++;
	}

}
