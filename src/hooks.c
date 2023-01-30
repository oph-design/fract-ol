/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oheinzel <oheinzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 08:02:35 by oheinzel          #+#    #+#             */
/*   Updated: 2023/01/30 15:54:08 by oheinzel         ###   ########.fr       */
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
	iterate(p);
}

void	shift_view(t_param *p, int key)
{
	if (key == 0)
		p->midi = p->midi - 0.05 * p->zoom;
	if (key == 1)
		p->midr = p->midr - 0.05 * p->zoom;
	if (key == 2)
		p->midi = p->midi + 0.05 * p->zoom;
	if (key == 3)
		p->midr = p->midr + 0.05 * p->zoom;
	if (key == 4)
		p->it_max += 1;
	if (key == 5)
		p->it_max -= 1;
	iterate(p);
}

void	loop_hook(void *param)
{
	t_param	*p;

	p = param;
	if (mlx_is_key_down(p->mlx, MLX_KEY_W))
		shift_view(p, 0);
	if (mlx_is_key_down(p->mlx, MLX_KEY_A))
		shift_view(p, 1);
	if (mlx_is_key_down(p->mlx, MLX_KEY_S))
		shift_view(p, 2);
	if (mlx_is_key_down(p->mlx, MLX_KEY_D))
		shift_view(p, 3);
	if (mlx_is_key_down(p->mlx, MLX_KEY_LEFT))
		color_shift(p, 1);
	if (mlx_is_key_down(p->mlx, MLX_KEY_RIGHT))
		color_shift(p, -1);
	if (mlx_is_key_down(p->mlx, MLX_KEY_UP))
		shift_view(p, 4);
	if (mlx_is_key_down(p->mlx, MLX_KEY_DOWN))
		shift_view(p, 5);
	if (mlx_is_key_down(p->mlx, MLX_KEY_ESCAPE))
		ft_exit(p);
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
	if (ydelta != 0)
		iterate(p);
}
