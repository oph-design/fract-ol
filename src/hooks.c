/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oheinzel <oheinzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 08:02:35 by oheinzel          #+#    #+#             */
/*   Updated: 2023/01/20 15:46:42 by oheinzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	my_keyhook(mlx_key_data_t keydata, void *param)
{
	t_params	*p;

	p = param;
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		p->midi = p->midi - 0.05;
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
		p->midr = p->midr - 0.05;
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
		p->midi = p->midi + 0.05;
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
		p->midr = p->midr + 0.05;
	if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS)
	{
		p->color = p->color + 8;
		if (p->color > 16)
			p->color = 0;
	}
	if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS)
	{
		p->color = p->color - 8;
		if (p->color < 0)
			p->color = 16;
	}
	iterate(p);
}

void	my_scrollhook(double xdelta, double ydelta, void *param)
{
	t_params		*p;
	static double	iteration;

	(void) xdelta;
	p = param;
	if (ydelta > 0)
	{
		p->ranger = p->ranger - 0.05;
		p->rangei = p->rangei - 0.031625;
		iteration = iteration + 0.1;
		p->it_max = p->it_max + iteration;
	}
	else if (ydelta < 0)
	{
		p->ranger = p->ranger + 0.05;
		p->rangei = p->rangei + 0.031625;
		iteration = iteration - 0.1;
		p->it_max = p->it_max - iteration;
	}
	iterate(p);
}