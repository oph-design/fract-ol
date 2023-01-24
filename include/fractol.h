/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oheinzel <oheinzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 11:25:33 by oheinzel          #+#    #+#             */
/*   Updated: 2023/01/24 18:43:14 by oheinzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../MLX42/include/MLX42/MLX42.h"
# include "../libft/src/libft.h"
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

# define WIDTH 1920
# define HEIGHT 1080

typedef struct s_param
{
	mlx_t			*mlx;
	mlx_image_t		*img;
	double			midr;
	double			midi;
	double			ranger;
	double			rangei;
	double			cords[2];
	double			consts[2];
	double			zoom;
	int				color;
	int				it_max;
	void			(*fr)(int x, int y, void *p);
}					t_param;

t_param		*init_struct(double midr, double midi, double rngr, double rngi);
void		my_scrollhook(double xdelta, double ydelta, void *param);
void		create_mandelbrot(int x, int y, void *param);
void		create_julia(int x, int y, void *param);
void		create_bship(int x, int y, void *param);
void		calc_c(double x, double y, t_param *p);
void		color_pixel(t_param *p, int x, int y, int i);
void		color_shift(t_param *p, int factor);
void		loop_hook(void *param);
void		iterate(t_param *p);
void		ft_exit(t_param *p);
double		ft_abs(double x);
uint32_t	get_color(int red, int green, int blue);

#endif
