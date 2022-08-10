/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelousse <yelousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 02:07:04 by yelousse          #+#    #+#             */
/*   Updated: 2022/08/10 22:51:55 by yelousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <mlx.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>

# define W 800
# define H 800

typedef struct s_complex
{
	double			r;
	double			i;
}			t_complex;

typedef struct s_mlx
{
	int			ud;
	int			lr;
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
	int			*img_str;
	int			bpp;
	int			l;
	int			endian;
	int			mx;
	int			my;
	double		coef;
	double		re_min;
	double		re_max;
	double		im_min;
	double		im_max;
	char		f;
	int			change;
	int			i;
	int			max_it;
	t_complex	c;
}t_mlx;

void	ft_mandelbrot(int x, int y, t_mlx *move);
void	ft_julia(int x, int y, t_mlx *move);
void	ft_draw(t_mlx *move, char f);
int		mouse_move(int x, int y, t_mlx *move);

int		keypress(int keycode, t_mlx *move);
int		mouse_press(int button, int x, int y, t_mlx *move);
int		ft_close(void *param);
int		keypress_bonus(int keycode, t_mlx *move);
int		mouse_press_bonus(int button, int x, int y, t_mlx *move);
int		close_bonus(void *param);

void	ft_mandelbrot_bonus(int x, int y, t_mlx *move);
void	ft_julia_bonus(int x, int y, t_mlx *move);
void	ft_tricorn_bonus(int x, int y, t_mlx *move);
void	change_color(t_mlx *move);
void	add_iter(t_mlx *move);
void	reduce_iter(t_mlx *move);
double	ft_atof(char *str);
void	ft_error(void);

#endif