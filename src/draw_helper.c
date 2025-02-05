/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shimi-be <shimi-be@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 15:34:25 by shimi-be          #+#    #+#             */
/*   Updated: 2025/01/28 13:32:04 by shimi-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	getpoints(t_map maps, int height, int length, long int *axis)
{
	int	i;
	int	j;

	i = 0;
	while (i < height)
	{
		j = 0;
		while (j < length)
		{
			axis[2] = maps.map[i][j] * 5;
			if (i < height - 1 && j < length - 1)
			{
				getpointsj(axis, i, j, maps);
				getpointsi(axis, i, j, maps);
			}
			else if (j == length - 1 && i != height - 1)
				getpointsj(axis, i, j, maps);
			else if (j != length - 1 && i == height - 1)
				getpointsi(axis, i, j, maps);
			j++;
		}
		i++;
	}
}

void	init_y(int *dy, int *yi, t_point *p0, t_point *p1)
{
	*dy = p1->y - p0->y;
	*yi = 1;
	if (*dy < 0)
	{
		*yi = -1;
		*dy = -*dy;
	}
}

void	init_x(int *dx, int *xi, t_point *p0, t_point *p1)
{
	*dx = p1->x - p0->x;
	*xi = 1;
	if (*dx < 0)
	{
		*xi = -1;
		*dx = -*dx;
	}
}
