/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawlines.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shimi-be <shimi-be@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 10:18:06 by shimi-be          #+#    #+#             */
/*   Updated: 2025/02/04 16:25:03 by shimi-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	iscorr(t_point *p0)
{
	if (p0->x < 0)
		p0->x = 0;
	else if (p0->x >= WIDTH)
		p0->x = WIDTH - 1;
	if (p0->y < 0)
		p0->y = 0;
	else if (p0->y >= HEIGHT)
		p0->y = HEIGHT - 1;
}

void	drawlinehigh(mlx_image_t *img, t_point p0, t_point p1)
{
	int	dx;
	int	dy;
	int	xi;
	int	d;
	int	y;

	dy = p1.y - p0.y;
	init_x(&dx, &xi, &p0, &p1);
	d = 2 * dy - dx;
	y = p0.y;
	while (p0.y < p1.y)
	{
		iscorr(&p0);
		mlx_put_pixel(img, p0.x, p0.y, p0.color);
		if (d > 0)
		{
			p0.x = p0.x + xi;
			d = d + (2 * (dx - dy));
		}
		else
			d = d + 2 * dx;
		p0.y++;
		if (p0.y > y + ((p1.y - y) / 2))
			p0.color = p1.color;
	}
}

void	drawlinelow(mlx_image_t *img, t_point p0, t_point p1)
{
	int	dx;
	int	dy;
	int	yi;
	int	d;
	int	x;

	dx = p1.x - p0.x;
	init_y(&dy, &yi, &p0, &p1);
	d = 2 * dy - dx;
	x = p0.x;
	while (p0.x < p1.x)
	{
		iscorr(&p0);
		mlx_put_pixel(img, p0.x, p0.y, p0.color);
		if (d > 0)
		{
			p0.y = p0.y + yi;
			d = d + (2 * (dy - dx));
		}
		else
			d = d + 2 * dy;
		p0.x++;
		if (p0.x > x + ((p1.x - x) / 2))
			p0.color = p1.color;
	}
}

void	drawline(mlx_image_t *img, t_point p0, t_point p1)
{
	if (abs(p1.y - p0.y) < abs(p1.x - p0.x))
	{
		if (p0.x > p1.x)
			drawlinelow(img, p1, p0);
		else
			drawlinelow(img, p0, p1);
	}
	else
	{
		if (p0.y > p1.y)
			drawlinehigh(img, p1, p0);
		else
			drawlinehigh(img, p0, p1);
	}
}
