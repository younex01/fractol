/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelousse <yelousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 02:06:24 by yelousse          #+#    #+#             */
/*   Updated: 2022/08/03 16:33:31 by yelousse         ###   ########.fr       */
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
            if (*f == 'b')
			    ft_burningship(j, i, move);
		    if (*f == 's')
			    ft_sierpinski(j, i, move);
			if (*f == 't')	
				ft_tricorn(j, i, move);
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
	double mouseRe = (((double)move->mx + move->lr)/ (W / (move->re_max - move->re_min)) + move->re_min);
	double mouseIm = (((double)move->my + move->ud)/ (H / (move->im_max - move->im_min)) + move->im_min );
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


int		keypress(int keycode, t_mlx *move)
{
	if (keycode == 53 && move)
	{
		//system("clear");
		exit(0);
	}
	if (keycode == 123)
		move->lr = move->lr - 10;
	if (keycode == 124)
		move->lr = move->lr + 10;
	if (keycode == 125)
		move->ud = move->ud + 10;
	if (keycode == 126)
		move->ud = move->ud - 10;
	ft_draw(move, move->f);
	return (0);
}

int close(void *param)
{
	(void)param;
	exit(0);
	return (0);
}

int	main(int ac, char **av)
{
	t_mlx  move;

	if (ac == 1 || ac > 2)
	{
		printf("only available parameters : (m) (j) (b)\n");
		exit(0);
	}
	if ((av[1][0] != 'm' && av[1][0] != 'j' && av[1][0] != 'b' && av[1][0] != 't' )|| av[1][1] != '\0')
	{
		printf("only available parameters : (m) (j) (b)\n");
		exit(0);
	}
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
	mlx_hook(move.win_ptr, 6, 0, mouse_move, &move);
	mlx_hook(move.win_ptr, 17, 0, close, (void *)&move);
	mlx_hook(move.win_ptr, 2, 0, keypress, (void *)&move);
	mlx_loop(move.mlx_ptr);
}