/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol__bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelousse <yelousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 02:15:44 by yelousse          #+#    #+#             */
/*   Updated: 2022/08/07 02:16:56 by yelousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	change_color(t_mlx *move)
{
	static int	color[] = {
		0xFF0800,
		0xA0F00F,
		265,
		4147,
		0xff0401,
		0x001100,
		0xcbcfd3,
		0xfafbff,
		0x9,
		0x020202,
		0x050000
	};

	move->change = color[move->i];
	move->i++;
	if (move->i == 10)
		move->i = 0;
}

void	add_iter(t_mlx *move)
{
	move->max_it += 20;
}

void	reduce_iter(t_mlx *move)
{
	move->max_it -= 20;
}
