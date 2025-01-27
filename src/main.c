/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shimi-be <shimi-be@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 12:57:49 by shimi-be          #+#    #+#             */
/*   Updated: 2025/01/27 18:45:43 by shimi-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	read_and_draw(t_map maps, char *input)
{
	int	height;
	int	length;
	int	fd;
	int	val;

	fd = open(input, O_RDONLY);
	if (fd < 0)
		return (ft_printf("Error Opening. Check that it exist.\n"), -1);
	height = 0;
	maps.map = get_values(fd, &maps.colormap, &height, &length);
	if (!maps.map)
	{
		ft_printf("Error creating. Check the map is correct.\n");
		return (-1);
	}
	//maps.mlx = mlx_init(WIDTH, HEIGHT, "FDF", true);
	//maps.img = mlx_new_image(maps.mlx, WIDTH, HEIGHT);
	//ft_memset(maps.img->pixels, 255, maps.img->width * maps.img->height
//		* sizeof(int32_t));
	val = draw(maps, height, length);
	freem(maps.map, height);
	if (maps.colormap)
		free_mat_color(maps.colormap, height);
	return (1);
}

int	main(int ac, char *av[])
{
	t_map	maps;

	maps.colormap = NULL;
	maps.map = NULL;
	if (ac < 2)
		return (ft_printf("Please provide a file.\n"), -1);
	else if (ac > 2)
		return (ft_printf("Please provide only one file.\n"), -1);
	else
	{
		if (corr_inp(av[1]))
			read_and_draw(maps, av[1]);
		else
			return (ft_printf("Provide a correct .fdf file.\n"), -1);
	}
	return (EXIT_SUCCESS);
}
