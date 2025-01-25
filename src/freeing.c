/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freeing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shimi-be <shimi-be@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 12:54:27 by shimi-be          #+#    #+#             */
/*   Updated: 2025/01/25 14:06:16 by shimi-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	freem(int **mat, int height)
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

void	freea(char **splitline, char *line, char *trimline)
{
	free_sp(splitline);
	free(line);
	free(trimline);
}
