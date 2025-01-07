#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdio.h>
#include "MLX42/MLX42.h"
#define WIDTH 1920
#define HEIGHT 1080

void draw(mlx_image_t* img, int i, int j, int a)
{

	
}


void my_keyhook(mlx_key_data_t keydata, void *param)
{
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	{
		mlx_close_window(param);
		return;
	}
}
int32_t	main(void)
{
	mlx_t* mlx;

	if (!(mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true)))
		return (EXIT_FAILURE);
	mlx_image_t* img = mlx_new_image(mlx, WIDTH, HEIGHT);
	memset(img->pixels, 255, img->width * img->height * sizeof(int32_t));
	for (int i = 0; i < WIDTH/2; i++)
	{
		for (int j = 0; j < WIDTH/2; j++)
		{
			if (i == 0 || i == (WIDTH/2)-1)
			{
				for (int k = 0; k < 10; k++)
					mlx_put_pixel(img, i+k, j, 40);
			}
			else if (j == 0 || j == (WIDTH/2)-1)
			{
				for (int k = 0; k < 10; k++)
					mlx_put_pixel(img, i, j+k, 40);
			}
		}
	}
	mlx_image_to_window(mlx, img, 0, 0);
	mlx_key_hook(mlx, &my_keyhook, mlx);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
