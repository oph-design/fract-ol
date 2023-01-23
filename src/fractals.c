/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oheinzel <oheinzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 09:57:25 by oheinzel          #+#    #+#             */
/*   Updated: 2023/01/23 16:29:38 by oheinzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	color_pixel(t_params *p, int x, int y, int i)
{
	uint32_t	c;

	if (i == 0)
		i = 1;
	c = 255 / i * 10;
	c = (c << p->color << 8) + 255;
	mlx_put_pixel(p->img, x, y, c);
}

void	create_mandelbrot(int x, int y, void *param)
{
	double	zreal;
	double	tmp;
	double	zimag;
	int		i;
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

// void	create_julia(int x, int y, t_params *p)
// {
// 	double	zreal;
// 	double	tmp;
// 	double	zimag;
// 	int		i;

// 	i = 0;
// 	calc_c((double)x, (double)y, p);
// 	zreal = p->creal;
// 	zimag = p->cimag;
// 	while (i < (int)p->it_max && (zreal * zreal + zimag * zimag) < 4)
// 	{
// 		tmp = (zreal * zreal) + (zimag * zimag) - 0.8;
// 		zimag = zreal * zimag + zreal * zimag + 0.2;
// 		zreal = tmp;
// 		i++;
// 	}
// 	if (i < p->it_max)
// 		color_pixel(p, x, y, i);
// 	else
// 		mlx_put_pixel(p->img, x, y, 255);
// }

void	create_julia(int x, int y, void *param)
{
	double	zreal;
	double	tmp;
	double	zimag;
	int		i;
	t_params *p;

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
	double	zreal;
	double	tmp;
	double	zimag;
	int		i;
	t_params *p;

	i = 0;
	p = param;
	calc_c((double)x, (double)y, p);
	zreal = p->creal;
	zimag = p->cimag;
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
