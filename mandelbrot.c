/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelousse <yelousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 16:10:51 by yelousse          #+#    #+#             */
/*   Updated: 2022/08/10 22:09:54 by yelousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_mandelbrot(int x, int y, t_mlx *move)
{
	int			it;
	t_complex	c;
	t_complex	z;
	t_complex	t;

	it = 1;
	c.r = move->re_min + x
		/ (double)W * (move->re_max - move->re_min);
	c.i = move->im_min + y
		/ (double)W * (move->im_max - move->im_min);
	z.r = 0.0;
	z.i = 0.0;
	t = z;
	while (z.r * z.r + z.i * z.i < 4 && it < move->max_it)
	{
		t.r = (z.r * z.r - z.i * z.i + c.r);
		t.i = (2 * z.r * z.i + c.i);
		z = t;
		it++;
	}
	if (it == move->max_it)
		move->img_str[y * W + x] = 0x000000;
	else
		move->img_str[y * W + x] = move->change * it;
}
