/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sierpinskis_carpet.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelousse <yelousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 23:21:32 by yelousse          #+#    #+#             */
/*   Updated: 2022/07/26 23:31:16 by yelousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void ft_sierpinski(int x, int y, t_mlx *move)
{
	int it;
	t_complex c, z, t;

	it = 1;
	c.r= move->re_min + (x + move->lr) / (double)W * (move->re_max - move->re_min);
	c.i = move->im_min + (y + move->ud) / (double)W * (move->im_max - move->im_min);
	z.r = 0.0;
	z.i = 0.0;
	t = z;
	while (it < MAX_IT)
	{
        if ((int)c.r % 3 == 1 && (int)c.i % 3 == 1)
            break;
		c.r *= 3;
		c.i *= 3;
		it++;
	}
	if (it == MAX_IT)
		move->img_str[y * W + x ] = 0x000000;
	else
		move->img_str[y * W + x ] = 265 * it;
}