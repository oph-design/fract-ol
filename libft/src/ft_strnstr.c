/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oheinzel <oheinzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 16:42:44 by oheinzel          #+#    #+#             */
/*   Updated: 2022/10/20 07:51:28 by oheinzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!(*needle) || needle == NULL)
		return ((char *) haystack);
	while ((i < len && haystack[i]))
	{
		j = 0;
		while (needle[j] == haystack[i + j] && (i + j) < len)
		{
			j++;
			if (needle[j] == '\0')
				return ((char *) haystack + i);
		}
		i++;
	}
	return (NULL);
}
/*
char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;

	i = 0;
	if (!(*needle) || needle == NULL)
		return ((char *) haystack);
	while ((haystack[i] != '\0') && (i < len))
	{
		if ((haystack[i] == needle[0])
			&& (ft_strncmp(haystack + i, needle, ft_strlen(needle)) == 0)
			&& (i + ft_strlen(needle)) <= len)
			return (&((char *)haystack)[i]);
		i++;
	}
	return (NULL);
} */
