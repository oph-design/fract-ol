/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oheinzel <oheinzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 16:42:42 by oheinzel          #+#    #+#             */
/*   Updated: 2022/10/19 13:27:05 by oheinzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t				i;
	const unsigned char	*a;
	const unsigned char	*b;

	i = 0;
	a = (const unsigned char *) s1;
	b = (const unsigned char *) s2;
	while (a[i] && b[i] && i < n)
	{
		if (a[i] != b[i])
			return (a[i] - b[i]);
		++i;
	}
	if (i != n)
		return (a[i] - b[i]);
	return (0);
}
