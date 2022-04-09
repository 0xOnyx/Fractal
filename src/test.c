#include <mlx.h>

int	main(void)
{
	void	*img;
	void 	*win;
	void	*mlx;

	mlx = mlx_init();
	img = mlx_new_image(mlx, 1920, 1080);
	win = mlx_new_window(mlx, 1920, 1080, "hello");

	mlx_loop(mlx);
	return (1);
}
