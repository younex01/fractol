/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelousse <yelousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 02:06:24 by yelousse          #+#    #+#             */
/*   Updated: 2022/08/07 02:04:27 by yelousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_draw(t_mlx *move, char *f)
{
	int	i;
	int	j;

	i = 0;
	while (i < H)
	{
		j = 0;
		while (j < W)
		{
			if (*f == 'm')
				ft_mandelbrot(j, i, move);
			if (*f == 'j')
				ft_julia_11(j, i, move);
			if (*f == 'k')
				ft_julia_22(j, i, move);
			if (*f == 'l')
				ft_julia_33(j, i, move);
			if (*f == 'h')
				ft_julia_44(j, i, move);
			j++;
		}
	i++;
	}
	mlx_put_image_to_window(move->mlx_ptr, move->win_ptr, move->img_ptr, 0, 0);
}

void	ft_ini(t_mlx *move)
{
	move->max_it = 50;
	move->ud = 0;
	move->lr = 0;
	move->re_min = -2;
	move->re_max = 2;
	move->im_min = -2;
	move->im_max = 2;
	move->coef = 1;
	move->change = 0xA0F00F;
	move->i = 0;
}

void	ft_protect(int ac)
{
	if (ac == 1 || ac > 2)
	{
		printf("only available parameters : mandelbrot "
			"(m) julia (h) (j) (k) (l) \n");
		exit(0);
	}
}

int	main(int ac, char **av)
{
	t_mlx	move;

	ft_protect(ac);
	if ((av[1][0] != 'm' && av[1][0] != 'j' && av[1][0] != 'h'
			&& av[1][0] != 'k' && av[1][0] != 'l') || av[1][1] != '\0')
	{
		printf("only available parameters : mandelbrot (m) "
			"julia (h) (j) (k) (l)\n");
		exit(0);
	}
	move.f = *(av + (1));
	ft_ini(&move);
	move.mlx_ptr = mlx_init();
	move.win_ptr = mlx_new_window(move.mlx_ptr, 800, 800, "fractol");
	move.img_ptr = mlx_new_image(move.mlx_ptr, 800, 800);
	move.img_str = (int *)mlx_get_data_addr(move.img_ptr,
			&(move.bpp), &(move.l), &(move.endian));
	ft_draw(&move, move.f);
	mlx_hook(move.win_ptr, 4, 0, mouse_press, &move);
	mlx_hook(move.win_ptr, 17, 0, close, (void *)&move);
	mlx_hook(move.win_ptr, 2, 0, keypress, (void *)&move);
	mlx_loop(move.mlx_ptr);
}
