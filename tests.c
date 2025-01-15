/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shimi-be <shimi-be@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 16:59:37 by shimi-be          #+#    #+#             */
/*   Updated: 2025/01/15 16:02:20 by shimi-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "srclibs/get_next_line/get_next_line.h"
#include "srclibs/libft/libft.h"
#include "srclibs/ft_printf/libprintft.h"
#include <stdlib.h>
#include <fcntl.h>

/*
//Free the line and all the contents of the matrix if malloc fails ttbrosk
void ralloc(char*** matriu, int height, char *line)
{
	int i;
	char **splitline;
	char **tempmat;

	i = 0;
	tempmat = *matriu;
	*matriu = (char **) malloc (height*sizeof(char*));
	if (!matriu)
		return (NULL);
	while (i < height-2)
	{
		*matriu[i] = tempmat[i];
		i++;
	}
	*matriu[i] = line;
	free(tempmat);
}

int corr_inp(char *input)
{
	return (1);
}
*/
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
	newmatrix[height-1] = (int*)malloc(len*sizeof(int));
	for (int i = 0; i < len; i++)
		newmatrix[height-1][i] = ft_atoi(line[i]);
	free(matrix);
	return (newmatrix);
}

int **get_values(int fd)
{
	char *line;
	int **atoiline;
	int **temp;
	char **splitline;
	int height;

	temp = NULL;
	atoiline = NULL;
	height = 0;
	line = get_next_line(fd);
	int lenline = getlen(ft_split(line, ' '));
	while (line)
	{
		height++;
		splitline = ft_split(line, ' ');
		if (atoiline)
			temp = atoiline;
		atoiline = ft_lineatoi(atoiline, splitline, height);
		free (splitline);
		line = get_next_line(fd);
	}
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < lenline; j++)
		{
			ft_printf("%i ",atoiline[i][j]);
		}
		ft_printf("\n");
	}

	return (atoiline);
}

int main(int ac, char *av[])
{
	int **mat;
	int height;//move this to another functions
	height = 0;// """"""""""""
	if (ac < 2)
	{
		ft_printf("Please provide a file.");
		return (-1);
	}
	else if (ac > 2)
	{
		ft_printf("Please provide only one file.");
		return (-1);
	}
	else 
	{
		if (ac == 2)
		{
			int fd = open(av[1],O_RDONLY);
			mat = get_values(fd);
		}
		else
		{
			ft_printf("Provide a .fdf file.");
			return (-1);
		}
	}
}
