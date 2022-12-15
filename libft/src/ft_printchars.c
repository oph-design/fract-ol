/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printchars.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oheinzel <oheinzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 14:37:50 by oheinzel          #+#    #+#             */
/*   Updated: 2022/11/27 16:39:49 by oheinzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

size_t	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

size_t	ft_putstr(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (ft_putstr("(null)"));
	while (s[i])
		i = i + ft_putchar(s[i]);
	return (i);
}

size_t	ft_putnbr(int x)
{
	char	*tmp;
	size_t	res;

	tmp = ft_itoa(x);
	res = ft_putstr(tmp);
	free(tmp);
	return (res);
}

static size_t	count_digits(unsigned int x)
{
	size_t	count;

	count = 0;
	if (x == 0)
		return (1);
	while (x != 0)
	{
		x /= 10;
		count++;
	}
	return (count);
}

size_t	ft_putunbr(unsigned int x)
{
	size_t	count;

	count = count_digits(x);
	if (x >= 10)
	{
		ft_putunbr(x / 10);
		x = x % 10;
	}
	if (x < 10)
		ft_putchar(x + 48);
	return (count);
}
