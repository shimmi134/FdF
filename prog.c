#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdio.h>
#include "MLX42/MLX42.h"
#define WIDTH 1920
#define HEIGHT 1080

#define BPP sizeof(int32_t)

void color_window(mlx_t* mlx, mlx_key_data_t keydata, mlx_image_t* img)
{
	int r = rand() % 255;
	if (keydata.key == MLX_KEY_C && keydata.action ==  MLX_PRESS)
	{
		memset(img->pixels, r, img->width * img->height * BPP);
		mlx_image_to_window(mlx, img, 0, 0);
	}
}

void my_keyhook(mlx_key_data_t keydata, void* param)
{
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(param);
	
	if (keydata.key == MLX_KEY_K && keydata.action == MLX_RELEASE)
		puts("World");

	if (keydata.key == MLX_KEY_L && keydata.action == MLX_REPEAT)
		puts("!");
}

void my_scrollhook(double xdelta, double ydelta, void* param)
{
	if (ydelta > 0)
		puts("Up!");
	else if (ydelta < 0)
		puts("Down!");
	
	if (xdelta < 0)
		puts("Sliiiide to the left!");
	else if (xdelta > 0)
		puts("Sliiiide to the right!");
}

int32_t	main(void)
{
	mlx_t* mlx;

	if (!(mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true)))
		return (EXIT_FAILURE);

	mlx_image_t* img = mlx_new_image(mlx, 256, 256);
	mlx_loop_hook(mlx, &color_window, img);
	mlx_key_hook(mlx, &my_keyhook, mlx);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
