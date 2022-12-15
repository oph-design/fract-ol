/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oheinzel <oheinzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 16:41:56 by oheinzel          #+#    #+#             */
/*   Updated: 2022/12/06 16:26:57 by oheinzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	f;
	int	r;

	i = 0;
	f = 1;
	r = 0;
	if (str[i] == 0)
		return (0);
	while ((str[i] >= 8 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			f = -1;
		i++;
	}
	while ((47 < str[i]) && (str[i] < 58))
	{
		r = r * 10 + (str[i] - 48);
		i++;
	}
	return (f * r);
}
