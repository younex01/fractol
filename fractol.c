/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelousse <yelousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 02:06:24 by yelousse          #+#    #+#             */
/*   Updated: 2022/07/23 19:11:55 by yelousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_draw(t_mlx *move, char *f)
{
	int i;
	int j;

	i = 0;
	while (i < H)
	{
		j = 0;
		while (j < W)
		{
            if (*f == 'm')
                ft_mandelbrot(j, i, move);
            if (*f == 'j')
			    ft_julia(j, i, move);
            // if (f == 'b')
			//     ft_burning_ship(j, i, move);
			j++;
		}
	i++;
	}
	mlx_put_image_to_window(move->mlx_ptr, move->win_ptr, move->img_ptr, 0, 0);
}

double interp(double start, double end, double interpolation)
{
    return (start + ((end - start) * interpolation));
}

void	zoom(t_mlx *move)
{
	double mouseRe = (double)move->mx / (W / (move->re_max - move->re_min)) + move->re_min;
	double mouseIm = (double)move->my / (H / (move->im_max - move->im_min)) + move->im_min;
	move->re_min = interp(mouseRe, move->re_min, move->coef);
	move->im_min = interp(mouseIm, move->im_min, move->coef);
	move->re_max = interp(mouseRe, move->re_max, move->coef);
	move->im_max = interp(mouseIm, move->im_max, move->coef);
	ft_draw(move, move->f);

}

int		mouse_press(int button, int x, int y, t_mlx *move)
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


int	main(int ac, char **av)
{
	t_mlx  move;

    (void)ac;
	move.ud = 0;
	move.lr = 0;
    move.f = *(av+(1));
	move.re_min = -2;
	move.re_max = 2;
	move.im_min = -2;
	move.im_max = 2;
	move.coef = 1;
	move.mlx_ptr = mlx_init();
	move.win_ptr = mlx_new_window(move.mlx_ptr, 800, 800, "fractol");
	move.img_ptr = mlx_new_image(move.mlx_ptr, 800, 800);
	move.img_str = (int*)mlx_get_data_addr(move.img_ptr, &(move.bpp), &(move.l), &(move.endian));
	ft_draw(&move, move.f);
	mlx_hook(move.win_ptr, 4, 0, mouse_press, &move);
	mlx_loop(move.mlx_ptr);
}