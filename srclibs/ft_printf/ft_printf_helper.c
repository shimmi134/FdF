/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_helper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shimi-be <shimi-be@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 13:27:49 by shimi-be          #+#    #+#             */
/*   Updated: 2024/10/07 15:24:04 by shimi-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprintft.h"

void	ft_print_num(int num, char type, int *count)
{
	if (type == 'u')
		ft_putnbr_u((unsigned int)num, count);
	else if (type == 'i' || type == 'd')
		ft_putnbr(num, type, count);
	else
		ft_putnbr_hex((unsigned int) num, type, count);
}

void	ft_print_dir(void *ptr, int *count)
{
	if (!ptr)
	{
		ft_print_str("(nil)", count);
		return ;
	}
	ft_putdir(ptr, count);
}

void	ft_print_str(char *str, int *count)
{
	int	i;

	i = 0;
	if (!str)
	{
		ft_print_str("(null)", count);
		return ;
	}
	while (str[i])
	{
		ft_print_char(str[i], count);
		if (*count == -1)
			return ;
		i++;
	}
}

void	ft_print_char(int chr, int *count)
{
	if (write(1, &chr, 1) > 0 && *count != -1)
		*count += 1;
	else
	{
		*count = -1;
		return ;
	}
}
