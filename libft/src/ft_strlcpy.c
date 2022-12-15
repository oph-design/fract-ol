/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oheinzel <oheinzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 16:42:35 by oheinzel          #+#    #+#             */
/*   Updated: 2022/10/19 11:21:58 by oheinzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	char	*s;

	s = (char *)src;
	i = 0;
	if (dstsize == 0)
		return (ft_strlen(src));
	while (s[i] && i < dstsize - 1)
	{
		dst[i] = s[i];
		i++;
	}
	dst[i] = 0;
	return (ft_strlen(src));
}
