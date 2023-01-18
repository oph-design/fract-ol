/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oheinzel <oheinzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 11:25:33 by oheinzel          #+#    #+#             */
/*   Updated: 2023/01/18 18:14:37 by oheinzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../MLX42/include/MLX42/MLX42.h"
# include "../libft/src/libft.h"
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

typedef struct i_params
{
	double	midr;
	double	midi;
	double	ranger;
	double	rangei;
	double	creal;
	double	cimag;
}	t_params;

unsigned int	get_rgba_2(int r, int g, int b, int a);
int				get_b(int rgba);
int				get_g(int rgba);
int				get_r(int rgba);
int				amount(int n);

#endif
