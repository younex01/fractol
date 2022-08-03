/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelousse <yelousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 02:07:04 by yelousse          #+#    #+#             */
/*   Updated: 2022/08/03 15:19:09 by yelousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <math.h>

#define W 800
#define H 800
#define MAX_IT 50

typedef struct s_complex
{
	double			r;
	double			i;
}			t_complex;

typedef struct s_mouse
{
	double			Re;
	double			Im;
}			mouse;

typedef struct s_mandel
{
	double re_min;
	double re_max;
	double im_min;
	double im_max;
}			t_mandel;


typedef		struct s_mlx
{
	int		ud;
	int		lr;
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	int		*img_str;
	int		bpp;
	int		l;
	int		endian;
	int		mx;
	int		my;
	double 	coef;
	double re_min;
	double re_max;
	double im_min;
	double im_max;
	char	*f;
}t_mlx;


void ft_mandelbrot(int x, int y, t_mlx *move);
void ft_julia(int x, int y, t_mlx *move);
void ft_burningship(int x, int y, t_mlx *move);
void ft_sierpinski(int x, int y, t_mlx *move);
void ft_tricorn(int x, int y, t_mlx *move);
int		mouse_move(int x, int y, t_mlx *move);
void	ft_draw(t_mlx *move, char *f);

#endif