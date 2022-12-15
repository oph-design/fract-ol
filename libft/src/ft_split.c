/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oheinzel <oheinzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 11:01:08 by oheinzel          #+#    #+#             */
/*   Updated: 2022/12/05 11:10:23 by oheinzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	sub_strlen(char const *str, char c)
{
	int	len;

	len = 0;
	while (str[len] && *(str + len) != c)
		len++;
	return (len);
}

static int	count_str(char const *str, char c)
{
	int	len;
	int	count;

	count = 0;
	while (*str)
	{
		while (*str && *str == c)
			str++;
		len = sub_strlen(str, c);
		str += len;
		if (len)
			count++;
	}
	return (count);
}

static char	*insert(char const *src, int len)
{
	char	*res;

	res = malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	res[len] = '\0';
	while (len--)
		res[len] = src[len];
	return (res);
}

static char	**aboard(int i, char **split)
{
	while (--i >= 0)
		free(split[i]);
	free(split);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	int		count;
	int		i;
	int		len;

	if (!s)
		return (0);
	count = count_str(s, c);
	split = malloc(sizeof(char *) * (count + 1));
	if (!split)
		return (NULL);
	i = 0;
	while (i < count)
	{
		while (*s && *s == c)
			s++;
		len = sub_strlen(s, c);
		split[i] = insert(s, len);
		if (!split[i])
			return (aboard(i, split));
		s += len;
		i++;
	}
	split[i] = 0;
	return (split);
}
