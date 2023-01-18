/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oheinzel <oheinzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 11:23:02 by oheinzel          #+#    #+#             */
/*   Updated: 2023/01/18 18:15:47 by oheinzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

#define WIDTH 1280
#define HEIGHT 720

void	calc_c(int x, int y, t_params **p)
{
	(*p)->creal = x / WIDTH * (*p)->ranger + (*p)->midr - (*p)->ranger / 2;
	(*p)->cimag = y / HEIGHT * (*p)->rangei + (*p)->midi - (*p)->rangei / 2;
}

t_params	*init_struct(double midr, double midi, double ranger, double rangei)
{
	t_params	*new;

	new = malloc(sizeof(t_params));
	if (!new)
		return (NULL);
	new->midr = midr;
	new->midi = midi;
	new->rangei = rangei;
	new->ranger = ranger;
	new->creal = 0;
	new->cimag = 0;
	return (new);
}

int	iterate(double creal, double cimag)
{
	double	zreal;
	double	zimag;
	int		i;

	zreal = 0;
	zimag = 0;
	i = 0;
	while (i < 100 && (amount(zreal) + amount(zimag)) < 2)
	{
		zreal = zreal * zreal + zimag * zimag + creal;
		zimag = 2 * zreal * zimag + cimag;
		i++;
	}
	return (amount(zreal) + amount(zimag));
}

void	create_mandelbrot(mlx_image_t *img, t_params *p)
{
	int	x;
	int	y;
	int	res;

	x = 0;
	y = 0;
	res = 0;
	while (x < WIDTH)
	{
		while (y < HEIGHT)
		{
			calc_c(x, y, &p);
			res = iterate(p->creal, p->cimag);
			if (res > 2)
				mlx_put_pixel(img, x, y, 0xFFFFFFFF);
			else
				mlx_put_pixel(img, x, y, 0x00000000);
			y++;
		}
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
	params = init_struct(-0.75, 0, 3.5, 2);
	img = mlx_new_image(mlx, WIDTH, HEIGHT);
	create_mandelbrot(img, params);
	mlx_image_to_window(mlx, img, 0, 0);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
