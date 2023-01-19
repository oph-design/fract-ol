/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oheinzel <oheinzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 11:23:02 by oheinzel          #+#    #+#             */
/*   Updated: 2023/01/19 17:19:59 by oheinzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"
#include <stdio.h>

void	color_pixel(mlx_image_t *img, int x, int y, int i)
{
	uint32_t	a;
	double		q;

	q = (double)i / 10;
	a = 255 / q;
	a = a << 8;
	a = a + 255;
	mlx_put_pixel(img, x, y, a);
}

void	iterate(int x, int y, t_params *p, mlx_image_t *img)
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
		color_pixel(img, x, y, i);
	else
		mlx_put_pixel(img, x, y, 0x000000FF);
}

void	create_mandelbrot(mlx_image_t *img, t_params *p)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (x < WIDTH)
	{
		while (y < HEIGHT)
			iterate(x, y++, p, img);
		y = 0;
		x++;
	}
}

int	main(void)
{
	mlx_t		*mlx;
	mlx_image_t	*img;
	t_params	*params;

	mlx = mlx_init(WIDTH, HEIGHT, "fract-ol", true);
	if (!mlx)
		exit(1);
	params = init_struct(-0.5, 0, 4, 2.35);
	img = mlx_new_image(mlx, WIDTH, HEIGHT);
	create_mandelbrot(img, params);
	free(params);
	mlx_image_to_window(mlx, img, 0, 0);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
