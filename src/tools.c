


#include "tools.h"


int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	my_mlx_pixel_put(t_data *img, int x, int y, int color)
{
	char *dst;

	dst = img->addr;
	dst += (y * img->line_length) + x * ( img->bits_per_pixel / 8);
	*(unsigned int *)dst = color;
}



