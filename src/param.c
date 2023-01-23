/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oheinzel <oheinzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 13:43:23 by oheinzel          #+#    #+#             */
/*   Updated: 2023/01/23 16:28:35 by oheinzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	calc_c(double x, double y, t_params *p)
{
	double	z;

	z = p->zoom;
	p->creal = x / WIDTH * p->ranger * z + p->midr - p->ranger * z / 2;
	p->cimag = y / HEIGHT * p->rangei * z + p->midi - p->rangei * z / 2;
}

t_params	*init_struct(double midr, char id, double rngr, double rngi)
{
	t_params	*new;

	new = malloc(sizeof(t_params));
	if (!new)
		return (NULL);
	new->fr = &create_mandelbrot;
	if (id == 'j')
		new->fr = &create_julia;
	if (id == 'b')
		new->fr = &create_bship;
	new->midr = midr;
	new->midi = 0;
	new->rangei = rngi;
	new->ranger = rngr;
	new->creal = 0;
	new->cimag = 0;
	new->mlx = mlx_init(WIDTH, HEIGHT, "fract-ol", true);
	new->img = mlx_new_image(new->mlx, WIDTH, HEIGHT);
	new->zoom = 1;
	new->color = 0;
	new->it_max = 100;
	return (new);
}
