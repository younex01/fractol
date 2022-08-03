/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tricorn.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelousse <yelousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 18:19:48 by yelousse          #+#    #+#             */
/*   Updated: 2022/08/02 14:58:09 by yelousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void ft_tricorn(int x, int y, t_mlx *move)
{
	int it;
	t_complex c, z, t;

	it = 1;
	c.r= move->re_min + (x + move->lr) / (double)W * (move->re_max - move->re_min);
	c.i = move->im_min + (y + move->ud) / (double)W * (move->im_max - move->im_min);
	z.r = 0.0;
	z.i = 0.0;
	t = z;
	while (z.r * z.r + z.i * z.i < 4 && it < MAX_IT)
	{
		t.r = (z.r * z.r - z.i * z.i + c.r);
		t.i = (-2 * z.r * z.i + c.i);
		z = t;
		it++;
	}
	if (it == MAX_IT)
		move->img_str[y * W + x ] = 0x000000;
	else
		move->img_str[y * W + x ] = 0xFF0800 * it;
}