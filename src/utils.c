/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oheinzel <oheinzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 10:21:47 by oheinzel          #+#    #+#             */
/*   Updated: 2023/01/24 15:33:32 by oheinzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

uint32_t	get_color(int red, int green, int blue)
{
	uint32_t	res;

	res = red;
	res = (res << 8) + green;
	res = (res << 8) + blue;
	return (res);
}

double	ft_abs(double x)
{
	if (x < 0)
		x *= -1;
	return (x);
}

void	calc_c(double x, double y, t_param *p)
{
	double	z;

	z = p->zoom;
	p->cords[0] = x / WIDTH * p->ranger * z + p->midr - p->ranger * z / 2;
	p->cords[1] = y / HEIGHT * p->rangei * z + p->midi - p->rangei * z / 2;
}

void	ft_exit(t_param *p)
{
	mlx_t	*mlx;

	mlx = p->mlx;
	free(p);
	mlx_terminate(mlx);
	exit(0);
}
