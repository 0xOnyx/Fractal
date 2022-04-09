


#include "tools.h"

#define moveX -0.5
#define moveY 0

#define scale 1

#define iteration 100

#include <stdio.h>
void	fractal_calc(t_data *img, int width, int height)
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

	while(x < height)
	{
		printf("x => %d, y => %d\n", x, y );
		while(y < width)
		{
			pr = 1.5 * (x - width / 2) / (0.5 * scale * width) + moveX;
			pi = (y - height / 2) / (0.5 * scale * height) + moveY;
			new_re = 0;
			new_im = 0;
			old_re = 0;
			old_im = 0;
			
			i = 0;
			while( i < iteration )
			{
				old_re = new_re;
				old_im = new_im;

				new_re = old_re * old_re - old_im * old_im + pr;
				new_im = 2 * old_re * old_im + pi;

				i++;

				if((new_re * new_re + new_im * new_im) > 4)
					break;
			}

			if(i == iteration)
				color = 0;

			else
				color = create_trgb(0, 0, 255 * i / iteration, 255);

			my_mlx_pixel_put(img, x, y, color);

			y++;
		}
		y = 0;
		x++;
	}

}
