/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_helper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shimi-be <shimi-be@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 14:05:07 by shimi-be          #+#    #+#             */
/*   Updated: 2025/01/28 17:20:51 by shimi-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	corr_inp(char *input)
{
	char	*end;

	end = ft_strrchr(input, '.');
	if (ft_strlen(end) > 4 || ft_strlen(end) < 4)
		return (0);
	if (end && ft_strncmp(end, ".fdf", ft_strlen(end)) == 0)
		return (1);
	return (0);
}

int	getlen(char **line)
{
	int	i;

	i = 0;
	while (line[i])
		i++;
	return (i);
}

int	check_hex(char **line, int j)
{
	int	i;

	i = 0;
	while (i < getlen(line) && line[j][i])
	{
		if (line[j][i] == ',')
			return (i);
		i++;
	}
	return (0);
}

void	copy_and_free_matrix(int **newmatrix, int **matrix, int height, int len)
{
	int	i;
	int	j;

	i = 0;
	while (i < height - 1)
	{
		newmatrix[i] = (int *)malloc(len * sizeof(int));
		if (!newmatrix[i])
			return ;
		j = 0;
		while (j < len)
		{
			newmatrix[i][j] = matrix[i][j];
			j++;
		}
		free(matrix[i]);
		i++;
	}
	free(matrix);
}

void	copy_and_free_color_matrix(uint32_t **newcolor, uint32_t **colorit,
		int height, int len)
{
	int	i;
	int	j;

	i = 0;
	while (i < height - 1)
	{
		newcolor[i] = (uint32_t *)malloc(len * sizeof(uint32_t));
		if (!newcolor[i])
		{
			newcolor = NULL;
			return ;
		}
		j = 0;
		while (j < len)
		{
			newcolor[i][j] = colorit[i][j];
			j++;
		}
		free(colorit[i]);
		i++;
	}
	free(colorit);
}
