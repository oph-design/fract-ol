/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oheinzel <oheinzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 12:59:00 by oheinzel          #+#    #+#             */
/*   Updated: 2022/11/27 16:39:13 by oheinzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static char	hex_digit(int v, char caps)
{
	if (v >= 0 && v < 10)
		return ('0' + v);
	else if (caps == 'X')
		return ('A' + v - 10);
	else
		return ('a' + v - 10);
}

static size_t	count_hex_digit(unsigned long long x)
{
	size_t	d;

	d = 0;
	if (x == 0)
		return (1);
	while (x != 0)
	{
		x /= 16;
		d++;
	}
	return (d);
}

static void	ft_printhex(unsigned long long x, char caps)
{
	if (x >= 16)
	{
		ft_printhex(x / 16, caps);
		x = x % 16;
	}
	if (x < 16)
		ft_putchar(hex_digit(x, caps));
}

size_t	ft_printx(unsigned int x, char caps)
{
	ft_printhex(x, caps);
	return (count_hex_digit(x));
}

size_t	ft_printp(unsigned long long x)
{
	ft_putstr("0x");
	ft_printhex(x, 'x');
	return (count_hex_digit(x) + 2);
}
