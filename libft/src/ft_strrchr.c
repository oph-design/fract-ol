/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oheinzel <oheinzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 16:42:47 by oheinzel          #+#    #+#             */
/*   Updated: 2022/10/19 15:57:24 by oheinzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int					i;
	const unsigned char	*a;
	unsigned char		b;

	i = ft_strlen(s);
	a = (const unsigned char *) s;
	b = (unsigned char) c;
	while (i >= 0)
	{
		if (a[i] == b)
			return (&((char *)a)[i]);
		i--;
	}
	return (NULL);
}
