/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelousse <yelousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 23:44:45 by yelousse          #+#    #+#             */
/*   Updated: 2022/08/10 21:29:27 by yelousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	ft_do_the_work(char *str, int i, int sign, double value)
{
	int		j;
	double	dec;

	dec = 1;
	j = 0;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			value = value * 10 + str[i] - '0';
			if (j)
				dec *= 10;
		}
		else if (str[i] == '.')
			j = 1;
		else
			ft_error();
		i++;
	}
	return ((value / dec) * sign);
}

double	ft_atof(char *str)
{
	int		i;
	int		sign;
	double	value;

	value = 0;
	i = 0;
	sign = 1;
	while (str[i] == ' ')
		i++;
	if (str[i] == '-')
		sign *= -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	value = ft_do_the_work(str, i, sign, value);
	return (value);
}
