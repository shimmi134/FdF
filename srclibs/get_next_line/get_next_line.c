/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shimi-be <shimi-be@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 18:34:32 by shimi-be          #+#    #+#             */
/*   Updated: 2025/01/25 18:37:00 by shimi-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*find_nl(char *arr)
{
	int	i;

	i = 0;
	if (!arr)
		return (NULL);
	while (arr[i])
	{
		if (arr[i] == '\n')
			return (arr);
		i++;
	}
	return (NULL);
}

char	*mall_buff(void)
{
	char	*buff;

	buff = (char *) malloc (BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	buff[0] = '\0';
	return (buff);
}

char	*get_next_line(int fd)
{
	static char	*stash = NULL;
	char		*arr;
	char		*temp;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	temp = NULL;
	if (!stash || !ft_strchr(stash, 0))
	{
		if (stash && !ft_strchr(stash, 0))
			temp = ft_strjoin(NULL, stash);
		free(stash);
		stash = get_line(stash, fd, 1);
		arr = stash;
		stash = ft_strjoin(temp, stash);
		free(arr);
		free(temp);
	}
	arr = trim_line(stash);
	if (!arr)
		return (free(stash), NULL);
	temp = stash;
	stash = ft_strchr(stash, 1);
	return (free(temp), arr);
}
