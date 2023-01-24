/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oheinzel <oheinzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 09:57:25 by oheinzel          #+#    #+#             */
/*   Updated: 2023/01/24 17:21:43 by oheinzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	color_pixel(t_param *p, int x, int y, int i)
{
	uint32_t	c;
	const int	r[16] = {66, 25, 9, 4, 0, 12, 24, 57, 134,
		211, 241, 248, 255, 204, 153, 106};
	const int	g[16] = {30, 7, 1, 4, 7, 44, 82, 125,
		181, 236, 233, 201, 170, 128, 87, 52};
	const int	b[16] = {15, 26, 47, 73, 100, 138, 177,
		209, 229, 248, 191, 95, 0, 0, 0, 3};

	i = i % 16;
	c = get_color(r[i], g[i], b[i]);
	c = c << p->color;
	c = (c << 8) + 255;
	mlx_put_pixel(p->img, x, y, c);
}

void	create_mandelbrot(int x, int y, void *param)
{
	double		zreal;
	double		tmp;
	double		zimag;
	int			i;
	t_param		*p;

	i = 0;
	zreal = 0;
	zimag = 0;
	p = param;
	calc_c((double)x, (double)y, p);
	while (i < (int)p->it_max && (zreal * zreal + zimag * zimag) < 4)
	{
		tmp = (zreal * zreal) - (zimag * zimag) + p->cords[0];
		zimag = zreal * zimag + zreal * zimag + p->cords[1];
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
	t_param		*p;

	i = 0;
	p = param;
	calc_c((double)x, (double)y, p);
	zreal = p->cords[0];
	zimag = p->cords[1];
	while (i < (int)p->it_max && (zreal * zreal + zimag * zimag) < 4)
	{
		tmp = (zreal * zreal) - (zimag * zimag) + p->consts[0];
		zimag = zreal * zimag + zreal * zimag + p->consts[1];
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
	t_param		*p;

	i = 0;
	p = param;
	calc_c((double)x, (double)y, p);
	zreal = p->cords[0];
	zimag = p->cords[1];
	while (i < (int)p->it_max && (zreal * zreal + zimag * zimag) < 4)
	{
		tmp = (zreal * zreal) - (zimag * zimag) + p->cords[0];
		zimag = ft_abs(zreal * zimag + zreal * zimag) + p->cords[1];
		zreal = tmp;
		i++;
	}
	if ((zreal * zreal + zimag * zimag) >= 4)
		color_pixel(p, x, y, i);
	else
		mlx_put_pixel(p->img, x, y, 255);
}

void	iterate(t_param *p)
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
