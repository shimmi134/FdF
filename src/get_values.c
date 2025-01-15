/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_values.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shimi-be <shimi-be@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 16:59:37 by shimi-be          #+#    #+#             */
/*   Updated: 2025/01/14 18:38:10 by shimi-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line/get_next_line.h"
#include "libft/libft.h"


//Free the line and all the contents of the matrix if malloc fails ttbrosk
void ralloc(char*** matriu, int height, char *line)
{
	int i;
	char **splitline;
	char **tempmat;

	i = 0;
	splitline = ft_split(line, ' ');
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

char **get_values(int fd, int *height, int *len)
{
	char *line;
	char **matriu;
	matriu = NULL;
	line = get_next_line(fd);
	while (line)
	{
		*height++;
		ralloc(&matriu, height, line);
		line = get_next_line(fd);
	}
	return (matriu);

}

int main(int ac, char *av[])
{
	char **mat;
	int height;//move this to another functions
	height = 0;// """"""""""""
	int len;
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
		if (corr_inp(av[1]))
		{
			fd = open(av[1],O_RDONLY);
			mat = get_values(fd, &height, &len);
			for (int i = 0; i < height; i++)
			{
				for (int i = 0; i <)
			}
		}
		else
		{
			ft_printf("Provide a .fdf file.")
			return (-1);
		}
	}
}
