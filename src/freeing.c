/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freeing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shimi-be <shimi-be@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 12:54:27 by shimi-be          #+#    #+#             */
/*   Updated: 2025/01/24 12:58:21 by shimi-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	free_mat(int **mat, int height)
{
	int	i;

	i = 0;
	while (i < height)
	{
		free(mat[i]);
		i++;
	}
	free(mat);
}

void	free_mat_color(uint32_t **mat, int height)
{
	int	i;

	i = 0;
	while (i < height)
	{
		free(mat[i]);
		i++;
	}
	free(mat);
}

void	free_sp(char **line)
{
	int	i;

	i = 0;
	while (i < getlen(line))
	{
		free(line[i]);
		i++;
	}
	free(line);
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
