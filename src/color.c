/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shimi-be <shimi-be@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 15:35:12 by shimi-be          #+#    #+#             */
/*   Updated: 2025/02/04 16:24:54 by shimi-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

t_point	createpoint(long int *axis, long int j, long int i, uint32_t **color)
{
	t_point	p;

	p.x = (axis[0] * (j)) / 2.5;
	p.y = (axis[1] * (i)) / 2.5;
	p.z = axis[2];
	p.color = 0x000000;
	if (!color)
	{
		if (p.z < 0)
			p.color = 0x000000FF;
		else if (p.z == 0 && p.color == 0x000000)
			p.color = 0x808080FF;
		else if (p.z <= 180 && p.color == 0x000000)
			p.color = 0xFF0000FF;
		else if (p.z <= 360 && p.color == 0x000000)
			p.color = 0x00FF00FF;
		else if (p.z <= 540 && p.color == 0x000000)
			p.color = 0xA020F0FF;
		else if (p.color == 0x000000)
			p.color = 0xD9D9D9FF;
	}
	else
		p.color = color[i][j];
	return (p);
}
