/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shimi-be <shimi-be@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 13:33:29 by shimi-be          #+#    #+#             */
/*   Updated: 2025/01/24 13:33:41 by shimi-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	dothing(t_point a, t_point b, t_map map)
{
	iso(&a.x, &a.y, a.z);
	iso(&b.x, &b.y, b.z);
	offset(&a.x, &a.y, &b.x, &b.y);
	drawline(map.img, a, b);
}

void	dootherthing(long int *axis, int i, int j, t_map map)
{
	t_point		a;
	t_point		b;

	axis[2] = map.map[i][j] * 5;
	a = createpoint(axis, j, i, map.colormap);
	axis[2] = map.map[i][j + 1] * 5;
	b = createpoint(axis, j + 1, i, map.colormap);
	dothing(a, b, map);
}

void	dootherotherthing(long int *axis, int i, int j, t_map map)
{
	t_point		a;
	t_point		b;

	axis[2] = map.map[i][j] * 5;
	a = createpoint(axis, j, i, map.colormap);
	axis[2] = map.map[i + 1][j] * 5;
	b = createpoint(axis, j, i + 1, map.colormap);
	dothing(a, b, map);
}
