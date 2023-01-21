/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oheinzel <oheinzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 08:02:35 by oheinzel          #+#    #+#             */
/*   Updated: 2023/01/21 17:25:15 by oheinzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	color_shift(t_params *p, int factor)
{
	p->color = p->color + 8 * factor;
	if (p->color > 16 && factor > 0)
			p->color = 0;
	if (p->color < 0 && factor < 0)
			p->color = 16;
}

void	my_keyhook(mlx_key_data_t keydata, void *param)
{
	t_params	*p;

	p = param;
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		p->midi = p->midi - 0.05 * p->zoom;
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
		p->midr = p->midr - 0.05 * p->zoom;
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
		p->midi = p->midi + 0.05 * p->zoom;
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
		p->midr = p->midr + 0.05 * p->zoom;
	if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS)
		color_shift(p, 1);
	if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS)
		color_shift(p, -1);
	if (keydata.key == MLX_KEY_UP && keydata.action == MLX_PRESS)
		p->it_max += 10;
	if (keydata.key == MLX_KEY_DOWN && p->it_max > 0
		&& keydata.action == MLX_PRESS)
		p->it_max -= 10;
	iterate(p);
}

void	my_scrollhook(double xdelta, double ydelta, void *param)
{
	t_params	*p;
	int32_t		x;
	int32_t		y;

	(void) xdelta;
	p = param;
	mlx_get_mouse_pos(p->mlx, &x, &y);
	if (ydelta > 0)
	{
		p->ranger = p->ranger * 0.95;
		p->rangei = p->rangei * 0.95;
		p->zoom = p->zoom * 0.95;
	}
	else if (ydelta < 0)
	{
		p->ranger = p->ranger / 0.95;
		p->rangei = p->rangei / 0.95;
		p->zoom = p->zoom / 0.95;
	}
	iterate(p);
}
