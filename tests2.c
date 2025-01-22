/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shimi-be <shimi-be@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 12:22:23 by shimi-be          #+#    #+#             */
/*   Updated: 2025/01/22 19:52:09 by shimi-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42/MLX42.h"
#include "fdf.h"
#include "srclibs/ft_printf/libprintft.h"
#include "srclibs/get_next_line/get_next_line.h"
#include "srclibs/libft/libft.h"
#include <fcntl.h>
#include <math.h>
#include <stdlib.h>
#define WIDTH 4480
#define HEIGHT 2520

int	abs(int num)
{
	if (num < 0)
		return (-num);
	return (num);
}

void	drawlinehigh(mlx_image_t *img, int x0, int x1, int y0, int y1,
		uint32_t color0, uint32_t color1)
{
	int	dx;
	int	dy;
	int	xi;
	int	d;
	int	y;

	dx = x1 - x0;
	dy = y1 - y0;
	xi = 1;
	if (dx < 0)
	{
		xi = -1;
		dx = -dx;
	}
	d = 2 * dx - dy;
	y = y0;
	while (y0 < y1)
	{
		if (y0 < 0)
			y0 = 0;
		else if (y0 >= HEIGHT)
			y0 = HEIGHT - 1;
		if (x0 < 0)
			x0 = 0;
		else if (x0 >= WIDTH)
			x0 = WIDTH - 1;
		mlx_put_pixel(img, x0, y0, color0);
		if (d > 0)
		{
			x0 = x0 + xi;
			d = d + (2 * (dx - dy));
		}
		else
			d = d + 2 * dx;
		y0++;
		if (y0 > y + ((y1 - y) / 2))
			color0 = color1;
	}
}

void	drawlinelow(mlx_image_t *img, int x0, int x1, int y0, int y1,
		uint32_t color0, uint32_t color1)
{
	int	dx;
	int	dy;
	int	yi;
	int	d;
	int	x;

	dx = x1 - x0;
	dy = y1 - y0;
	yi = 1;
	if (dy < 0)
	{
		yi = -1;
		dy = -dy;
	}
	d = 2 * dy - dx;
	x = x0;
	while (x0 < x1)
	{
		if (x0 < 0)
			x0 = 0;
		else if (x0 >= WIDTH)
			x0 = WIDTH - 1;
		if (y0 < 0)
			y0 = 0;
		else if (y0 >= HEIGHT)
			y0 = HEIGHT - 1;
		mlx_put_pixel(img, x0, y0, color0);
		if (d > 0)
		{
			y0 = y0 + yi;
			d = d + (2 * (dy - dx));
		}
		else
			d = d + 2 * dy;
		x0++;
		if (x0 > x + ((x1 - x) / 2))
			color0 = color1;
	}
}

void	drawline(mlx_image_t *img, int x0, int x1, int y0, int y1,
		uint32_t color0, uint32_t color1)
{
	if (abs(y1 - y0) < abs(x1 - x0))
	{
		if (x0 > x1)
			drawlinelow(img, x1, x0, y1, y0, color1, color0);
		else
			drawlinelow(img, x0, x1, y0, y1, color0, color1);
	}
	else
	{
		if (y0 > y1)
			drawlinehigh(img, x1, x0, y1, y0, color1, color0);
		else
			drawlinehigh(img, x0, x1, y0, y1, color0, color1);
	}
}

void	my_keyhook(mlx_key_data_t keydata, void *param)
{
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	{
		mlx_close_window(param);
		mlx_terminate(param);
		exit(1);
		return ;
	}
}

void	iso(double *x, double *y, double z)
{
	double	previous_x;
	double	previous_y;

	previous_x = *x;
	previous_y = *y;
	*x = (previous_x - previous_y) * cos(0.523599);
	*y = -z + (previous_x + previous_y) * sin(0.523599);
}

void	print_point(t_point p)
{
	ft_printf("p.x: %i\n", p.x);
	ft_printf("p.y: %i\n", p.y);
	ft_printf("p.z: %i\n", p.z);
}

void	init_point(t_point *p, uint32_t **color, int i, int j, int z)
{
	p->x = 0;
	p->y = 0;
	p->z = 0;
	p->color = 0x000000;
	if (color)
		p->color = color[i][j];
}

void	createpoint(t_point *p, long int x, long int y, long int z, long int j,
		long int i, uint32_t **color)
{
	p->x = (x * (j)) / 2.5;
	p->y = (y * (i)) / 2.5;
	p->z = z;
	if (!color)
	{
		if (z < 0 && p->color == 0x000000)
			p->color = 0x000000FF;
		else if (z == 0 && p->color == 0x000000)
			p->color = 0x808080FF;
		else if (z <= 180 && p->color == 0x000000)
			p->color = 0xFF0000FF;
		else if (z <= 360 && p->color == 0x000000)
			p->color = 0x00FF00FF;
		else if (z <= 540 && p->color == 0x000000)
			p->color = 0x0000FFF0;
		else if (z <= 720 && p->color == 0x000000)
			p->color = 0xA020F0FF;
		else if (p->color == 0x000000)
			p->color = 0xD9D9D9FF;
	}
}

void	offset(double *x0, double *y0, double *x1, double *y1)
{
	double	ax = *x0, ay = *y0, bx = *x1, by = *y1;

	*x0 = (1800 + ax);
	*y0 = (380 + ay);
	*x1 = (1800 + bx);
	*y1 = (380 + by);
}

int	draw(int **m, uint32_t **color, int height, int length) // int **color
{
	mlx_t		*mlx;
	mlx_image_t	*img;
	long int	x;
	long int	y;
	long int	z;
	t_point		a;
	t_point		b;

	mlx = mlx_init(WIDTH, HEIGHT, "FDF", true);
	img = mlx_new_image(mlx, WIDTH, HEIGHT);
	ft_memset(img->pixels, 255, img->width * img->height * sizeof(int32_t));
	y = (HEIGHT - 100) / height;
	x = (WIDTH - 100) / length;
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < length; j++)
		{
			if (i < height - 1 && j < length - 1)
			{
				z = m[i][j] * 5;
				init_point(&a, color, i, j, z);
				createpoint(&a, x, y, z, j, i, color);
				z = m[i][j + 1] * 5;
				init_point(&b, color, i, j + 1, z);
				createpoint(&b, x, y, z, j + 1, i, color);
				iso(&a.x, &a.y, a.z);
				iso(&b.x, &b.y, b.z);
				offset(&a.x, &a.y, &b.x, &b.y);
				drawline(img, a.x, b.x, a.y, b.y, a.color, b.color);
				z = m[i][j] * 5;
				init_point(&a, color, i, j, z);
				createpoint(&a, x, y, z, j, i, color);
				z = m[i + 1][j] * 5;
				init_point(&b, color, i + 1, j, z);
				createpoint(&b, x, y, z, j, i + 1, color);
				iso(&a.x, &a.y, a.z);
				iso(&b.x, &b.y, b.z);
				offset(&a.x, &a.y, &b.x, &b.y);
				drawline(img, a.x, b.x, a.y, b.y, a.color, b.color);
			}
			else if (j == length - 1 && i != height - 1)
			{
				z = m[i][j] * 5;
				init_point(&a, color, i, j, z);
				createpoint(&a, x, y, z, j, i, color);
				z = m[i + 1][j] * 5;
				init_point(&b, color, i + 1, j, z);
				createpoint(&b, x, y, z, j, i + 1, color);
				iso(&a.x, &a.y, a.z);
				iso(&b.x, &b.y, b.z);
				offset(&a.x, &a.y, &b.x, &b.y);
				drawline(img, a.x, b.x, a.y, b.y, a.color, b.color);
			}
			else if (j != length - 1 && i == height - 1)
			{
				z = m[i][j] * 5;
				init_point(&a, color, i, j, z);
				createpoint(&a, x, y, z, j, i, color);
				z = m[i][j + 1] * 5;
				init_point(&b, color, i, j + 1, z);
				createpoint(&b, x, y, z, j + 1, i, color);
				iso(&a.x, &a.y, a.z);
				iso(&b.x, &b.y, b.z);
				offset(&a.x, &a.y, &b.x, &b.y);
				drawline(img, a.x, b.x, a.y, b.y, a.color, b.color);
			}
		}
	}
	mlx_image_to_window(mlx, img, 0, 0);
	mlx_key_hook(mlx, &my_keyhook, mlx);
	mlx_loop(mlx);
	mlx_delete_image(mlx, img);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
