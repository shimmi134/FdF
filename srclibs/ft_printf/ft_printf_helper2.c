/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_helper2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shimi-be <shimi-be@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 13:27:40 by shimi-be          #+#    #+#             */
/*   Updated: 2024/10/07 15:24:04 by shimi-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprintft.h"

void	ft_putnbr(int num, char c, int *count)
{
	if (num == -2147483648)
	{
		ft_print_str("-2147483648", count);
		return ;
	}
	if (num < 0)
	{
		num = -num;
		ft_print_char('-', count);
	}
	if (num > 9)
		ft_putnbr(num / 10, c, count);
	ft_print_char('0' + num % 10, count);
}

void	ft_putnbr_hex(unsigned long num, char c, int *count)
{
	char	*hex;

	if (c == 'X')
		hex = "0123456789ABCDEF";
	else
		hex = "0123456789abcdef";
	if (num > 15)
		ft_putnbr_hex(num / 16, c, count);
	ft_print_char(hex[num % 16], count);
}

void	ft_putdir(void *ptr, int *count)
{
	ft_print_str("0x", count);
	ft_putnbr_hex((unsigned long) ptr, 'x', count);
}

void	ft_putnbr_u(unsigned int num, int *count)
{
	if (num > 9)
		ft_putnbr_u(num / 10, count);
	ft_print_char('0' + num % 10, count);
}
