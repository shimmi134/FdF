/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shimi-be <shimi-be@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 13:24:44 by shimi-be          #+#    #+#             */
/*   Updated: 2024/10/07 15:24:05 by shimi-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprintft.h"

int	ft_printf(char const *str, ...)
{
	va_list	args;
	int		i;
	int		count;

	count = 0;
	i = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
			choose_type(str[++i], args, &count);
		else
			ft_print_char(str[i], &count);
		if (count == -1)
			return (-1);
		i++;
	}
	va_end(args);
	return (count);
}

void	choose_type(char c, va_list args, int *count)
{
	if (c == 'd' || c == 'i' || c == 'u' || c == 'x' || c == 'X')
		ft_print_num(va_arg(args, int), c, count);
	else if (c == 's')
		ft_print_str(va_arg(args, char *), count);
	else if (c == 'p')
		ft_print_dir(va_arg(args, void *), count);
	else if (c == 'c')
		ft_print_char(va_arg(args, int), count);
	else if (c == '%')
		ft_print_char('%', count);
}
