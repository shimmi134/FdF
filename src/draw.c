/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shimi-be <shimi-be@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 12:22:23 by shimi-be          #+#    #+#             */
/*   Updated: 2025/02/04 15:57:15 by shimi-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

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

void	iso(int *x, int *y, int z)
{
	int	previous_x;
	int	previous_y;

	previous_x = *x;
	previous_y = *y;
	*x = (previous_x - previous_y) * cos(0.785398);
	*y = -z + (previous_x + previous_y) * sin(0.615472907);
}

t_point	createpoint(long int *axis, long int j, long int i, uint32_t **color)
{
	t_point	p;

	p.x = (axis[0] * (j)) / 2.5;
	p.y = (axis[1] * (i)) / 2.5;
	p.z = axis[2];
	p.color = 0x000000;
	if (!color)
	{
		if (p.z < 0)
			p.color = 0x000000FF;
		else if (p.z == 0 && p.color == 0x000000)
			p.color = 0x808080FF;
		else if (p.z <= 180 && p.color == 0x000000)
			p.color = 0xFF0000FF;
		else if (p.z <= 360 && p.color == 0x000000)
			p.color = 0x00FF00FF;
		else if (p.z <= 540 && p.color == 0x000000)
			p.color = 0xA020F0FF;
		else if (p.color == 0x000000)
			p.color = 0xD9D9D9FF;
	}
	else
		p.color = color[i][j];
	return (p);
}

void	offset(int *x0, int *y0, int *x1, int *y1)
{
	*x0 = (800 + *x0);
	*y0 = (180 + *y0);
	*x1 = (800 + *x1);
	*y1 = (180 + *y1);
}

int	draw(t_map maps, int height, int length)
{
	long int	axis[3];

	axis[0] = (WIDTH - 100) / length;
	axis[1] = (HEIGHT - 100) / height;
	getpoints(maps, height, length, axis);
	mlx_image_to_window(maps.mlx, maps.img, 0, 0);
	mlx_key_hook(maps.mlx, my_keyhook, maps.mlx);
	mlx_loop(maps.mlx);
	mlx_delete_image(maps.mlx, maps.img);
	mlx_terminate(maps.mlx);
	return (EXIT_SUCCESS);
}
