/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia_33_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelousse <yelousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 17:27:33 by yelousse          #+#    #+#             */
/*   Updated: 2022/08/07 01:34:43 by yelousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// int		mouse_move(int x, int y, t_mlx *move)
// {
// 	move->mx = x;
// 	move->my = y;
// 	ft_draw(move, move->f);
// 	return (0);
// }

void	ft_julia_33_bonus(int x, int y, t_mlx *move)
{
	int			it;
	t_complex	c;
	t_complex	z;
	t_complex	t;

	it = 1;
	c.r = 0.285;
	c.i = 0.01;
	z.r = move->re_min + (x + move->lr)
		/ (double)W * (move->re_max - move->re_min);
	z.i = move->im_min + (y + move->ud)
		/ (double)W * (move->im_max - move->im_min);
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
		move->img_str[y * W + x] = move->change * (it);
}
