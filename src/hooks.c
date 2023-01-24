/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oheinzel <oheinzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 08:02:35 by oheinzel          #+#    #+#             */
/*   Updated: 2023/01/24 18:43:27 by oheinzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	color_shift(t_param *p, int factor)
{
	p->color = p->color + 1 * factor;
	if (p->color > 16 && factor > 0)
			p->color = 0;
	if (p->color < 0 && factor < 0)
			p->color = 16;
}

void	loop_hook(void *param)
{
	t_param	*p;

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
	if (mlx_is_key_down(p->mlx, MLX_KEY_ESCAPE))
		ft_exit(p);
	iterate(p);
}

void	my_scrollhook(double xdelta, double ydelta, void *param)
{
	t_param	*p;
	int32_t	x;
	int32_t	y;
	double	prevx;
	double	prevy;

	(void) xdelta;
	p = param;
	mlx_get_mouse_pos(p->mlx, &x, &y);
	calc_c(x, y, p);
	prevx = p->cords[0];
	prevy = p->cords[1];
	if (ydelta > 0)
		p->zoom = p->zoom * 0.80;
	else if (ydelta < 0)
		p->zoom = p->zoom / 0.80;
	calc_c(x, y, p);
	p->midr += prevx - p->cords[0];
	p->midi += prevy - p->cords[1];
	iterate(p);
}
