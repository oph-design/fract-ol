/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oheinzel <oheinzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 10:21:47 by oheinzel          #+#    #+#             */
/*   Updated: 2023/01/24 11:35:40 by oheinzel         ###   ########.fr       */
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

void	color_shift(t_params *p, int factor)
{
	p->color = p->color + 1 * factor;
	if (p->color > 16 && factor > 0)
			p->color = 0;
	if (p->color < 0 && factor < 0)
			p->color = 16;
}

void	color_pixel(t_params *p, int x, int y, int i)
{
	uint32_t	c;

	i = i % 16;
	if (i == 0)
		c = get_color(66, 30, 15);
	if (i == 1)
		c = get_color(25, 7, 26);
	if (i == 2)
		c = get_color(9, 1, 47);
	if (i == 3)
		c = get_color(4, 4, 73);
	if (i == 4)
		c = get_color(0, 7, 100);
	if (i == 5)
		c = get_color(12, 44, 138);
	if (i == 6)
		c = get_color(24, 82, 177);
	if (i == 7)
		c = get_color(57, 125, 209);
	if (i == 8)
		c = get_color(134, 181, 229);
	if (i == 9)
		c = get_color(211, 236, 248);
	if (i == 10)
		c = get_color(241, 233, 191);
	if (i == 11)
		c = get_color(248, 201, 95);
	if (i == 12)
		c = get_color(255, 170, 0);
	if (i == 13)
		c = get_color(204, 128, 0);
	if (i == 14)
		c = get_color(153, 87, 0);
	if (i == 15)
		c = get_color(106, 52, 3);
	c = c << p->color;
	c = (c << 8) + 255;
	mlx_put_pixel(p->img, x, y, c);
}

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
