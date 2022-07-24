/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelousse <yelousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 23:37:31 by yelousse          #+#    #+#             */
/*   Updated: 2022/07/24 23:51:17 by yelousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void ft_burningship(int x, int y, t_mlx *move)
{
	int it;
	t_complex c, z, t;

	it = 1;
	c.r= move->re_min + (x + move->lr) / (double)W * (move->re_max - move->re_min);
	c.i = move->im_min + (y + move->ud) / (double)W * (move->im_max - move->im_min);
	z.r = 0.0;
	z.i = 0.0;
	t = z;
	while (fabs(z.r) * fabs(z.r) + fabs(z.i) * fabs(z.i) < 4 && it < MAX_IT)
	{
		t.r = (fabs(z.r) * fabs(z.r) - fabs(z.i) * fabs(z.i) + c.r);
		t.i = (2 * fabs(z.r) * fabs(z.i) + c.i);
		z = t;
		it++;
	}
	if (it == MAX_IT)
		move->img_str[y * W + x ] = 0x000000;
	else
		move->img_str[y * W + x ] = 0x050000 * it;
}