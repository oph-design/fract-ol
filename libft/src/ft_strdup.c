/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oheinzel <oheinzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 09:22:39 by oheinzel          #+#    #+#             */
/*   Updated: 2022/11/27 16:47:33 by oheinzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *s1)
{
	size_t	i;
	size_t	len;
	char	*cpy;

	i = 0;
	len = ft_strlen(s1);
	cpy = malloc((len + 1) * sizeof(char));
	if (!cpy)
		return (NULL);
	while (i <= len)
	{
		cpy[i] = s1[i];
		i++;
	}
	return (cpy);
}
