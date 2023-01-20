/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oheinzel <oheinzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 08:02:35 by oheinzel          #+#    #+#             */
/*   Updated: 2023/01/20 11:05:24 by oheinzel         ###   ########.fr       */
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
