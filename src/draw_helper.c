/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shimi-be <shimi-be@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 15:34:25 by shimi-be          #+#    #+#             */
/*   Updated: 2025/01/27 19:59:40 by shimi-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

t_point	**create_map_point(int height, int length)
{
	t_point	**map;
	int		i;

	i = 0;
	map = malloc(sizeof(t_point*) * height);
	if(!map)
		return (NULL);
	while (i < height)
	{
		map[i] = malloc(sizeof(t_point) * length);
		if (!map[i])
			return (NULL); // freeeeee
		i++;
	}
	return (map);
}

void	getpoints(t_map *maps, int height, int length, long int *axis)
{
	int	i;
	int	j;

	i = 0;
	maps->point_map = create_map_point(height, length);
	while (i < height)
	{
		j = 0;
		while (j < length)
		{
			axis[2] = maps->map[i][j] * 5;
			if (i < height - 1 && j < length - 1)
			{
				getpointsj(axis, i, j, *maps);
				getpointsi(axis, i, j, *maps);
			}
			else if (j == length - 1 && i != height - 1)
				getpointsj(axis, i, j, *maps);
			else if (j != length - 1 && i == height - 1)
				getpointsi(axis, i, j, *maps);
			
			maps->point_map[i][j] = createpoint(axis, j, i, maps->colormap);
			ft_printf("pointmap[i][j]: %i\n", maps->point_map[i][j].x);
			ft_printf("pointmap[i][j]: %i\n", maps->point_map[i][j].y);
			ft_printf("pointmap[i][j]: %i\n", maps->point_map[i][j].z);
			j++;
		}
		i++;
	}
	print_point_mat(maps->point_map, length, height);
}

void	print_point_mat(t_point **map, int length, int height)
{
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < length; j++)
		{
			ft_printf("x: %i\n", map[i][j].x);
			ft_printf("y: %i\n", map[i][j].y);
			ft_printf("z: %i\n", map[i][j].z);
		}
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
