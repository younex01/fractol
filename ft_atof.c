/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelousse <yelousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 23:44:45 by yelousse          #+#    #+#             */
/*   Updated: 2022/08/10 01:10:26 by yelousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	ft_atof(char *str)
{
    int i;
    int j;
    int sign;
    double  value;
    double  dec;

    value = 0;
    i = 0;
    j = 0;
    sign = 1;
    dec = 1;
    while(str[i] == ' ')
        i++;
    if (str[i] == '-')
        sign *= -1; 
    if (str[i] == '+' || str[i] == '-')
        i++;
    while(str[i])
    {
        if(str[i] >= '0' && str[i] <= '9')
        {
            value = value * 10 + str[i] - '0';
            if(j)
                dec *=10;
        }
        else if(str[i] == '.')
            j = 1;
        else
            break;
        i++;
    }
    return ((value / dec) * sign);
}
