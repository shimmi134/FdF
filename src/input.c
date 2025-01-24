/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shimi-be <shimi-be@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 16:59:37 by shimi-be          #+#    #+#             */
/*   Updated: 2025/01/24 13:12:52 by shimi-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	corr_inp(char *input)
{
	char	*end;

	end = ft_strchr_libft(input, '.');
	if (ft_strlen(end) > 4 || ft_strlen(end) < 4)
		return (0);
	if (end && ft_strncmp(end, ".fdf", ft_strlen(end)) == 0)
		return (1);
	return (0);
}

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
	int			j;

	i = 0;
	colorit = *color;
	newcolor = (uint32_t **)malloc(height * sizeof(uint32_t *));
	while (i < height - 1)
	{
		j = 0;
		newcolor[i] = (uint32_t *)malloc(len * sizeof(uint32_t));
		while (j < len)
		{
			newcolor[i][j] = colorit[i][j];
			j++;
		}
		free(colorit[i]);
		i++;
	}
	free(colorit);
	newcolor[height - 1] = (uint32_t *)malloc(len * sizeof(int));
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
	int	j;

	i = 0;
	hexpresent = check_hex(line, 0);
	len = getlen(line);
	newmatrix = (int **)malloc(height * sizeof(int *));
	if (!newmatrix)
		return (NULL);
	if (hexpresent > 0)
		*color = colormatrix(color, line, height, len);
	while (i < height - 1)
	{
		j = 0;
		newmatrix[i] = (int *)malloc(len * sizeof(int));
		while (j < len)
		{
			newmatrix[i][j] = matrix[i][j];
			j++;
		}
		free(matrix[i]);
		i++;
	}
	free(matrix);
	newmatrix[height - 1] = (int *)malloc(len * sizeof(int));
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
	int			**atoiline;
	char		**splitline;
	char		*trimline;

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
			return (free_mat(atoiline, *height), free_sp(splitline), free(line),
				NULL);
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
