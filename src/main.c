/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shimi-be <shimi-be@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 12:57:49 by shimi-be          #+#    #+#             */
/*   Updated: 2025/01/24 17:34:50 by shimi-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	main(int ac, char *av[])
{
	t_map	maps;
	int		height;
	int		length;
	int		val;
	int		fd;

	maps.colormap = NULL;
	maps.map = NULL;
	if (ac < 2)
	{
		ft_printf("Please provide a file.\n");
		return (-1);
	}
	else if (ac > 2)
	{
		ft_printf("Please provide only one file.\n");
		return (-1);
	}
	else
	{
		if (corr_inp(av[1]))
		{
			fd = open(av[1], O_RDONLY);
			if (fd < 0)
			{
				ft_printf("Error Opening the file. Check that it exist.\n");
				return (-1);
			}
			maps.map = get_values(fd, &maps.colormap, &height, &length);
			if (!maps.map)
			{
				ft_printf("Error creating the matrix.");
				ft_printf("Check the map is correct.\n");
				return (-1);
			}
			maps.mlx = mlx_init(WIDTH, HEIGHT, "FDF", true);
			maps.img = mlx_new_image(maps.mlx, WIDTH, HEIGHT);
			ft_memset(maps.img->pixels, 255, maps.img->width * maps.img->height
				* sizeof(int32_t));
			val = draw(maps, height, length);
			free_mat(maps.map, height);
			if (maps.colormap)
				free_mat_color(maps.colormap, height);
		}
		else
		{
			ft_printf("Provide a correct .fdf file.\n");
			return (-1);
		}
	}
	return (EXIT_SUCCESS);
}
