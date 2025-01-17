#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdio.h>
#include "MLX42/MLX42.h"
#define WIDTH 4480
#define HEIGHT 2520

int abs(int num)
{
	if (num < 0) return (-num);
	return num;
}

void drawlineHigh(mlx_image_t* img,int x0, int x1, int y0, int y1)	
{
	int dx = x1-x0;
	int dy = y1-y0;
	int xi = 1;
	if (dx < 0)
	{
		xi = -1;
		dx = -dx;
	}
	int D = 2*dx - dy;
	while (y0 < y1)
	{
		mlx_put_pixel(img, x0,y0,100);
		if (D > 0)
		{
			x0 = x0+xi;
			D = D + (2*(dx-dy));
		}
		else
			D = D + 2*dx;
		y0++;
	}
	printf("y0: %i",y0);
}

void drawlineLow(mlx_image_t* img,int x0, int x1, int y0, int y1)	
{
	int dx = x1-x0;
	int dy = y1-y0;
	int yi = 1;
	if (dy < 0)
	{
		yi = -1;
		dy = -dy;
	}
	int D = 2*dy - dx;
	while (x0 < x1)
	{
		mlx_put_pixel(img, x0,y0,100);
		if (D > 0)
		{
			y0 = y0+yi;
			D = D + (2*(dy-dx));
		}
		else
			D = D + 2*dy;
		x0++;
	}
	printf("x0: %i",x0);
}

void drawLine(mlx_image_t* img, int x0, int x1, int y0, int y1)
{
	if (abs(y1-y0) < abs(x1-x0))
	{
		if (x0 > x1)
			drawlineLow(img, x1,x0,y1,y0);
		else
			drawlineLow(img, x0,x1,y0,y1);
	}
	else{
		if (y0 > y1)
			drawlineHigh(img, x1, x0, y1, y0);
		else
			drawlineHigh(img, x0, x1, y0, y1);
	}
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
	drawLine(img, 400,3850/2,1880/2,400);
	drawLine(img, 1925,3850-400,400,1880/2);
	drawLine(img, 400,3850-400,1880/2,1880/2);
	mlx_image_to_window(mlx, img, 0, 0);
	mlx_key_hook(mlx, &my_keyhook, mlx);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
