/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oheinzel <oheinzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 11:23:02 by oheinzel          #+#    #+#             */
/*   Updated: 2023/01/24 11:08:04 by oheinzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"
#include <stdio.h>

t_params	*init_struct(double midr, double midi, double rngr, double rngi)
{
	t_params	*new;

	new = malloc(sizeof(t_params));
	if (!new)
		return (NULL);
	if (midr == -0.75)
		new->fr = &create_mandelbrot;
	if (midr == 0)
		new->fr = &create_julia;
	if (midr == -0.4)
		new->fr = &create_bship;
	new->midr = midr;
	new->midi = midi;
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

void	wrong_input(void)
{
	ft_putendl_fd("\033[0;31mERROR: Wrong Input entered\033[0m", 2);
	ft_putendl_fd("\033[0;97mExecute with following Options:", 2);
	ft_putendl_fd("\033[0;97m* ./fract-ol [fractal] [constx] [consty]", 2);
	ft_putendl_fd("\033[0;97m* [fractal] can have the following values:", 2);
	ft_putendl_fd("\033[0;97m* mandelbrot | burning_ship | julia", 2);
	ft_putendl_fd("* if the option is 'julia' you have to specify [constn]", 2);
	exit(1);
}

t_params	*input(int argc, char *argv[])
{
	if (argc < 2 || (!ft_strncmp(argv[1], "julia", 5) && argc != 4))
		wrong_input();
	if (ft_strncmp(argv[1], "julia", 5) && ft_strncmp(argv[1], "mandelbrot", 10)
		&& ft_strncmp(argv[1], "burning_ship", 12))
		wrong_input();
	if (!ft_strncmp(argv[1], "mandelbrot", 10))
		return (init_struct(-0.75, 0, 4, 2.25));
	if (!ft_strncmp(argv[1], "julia", 5))
		return (init_struct(0, 0, 4, 2.25));
	if (!ft_strncmp(argv[argc - 1], "burning_ship", 12))
		return (init_struct(-0.4, -0.6, 5, 2.5));
	return (NULL);
}

int	main(int argc, char *argv[])
{
	t_params	*params;

	params = input(argc, argv);
	if (params == NULL)
		return (ft_putendl_fd("\033[0;31mERROR: failed to create mlx", 2), 1);
	mlx_set_window_limit(params->mlx, WIDTH, HEIGHT, WIDTH, HEIGHT);
	iterate(params);
	mlx_loop_hook(params->mlx, &loop_hook, params);
	mlx_scroll_hook(params->mlx, &my_scrollhook, params);
	mlx_loop(params->mlx);
	free(params);
	mlx_terminate(params->mlx);
	return (EXIT_SUCCESS);
}
