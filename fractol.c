/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelousse <yelousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 02:06:24 by yelousse          #+#    #+#             */
/*   Updated: 2022/08/10 23:03:16 by yelousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_draw(t_mlx *move, char f)
{
	int	i;
	int	j;

	i = 0;
	while (i < H)
	{
		j = 0;
		while (j < W)
		{
			if (f == 'm')
				ft_mandelbrot(j, i, move);
			if (f == 'j')
				ft_julia(j, i, move);
			j++;
		}
	i++;
	}
	mlx_put_image_to_window(move->mlx_ptr, move->win_ptr, move->img_ptr, 0, 0);
}

void	ft_ini(t_mlx *move)
{
	move->max_it = 100;
	move->re_min = -2;
	move->re_max = 2;
	move->im_min = -2;
	move->im_max = 2;
	move->coef = 1;
	move->ud = 0;
	move->lr = 0;
	move->change = 0xA0F00F;
	move->i = 0;
	move->c.r = 0.0;
	move->c.i = -0.8;
}

void	ft_error(void)
{
	write(1, "only available parameters : mandelbrot (m) julia (j) [Cr & Ci]\
	\n", 64);
	exit(0);
}

int	main(int ac, char **av)
{
	t_mlx	move;

	ft_ini(&move);
	if (ac == 1 || ((ac == 4 && av[1][0] == 'm')
		|| (av[1][0] != 'm' && av[1][0] != 'j'))
		|| av[1][1] != '\0' || (ac != 2 && ac != 4))
		ft_error();
	else if (av[1][0] == 'j' && ac == 4)
	{
		move.c.r = ft_atof(av[2]);
		move.c.i = ft_atof(av[3]);
	}
	move.f = av[1][0];
	move.mlx_ptr = mlx_init();
	move.win_ptr = mlx_new_window(move.mlx_ptr, 800, 800, "fractol");
	move.img_ptr = mlx_new_image(move.mlx_ptr, 800, 800);
	move.img_str = (int *)mlx_get_data_addr(move.img_ptr,
			&(move.bpp), &(move.l), &(move.endian));
	ft_draw(&move, move.f);
	mlx_hook(move.win_ptr, 4, 0, mouse_press, &move);
	mlx_hook(move.win_ptr, 17, 0, ft_close, (void *)&move);
	mlx_hook(move.win_ptr, 2, 0, keypress, (void *)&move);
	mlx_loop(move.mlx_ptr);
}
