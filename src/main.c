/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oheinzel <oheinzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 11:23:02 by oheinzel          #+#    #+#             */
/*   Updated: 2023/01/20 11:05:02 by oheinzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"
#include <stdio.h>

void	color_pixel(t_params *p, int x, int y, int i)
{
	uint32_t	c;

	c = 255 / i * 10;
	c = (c << p->color << 8) + 255;
	mlx_put_pixel(p->img, x, y, c);
}

void	create_mandelbrot(int x, int y, t_params *p)
{
	double	zreal;
	double	tmp;
	double	zimag;
	int		i;

	i = 0;
	zreal = 0;
	zimag = 0;
	calc_c((double)x, (double)y, &p);
	while (i < 100 && (zreal * zreal + zimag * zimag) < 4)
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

void	iterate(t_params *p)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (x < WIDTH)
	{
		while (y < HEIGHT)
			create_mandelbrot(x, y++, p);
		y = 0;
		x++;
	}
	mlx_image_to_window(p->mlx, p->img, 0, 0);
}

int	main(void)
{
	t_params	*params;

	params = init_struct(-0.75, 0, 4, 2.35);
	iterate(params);
	mlx_key_hook(params->mlx, &my_keyhook, params);
	mlx_loop(params->mlx);
	mlx_terminate(params->mlx);
	free(params);
	return (EXIT_SUCCESS);
}
