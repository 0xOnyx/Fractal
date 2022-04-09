


#include "tools.h"

#define x1 -2.1
#define x2 0.6
#define y1 -1.2
#define y2 1.2

#define scale 100

#define iteration 100


#include <stdio.h>
void	fractal_calc(t_data *img)
{
	int color = create_trgb(0, 255, 255, 255);

	int x;
	int y;
	int image_x = (x2 - x1) * scale;
	int image_y = (y2 - y1) * scale;

	x = 0;
	y = 0;

	while(x < image_x)
	{
		printf("x => %d, y => %d\n", x, y );
		while(y < image_y)
		{
			int c_r = (x / scale) + x1;
			int c_i = (y / scale) + y1;
			int z_r = 0;
			int z_i = 0;
			int i = 0;

			do{
				int tmp = z_r;
				z_r = (z_r * z_r) - (z_i * z_i) + c_r;
				z_i = (2 * z_i * tmp) + c_i;
				i += 1;
			}while(
				(z_r * z_r ) + (z_i * z_i) < 4 && \
				i < iteration
			);

			if(i == iteration)
				my_mlx_pixel_put(img, x, y, color);

			y++;
		}
		y = 0;
		x++;
	}

}
