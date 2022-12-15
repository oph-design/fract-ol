/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oheinzel <oheinzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 20:28:41 by oheinzel          #+#    #+#             */
/*   Updated: 2022/11/27 16:39:04 by oheinzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static size_t	check(va_list ptr, char c)
{
	size_t	count;

	count = 0;
	if (c == 'c')
		count = ft_putchar(va_arg(ptr, int));
	if (c == '%')
		count = ft_putchar('%');
	if (c == 's')
		count = ft_putstr(va_arg(ptr, char *));
	if (c == 'i' || c == 'd')
		count = ft_putnbr(va_arg(ptr, int));
	if (c == 'u')
		count = ft_putunbr(va_arg(ptr, unsigned int));
	if (c == 'p')
		count = ft_printp(va_arg(ptr, unsigned long long));
	if (c == 'x' || c == 'X')
		count = ft_printx(va_arg(ptr, unsigned int), c);
	return (count);
}

int	ft_printf(const char *s, ...)
{
	va_list	ptr;
	size_t	count;
	size_t	i;

	i = 0;
	count = 0;
	va_start(ptr, s);
	while (s[i])
	{
		if (s[i] == '%')
			count += check(ptr, s[++i]);
		else
			count += ft_putchar(s[i]);
		i++;
	}
	va_end(ptr);
	return (count);
}
