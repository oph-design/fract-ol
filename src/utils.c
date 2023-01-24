/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oheinzel <oheinzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 10:21:47 by oheinzel          #+#    #+#             */
/*   Updated: 2023/01/24 11:06:00 by oheinzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

double	ft_abs(double x)
{
	if (x < 0)
		x *= -1;
	return (x);
}

void	calc_c(double x, double y, t_params *p)
{
	double	z;

	z = p->zoom;
	p->creal = x / WIDTH * p->ranger * z + p->midr - p->ranger * z / 2;
	p->cimag = y / HEIGHT * p->rangei * z + p->midi - p->rangei * z / 2;
}

void	color_shift(t_params *p, int factor)
{
	p->color = p->color + 8 * factor;
	if (p->color > 16 && factor > 0)
			p->color = 0;
	if (p->color < 0 && factor < 0)
			p->color = 16;
}

void	color_pixel(t_params *p, int x, int y, int i)
{
	uint32_t	c;

	if (i == 0)
		i = 1;
	c = 255 / i * 10;
	c = (c << p->color << 8) + 255;
	mlx_put_pixel(p->img, x, y, c);
}
