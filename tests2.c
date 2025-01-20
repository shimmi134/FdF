/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shimi-be <shimi-be@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 12:22:23 by shimi-be          #+#    #+#             */
/*   Updated: 2025/01/20 13:42:06 by shimi-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "srclibs/get_next_line/get_next_line.h"
#include "srclibs/libft/libft.h"
#include "srclibs/ft_printf/libprintft.h"
#include <stdlib.h>
#include <fcntl.h>
#include <math.h>
#include "fdf.h"
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
		mlx_put_pixel(img, x0,y0,150);
		if (D > 0)
		{
			x0 = x0+xi;
			D = D + (2*(dx-dy));
		}
		else
			D = D + 2*dx;
		y0++;
	}
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
		mlx_put_pixel(img, x0,y0,150);
		if (D > 0)
		{
			y0 = y0+yi;
			D = D + (2*(dy-dx));
		}
		else
			D = D + 2*dy;
		x0++;
	}
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

void iso(double *x, double *y, double z)
{
    double previous_x;
    double previous_y;

    previous_x = *x;
    previous_y = *y;
    *x = (previous_x - previous_y) * cos(0.523599);
    *y = -z + (previous_x + previous_y) * sin(0.523599);
}

t_point createPoint(int x, int y, int z, int j, int i)
{
	t_point point;
	point.x = (x*(j))/2;
	point.y = (y*(i))/2;
	point.z = z;
	return (point);
}

void offset(double *x0, double *y0, double *x1, double *y1)
{
	double ax = *x0, ay = *y0, bx = *x1, by = *y1;
	*x0 = (1800+ax);
	*y0 = (400+ay);
	*x1 = (1800+bx);
	*y1 = (400+by);		
}

void draw(int **m, int height, int length)
{
	mlx_t* mlx;
	int x;
	int y;
	int z;
	t_point a;
	t_point b;

	mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true); 
	mlx_image_t* img = mlx_new_image(mlx, WIDTH, HEIGHT);
	ft_memset(img->pixels, 255, img->width * img->height * sizeof(int32_t));
	y = (HEIGHT - 400) / height;
	x = (WIDTH - 800) / length;
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < length; j++)
		{
			if (i < height-1 && j < length-1)
			{
				z = m[i][j]*5;
				a = createPoint(x,y,z,j,i);
				z = m[i+1][j]*5;
				b = createPoint(x,y,z,j,i+1);
				iso(&a.x,&a.y,a.z);
				iso(&b.x,&b.y,b.z);
				offset(&a.x,&a.y,&b.x,&b.y);
				drawLine(img, a.x,b.x,a.y,b.y);
				z = m[i][j]*5;
				a = createPoint(x,y,z,j,i);
				z = m[i][j+1]*5;
				b = createPoint(x,y,z,j+1,i);
				iso(&a.x,&a.y,a.z);
				iso(&b.x,&b.y,b.z);
				offset(&a.x,&a.y,&b.x,&b.y);
				drawLine(img, a.x,b.x,a.y,b.y);
			}
			else if (j == length-1 && i != height-1)
			{
				z = m[i][j]*5;
				a = createPoint(x,y,z,j,i);
				z = m[i+1][j]*5;
				b = createPoint(x,y,z,j,i+1);
				iso(&a.x,&a.y,a.z);
				iso(&b.x,&b.y,b.z);
				offset(&a.x,&a.y,&b.x,&b.y);
				drawLine(img, a.x,b.x,a.y,b.y);
			}
			else if (j != length-1 && i == height-1)
			{
				z = m[i][j]*5;
				a = createPoint(x,y,z,j,i);
				z = m[i][j+1]*5;
				b = createPoint(x,y,z,j+1,i);
				iso(&a.x,&a.y,a.z);
				iso(&b.x,&b.y,b.z);
				offset(&a.x,&a.y,&b.x,&b.y);
				drawLine(img, a.x,b.x,a.y,b.y);
			}
		}
	}
	mlx_image_to_window(mlx, img, 0, 0);
	mlx_key_hook(mlx, &my_keyhook, mlx);
	mlx_loop(mlx);
	mlx_delete_image(mlx,img);
	mlx_terminate(mlx);
}
