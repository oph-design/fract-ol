/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oheinzel <oheinzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 08:02:35 by oheinzel          #+#    #+#             */
/*   Updated: 2023/01/24 11:05:34 by oheinzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	loop_hook(void *param)
{
	t_params	*p;

	p = param;
	if (mlx_is_key_down(p->mlx, MLX_KEY_W))
		p->midi = p->midi - 0.05 * p->zoom;
	if (mlx_is_key_down(p->mlx, MLX_KEY_A))
		p->midr = p->midr - 0.05 * p->zoom;
	if (mlx_is_key_down(p->mlx, MLX_KEY_S))
		p->midi = p->midi + 0.05 * p->zoom;
	if (mlx_is_key_down(p->mlx, MLX_KEY_D))
		p->midr = p->midr + 0.05 * p->zoom;
	if (mlx_is_key_down(p->mlx, MLX_KEY_LEFT))
		color_shift(p, 1);
	if (mlx_is_key_down(p->mlx, MLX_KEY_RIGHT))
		color_shift(p, -1);
	if (mlx_is_key_down(p->mlx, MLX_KEY_UP))
		p->it_max += 1;
	if (mlx_is_key_down(p->mlx, MLX_KEY_DOWN))
		p->it_max -= 1;
	iterate(p);
}

void	my_scrollhook(double xdelta, double ydelta, void *param)
{
	t_params	*p;
	int32_t		x;
	int32_t		y;
	double		prevx;
	double		prevy;

	(void) xdelta;
	p = param;
	mlx_get_mouse_pos(p->mlx, &x, &y);
	calc_c(x, y, p);
	prevx = p->creal;
	prevy = p->cimag;
	if (ydelta > 0)
		p->zoom = p->zoom * 0.95;
	else if (ydelta < 0)
		p->zoom = p->zoom / 0.95;
	calc_c(x, y, p);
	p->midr += prevx - p->creal;
	p->midi += prevy - p->cimag;
	iterate(p);
}
