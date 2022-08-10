/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelousse <yelousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 01:54:33 by yelousse          #+#    #+#             */
/*   Updated: 2022/08/10 22:43:05 by yelousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	interp(double start, double end, double interpolation)
{
	return (start + ((end - start) * interpolation));
}

void	zoom(t_mlx *move)
{
	double	mouse_re;
	double	mouse_im;

	mouse_re = (((double) move->lr) / (W / move->re_min));
	mouse_im = (((double) move->ud) / (H / move->im_min));
	move->re_min = interp(mouse_re, move->re_min, move->coef);
	move->im_min = interp(mouse_im, move->im_min, move->coef);
	move->re_max = interp(mouse_re, move->re_max, move->coef);
	move->im_max = interp(mouse_im, move->im_max, move->coef);
	ft_draw(move, move->f);
}

int	mouse_press(int button, int x, int y, t_mlx *move)
{
	if (button == 4)
	move->coef = 1.1;
	else if (button == 5)
	move->coef = 0.9;
	move->mx = x;
	move->my = y;
	zoom(move);
	return (0);
}

int	keypress(int keycode, t_mlx *move)
{
	if (keycode == 53 && move)
		exit(0);
	ft_draw(move, move->f);
	return (0);
}

int	ft_close(void *param)
{
	(void)param;
	exit(0);
	return (0);
}
