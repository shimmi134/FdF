/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tryingtihngs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shimi-be <shimi-be@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 12:48:45 by shimi-be          #+#    #+#             */
/*   Updated: 2025/01/20 12:54:12 by shimi-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
	x = (WIDTH - 400) / length;
	z = 150
	a = createPoint(x,y,z,j,i);
	b = createPoint(x,y,z,j+1,i);
	iso(&a.x,&a.y,a.z);
	iso(&b.x,&b.y,b.z);
	offset(&a.x,&a.y,&b.x,&b.y);
	drawLine(img, a.x,b.x,a.y,b.y);
	mlx_image_to_window(mlx, img, 0, 0);
	mlx_key_hook(mlx, &my_keyhook, mlx);
	mlx_loop(mlx);
	mlx_delete_image(mlx,img);
	mlx_terminate(mlx);
}

