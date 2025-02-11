/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shimi-be <shimi-be@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 16:59:37 by shimi-be          #+#    #+#             */
/*   Updated: 2025/01/25 18:17:21 by shimi-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

uint32_t	ft_atoi_uint(const char *nptr)
{
	int			i;
	int			sign;
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

uint32_t	**colormatrix(uint32_t ***color, char **line, int height, int len)
{
	uint32_t	**newcolor;
	uint32_t	**colorit;
	int			i;

	colorit = *color;
	newcolor = (uint32_t **)malloc(height * sizeof(uint32_t *));
	if (!newcolor)
		return (NULL);
	copy_and_free_color_matrix(newcolor, colorit, height, len);
	newcolor[height - 1] = (uint32_t *)malloc(len * sizeof(int));
	if (!newcolor[height - 1])
		return (NULL);
	i = 0;
	while (i < len)
	{
		newcolor[height - 1][i] = ft_atoi_uint(line[i] + check_hex(line, i)
				+ 3);
		i++;
	}
	return (newcolor);
}

int	**ft_lineatoi(int **matrix, uint32_t ***color, char **line, int height)
{
	int	len;
	int	hexpresent;
	int	**newmatrix;
	int	i;

	hexpresent = check_hex(line, 0);
	len = getlen(line);
	newmatrix = (int **)malloc(height * sizeof(int *));
	if (!newmatrix)
		return (NULL);
	if (hexpresent > 0)
		*color = colormatrix(color, line, height, len);
	if (*color == NULL && hexpresent > 0)
		return (NULL);
	copy_and_free_matrix(newmatrix, matrix, height, len);
	newmatrix[height - 1] = (int *)malloc(len * sizeof(int));
	if (!newmatrix[height - 1])
		return (NULL);
	i = 0;
	while (i < len)
	{
		newmatrix[height - 1][i] = ft_atoi(line[i]);
		i++;
	}
	return (newmatrix);
}

int	**get_values(int fd, uint32_t ***color, int *height, int *len)
{
	char		*line;
	uint32_t	**colormat;
	int			**atoi;
	char		**split;
	char		*trim;

	atoi = NULL;
	colormat = NULL;
	line = get_next_line(fd);
	trim = ft_strtrim(line, " \n");
	split = ft_split(trim, ' ');
	*len = getlen(split);
	while (line)
	{
		*height += 1;
		if (*len != getlen(split))
			return (freea(split, line, trim), freem(atoi, *height - 1), NULL);
		atoi = ft_lineatoi(atoi, &colormat, split, *height);
		*len = getlen(split);
		freea(split, line, trim);
		line = get_next_line(fd);
		trim = ft_strtrim(line, " \n");
		split = ft_split(trim, ' ');
	}
	return (*color = colormat, atoi);
}
