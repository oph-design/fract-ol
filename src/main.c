/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oheinzel <oheinzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 11:23:02 by oheinzel          #+#    #+#             */
/*   Updated: 2023/01/25 10:33:25 by oheinzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	wrong_input(void)
{
	ft_putendl_fd("\033[0;31mERROR: Wrong Input entered", 2);
	ft_putendl_fd("\033[0;97mExecute with following Options:", 2);
	ft_putendl_fd("* ./fractol [fractal] [constx] [consty]", 2);
	ft_putendl_fd("* [fractal] can have the following values:", 2);
	ft_putendl_fd("* mandelbrot | burning_ship | julia", 2);
	ft_putendl_fd("* if the option is 'julia' you have to specify", 2);
	ft_putendl_fd("* [constn] with any value between 1 and 6 ", 2);
	ft_putendl_fd("* [constn]  1   2    3    4    5   6 ", 2);
	ft_putendl_fd("* [constx] -1 -0.8 -0.6 -0.4 -0.2  0", 2);
	ft_putendl_fd("* [constx]  1  0.8  0.6  0.4  0.2  0\033[0m", 2);
	exit(1);
}

t_param	*init_struct(double midr, double midi, double rngr, double rngi)
{
	t_param	*new;

	new = malloc(sizeof(t_param));
	if (new == NULL)
		return (NULL);
	new->mlx = mlx_init(WIDTH, HEIGHT, "fract-ole", true);
	if (new->mlx == NULL)
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
	new->img = mlx_new_image(new->mlx, WIDTH, HEIGHT);
	new->zoom = 1;
	new->color = 0;
	if (midr == -0.4)
		new->color = 16;
	new->it_max = 100;
	return (new);
}

t_param	*init_julia(char *argv[])
{
	t_param			*new;
	const double	x[6] = {-1, -0.8, -0.6, -0.4, -0.2, 0};
	const double	y[6] = {1, 0.8, 0.6, 0.4, 0.2, 0};

	if (ft_strlen(argv[2]) > 1 || !ft_isdigit(argv[2][0])
		|| ft_strlen(argv[3]) > 1 || !ft_isdigit(argv[2][0])
		|| ft_atoi(argv[2]) > 6 || ft_atoi(argv[3]) > 6
		|| ft_atoi(argv[2]) < 1 || ft_atoi(argv[3]) < 1)
		wrong_input();
	new = init_struct(0, 0, 4, 2.25);
	if (new == NULL)
		return (NULL);
	new->consts[0] = x[ft_atoi(argv[2]) - 1];
	new->consts[1] = y[ft_atoi(argv[3]) - 1];
	new->color = 8;
	return (new);
}

t_param	*input(int argc, char *argv[])
{
	if (argc < 2 || (!ft_strncmp(argv[1], "julia", 6) && argc != 4)
		|| (ft_strncmp(argv[1], "julia", 6) && argc != 2))
		wrong_input();
	if (ft_strncmp(argv[1], "julia", 6) && ft_strncmp(argv[1], "mandelbrot", 11)
		&& ft_strncmp(argv[1], "burning_ship", 13))
		wrong_input();
	if (!ft_strncmp(argv[1], "mandelbrot", 11))
		return (init_struct(-0.75, 0, 4, 2.25));
	if (!ft_strncmp(argv[1], "julia", 6))
		return (init_julia(argv));
	if (!ft_strncmp(argv[1], "burning_ship", 13))
		return (init_struct(-0.4, -0.6, 4.4, 2.5));
	return (NULL);
}

int	main(int argc, char *argv[])
{
	t_param	*param;

	param = input(argc, argv);
	if (param == NULL)
		return (ft_putendl_fd("fractol: failed to create mlx", 2), 1);
	mlx_set_window_limit(param->mlx, WIDTH, HEIGHT, WIDTH, HEIGHT);
	iterate(param);
	mlx_loop_hook(param->mlx, &loop_hook, param);
	mlx_scroll_hook(param->mlx, &my_scrollhook, param);
	mlx_loop(param->mlx);
	ft_exit(param);
	return (EXIT_SUCCESS);
}
