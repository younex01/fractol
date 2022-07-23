/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelousse <yelousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 17:27:33 by yelousse          #+#    #+#             */
/*   Updated: 2022/07/23 21:39:01 by yelousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void ft_julia(int x, int y, t_mlx *move)
{
	int it;
	t_complex c, z, t;

	it = 1;
	c.r = 0.285;
	c.i = 0.01;
	z.r = move->re_min + x / (double)W * (move->re_max - move->re_min);
	z.i = move->im_min + y / (double)W * (move->im_max - move->im_min);
	t = z;
	while (z.r * z.r + z.i * z.i < 4 && it < MAX_IT)
	{
		t.r = (z.r * z.r - z.i * z.i + c.r);
		t.i = (2 * z.r * z.i + c.i);
		z = t;
		it++;
	}
	if (it == MAX_IT)
		move->img_str[(y + move->ud) * W + (x + move->lr)] = 0x000000;
	else
		move->img_str[(y + move->ud) * W + (x + move->lr)] = 0xA0F00F * (it);
}