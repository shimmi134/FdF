/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shimi-be <shimi-be@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 16:59:37 by shimi-be          #+#    #+#             */
/*   Updated: 2025/01/22 15:50:29 by shimi-be         ###   ########.fr       */
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


int corr_inp(char *input)
{
	char *end;

	end = ft_strchr_libft(input, '.');
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


int check_hex(char **line, int j)
{
	int i;

	i = 0;
	while (i < getlen(line) && line[j][i])
	{
		if (line[j][i] == ',')
			return (i);
		i++;
	}
	return (0);
}

uint32_t	ft_atoi_uint(const char *nptr)
{
	int	i;
	int	sign;
	uint32_t	result;

	i = 0;
	result = 0;
	sign = 1;
	while ((nptr[i] >= '\t' && nptr[i] <= '\r') || nptr[i] == 32)
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -sign;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = result * 10 + (nptr[i] - '0');
		i++;
	}
	return (result * sign);
}

uint32_t **colormatrix(uint32_t ***color, char **line, int height, int len) // finish function so I DONT HAVE TO DO IF HEXPRESENT
{
	uint32_t **newcolor;
	uint32_t **colorit;

	colorit = *color;
	newcolor = (uint32_t **)malloc(height*sizeof(uint32_t*));
	for (int j = 0; j < height-1; j++)
	{
		newcolor[j] = (uint32_t *)malloc(len*sizeof(uint32_t));
		for (int i = 0; i < len; i++)
			newcolor[j][i] = colorit[j][i];
		free(colorit[j]);
	}
	free(colorit);
	newcolor[height-1] = (uint32_t *) malloc (len * sizeof(int));
	for (int i = 0; i < len; i++)
		newcolor[height-1][i] = ft_atoi_uint(line[i]+check_hex(line,i)+3);
	return (newcolor);
	
}

int **ft_lineatoi(int **matrix, uint32_t*** color, char **line, int height) //COmprovar que las lineas son iguals
{
	int len;
	int hexPresent;
	int **newmatrix;

	hexPresent = check_hex(line,0);
	len = getlen(line);
	newmatrix = (int **)malloc(height*sizeof(int*));
	if (!newmatrix)
		return NULL;
	if (hexPresent > 0)
		*color = colormatrix(color, line, height, len);
	for (int j = 0; j < height-1; j++)
	{
		newmatrix[j] = (int*)malloc(len*sizeof(int));
		for (int i = 0; i < len; i++)
			newmatrix[j][i] = matrix[j][i];
		free(matrix[j]);
	}
	free(matrix);
	newmatrix[height-1] = (int*)malloc(len*sizeof(int));
	for (int i = 0; i < len; i++)
		newmatrix[height-1][i] = ft_atoi(line[i]);
	return (newmatrix);
}

int **get_values(int fd, uint32_t*** color, int* height, int *len)
{
	char *line;
	uint32_t **colormat;
	int **atoiline;
	char **splitline;
	char *trimline;

	atoiline = NULL;
	line = get_next_line(fd);
	trimline = ft_strtrim(line, " \n");
	splitline = ft_split(trimline, ' ');
	*len = getlen(splitline);
	colormat = NULL;
	*height = 0;
	while (line)
	{
		*height += 1;
		atoiline = ft_lineatoi(atoiline, &colormat, splitline, *height);
		if (*len != getlen(splitline))
			return (free_mat(atoiline, *height),free_sp(splitline), free(line), NULL);
		*len = getlen(splitline);
		free_sp(splitline);
		free(line);
		free(trimline);
		line = get_next_line(fd);
		trimline = ft_strtrim(line, " \n");
		splitline = ft_split(trimline, ' ');
	}
	*color = colormat;
	return (atoiline);
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



void print_mat(int **mat, int height, int length)
{
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < length; j++)
		{
			ft_printf("%i ", mat[i][j]);
		}
		ft_printf("\n");
	}
}


int main(int ac, char *av[])
{
	int **mat;
	uint32_t **color;
	int height;
	int length;
	int val;

	color = NULL;
	mat = NULL;
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
			mat = get_values(fd, &color, &height, &length);
			if (!mat)
			{
				ft_printf("Error creating the matrix. Check the map is correct.\n");
				return (-1);
			}
			val = draw(mat, color, height, length);
			print_mat(mat,height,length);
			free_mat(mat,height);
//			if (color)
//				free_mat(color,height);
		}	
		else
		{
			ft_printf("Provide a correct .fdf file.\n");
			return (-1);
		}
	}
	return(EXIT_SUCCESS);
}
