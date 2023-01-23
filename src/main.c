/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oheinzel <oheinzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 11:23:02 by oheinzel          #+#    #+#             */
/*   Updated: 2023/01/23 16:30:18 by oheinzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"
#include <stdio.h>

void	iterate(t_params *p)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (x < WIDTH)
	{
		while (y < HEIGHT)
			p->fr(x, y++, p);
		y = 0;
		x++;
	}
	mlx_image_to_window(p->mlx, p->img, 0, 0);
}

int	main(int argc, char *argv[])
{
	t_params	*params;

	if (!ft_strncmp(argv[argc - 1], "julia", 5))
		params = init_struct(0, 'j', 4, 2.25);
	else if (!ft_strncmp(argv[argc - 1], "bship", 5))
		params = init_struct(0, 'b', 4, 2.25);
	else
		params = init_struct(-0.75, 'm', 4, 2.25);
	mlx_set_window_limit(params->mlx, WIDTH, HEIGHT, WIDTH, HEIGHT);
	iterate(params);
	mlx_loop_hook(params->mlx, &loop_hook, params);
	mlx_scroll_hook(params->mlx, &my_scrollhook, params);
	mlx_loop(params->mlx);
	mlx_terminate(params->mlx);
	free(params);
	return (EXIT_SUCCESS);
}
