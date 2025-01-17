/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shimi-be <shimi-be@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 16:59:37 by shimi-be          #+#    #+#             */
/*   Updated: 2025/01/17 11:04:51 by shimi-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "srclibs/get_next_line/get_next_line.h"
#include "srclibs/libft/libft.h"
#include "srclibs/ft_printf/libprintft.h"
#include <stdlib.h>
#include <fcntl.h>


int corr_inp(char *input)
{
	char *end;

	end = ft_strrchr(input, '.');
	if (end && ft_strncmp(end, ".fdf", ft_strlen(end)) == 0)
		return 1;
	return 0;


}

int getlen(char **line)
{
	int i;

	i = 0;
	while (line[i])
		i++;
	return (i);
}

int **ft_lineatoi(int **matrix, char **line, int height)
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
int **get_values(int fd, int* height)
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
		free_sp(splitline);
		free(line);
		line = get_next_line(fd);
	}
	return (atoiline);
}

int main(int ac, char *av[])
{
	int **mat;
	int height;
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
			mat = get_values(fd, &height);
			free_mat(mat, height);

		}
		else
		{
			ft_printf("Provide a .fdf file.\n");
			return (-1);
		}
	}
}
