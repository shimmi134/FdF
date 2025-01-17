/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shimi-be <shimi-be@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 16:59:37 by shimi-be          #+#    #+#             */
/*   Updated: 2025/01/17 13:15:38 by shimi-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "srclibs/get_next_line/get_next_line.h"
#include "srclibs/libft/libft.h"
#include "srclibs/ft_printf/libprintft.h"
#include <stdlib.h>
#include <fcntl.h>
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

int corr_inp(char *input)
{
	char *end;

	end = ft_strchr_lift(input, '.');
	if (ft_strlen(end) > 4 || ft_strlen(end) < 4)
		return (0);
	if (end && ft_strncmp(end, ".fdf", ft_strlen(end)) == 0)
		return (1);
	return (0);
}

int getlen(char **line)
{
	int i;

	i = 0;
	while (line[i])
		i++;
	return (i);
}

int **ft_lineatoi(int **matrix, char **line, int height) //COmprovar que las lineas son iguals
{
	int len;
	int **newmatrix;
	len = getlen(line);
	newmatrix = (int **)malloc(height*sizeof(int*));
	for (int j = 0; j < height-1; j++)
	{
		newmatrix[j] = (int*)malloc(len*sizeof(int));
		for (int i = 0; i < len; i++)
		{
			newmatrix[j][i] = matrix[j][i];
		}
		free(matrix[j]);
	}
	free(matrix);
	newmatrix[height-1] = (int*)malloc(len*sizeof(int));
	for (int i = 0; i < len; i++)
		newmatrix[height-1][i] = ft_atoi(line[i]);
	return (newmatrix);
}

void free_sp(char **line)
{
	int i;

	i = 0;
	while (i < getlen(line))
	{
		free(line[i]);
		i++;
	}
	free(line);
}

void free_mat(int **mat, int height)
{
	int i;

	i = 0;
	while (i < height)
	{
		free(mat[i]);
		i++;
	}
	free(mat);
}
int **get_values(int fd, int* height, int *len)
{
	char *line;
	int **atoiline;
	char **splitline;

	atoiline = NULL;
	line = get_next_line(fd);
	*height = 0;
	while (line)
	{
		*height += 1;
		splitline = ft_split(line, ' ');
		atoiline = ft_lineatoi(atoiline, splitline, *height);
		*len = getlen(splitline);
		free_sp(splitline);
		free(line);
		line = get_next_line(fd);
	}
	return (atoiline);
}



void draw(int **m, int height, int length)
{
	mlx_t* mlx;

	if (!(mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true)))
		return (EXIT_FAILURE);
	mlx_image_t* img = mlx_new_image(mlx, WIDTH, HEIGHT);
	memset(img->pixels, 255, img->width * img->height * sizeof(int32_t));

	
}

int main(int ac, char *av[])
{
	int **mat;
	int height;
	int length;

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
			int fd = open(av[1],O_RDONLY);
			if (fd < 0)
			{
				ft_printf("Error Opening the file. Check that it exist.\n");
				return (-1);
			}
			mat = get_values(fd, &height, &length);
			draw(mat, height, length);
			free_mat(mat, height);

		}
		else
		{
			ft_printf("Provide a correct .fdf file.\n");
			return (-1);
		}
	}
}
