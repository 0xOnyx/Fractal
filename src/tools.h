#ifndef APP_H
#	define APP_H

typedef struct s_data {
	void 	*img;
	char	*addr;
	int	bits_per_pixel;
	int	line_length;
	int	endian;
}	t_data;

typedef struct s_pos {
	int x;
	int y;
}	t_pos;

typedef struct s_vars {
	void *mlx;
	void *win;	
}	t_vars;


void	my_mlx_pixel_put(t_data *img, int x, int y, int color);
int	create_trgb(int t, int r, int g, int b);


#endif
