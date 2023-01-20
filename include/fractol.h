/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oheinzel <oheinzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 11:25:33 by oheinzel          #+#    #+#             */
/*   Updated: 2023/01/20 15:24:26 by oheinzel         ###   ########.fr       */
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

typedef struct i_params
{
	mlx_t		*mlx;
	mlx_image_t	*img;
	double		midr;
	double		midi;
	double		ranger;
	double		rangei;
	double		creal;
	double		cimag;
	int			color;
	int			it_max;
}				t_params;

t_params	*init_struct(double midr, double midi, double rngr, double rngi);
void		calc_c(double x, double y, t_params **p);
void		my_keyhook(mlx_key_data_t keydata, void *param);
void		iterate(t_params *p);
void		my_scrollhook(double xdelta, double ydelta, void *param);

#endif
