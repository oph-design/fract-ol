/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oheinzel <oheinzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 09:57:25 by oheinzel          #+#    #+#             */
/*   Updated: 2023/01/24 11:05:55 by oheinzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	create_mandelbrot(int x, int y, void *param)
{
	double		zreal;
	double		tmp;
	double		zimag;
	int			i;
	t_params	*p;

	i = 0;
	zreal = 0;
	zimag = 0;
	p = param;
	calc_c((double)x, (double)y, p);
	while (i < (int)p->it_max && (zreal * zreal + zimag * zimag) < 4)
	{
		tmp = (zreal * zreal) - (zimag * zimag) + p->creal;
		zimag = zreal * zimag + zreal * zimag + p->cimag;
		zreal = tmp;
		i++;
	}
	if ((zreal * zreal + zimag * zimag) >= 4)
		color_pixel(p, x, y, i);
	else
		mlx_put_pixel(p->img, x, y, 255);
}

void	create_julia(int x, int y, void *param)
{
	double		zreal;
	double		tmp;
	double		zimag;
	int			i;
	t_params	*p;

	i = 0;
	p = param;
	calc_c((double)x, (double)y, p);
	zreal = p->creal;
	zimag = p->cimag;
	while (i < (int)p->it_max && (zreal * zreal + zimag * zimag) < 4)
	{
		tmp = (zreal * zreal) - (zimag * zimag) - 0.8;
		zimag = zreal * zimag + zreal * zimag + 0.2;
		zreal = tmp;
		i++;
	}
	if ((zreal * zreal + zimag * zimag) >= 4)
		color_pixel(p, x, y, i);
	else
		mlx_put_pixel(p->img, x, y, 255);
}

void	create_bship(int x, int y, void *param)
{
	double		zreal;
	double		tmp;
	double		zimag;
	int			i;
	t_params	*p;

	i = 0;
	p = param;
	calc_c((double)x, (double)y, p);
	zreal = p->creal;
	zimag = p->cimag;
	while (i < (int)p->it_max && (zreal * zreal + zimag * zimag) < 4)
	{
		tmp = (zreal * zreal) - (zimag * zimag) + p->creal;
		zimag = ft_abs(zreal * zimag + zreal * zimag) + p->cimag;
		zreal = tmp;
		i++;
	}
	if ((zreal * zreal + zimag * zimag) >= 4)
		color_pixel(p, x, y, i);
	else
		mlx_put_pixel(p->img, x, y, 255);
}

void	iterate(t_params *p)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (x < WIDTH)
	{
		while (y < HEIGHT)
			p->fr(x, y++, p);
		y = 0;
		x++;
	}
	mlx_image_to_window(p->mlx, p->img, 0, 0);
}
