/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oheinzel <oheinzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 11:01:40 by oheinzel          #+#    #+#             */
/*   Updated: 2022/10/20 10:57:36 by oheinzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	loopbreak(char const s, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (s == set[i])
			return (1);
		i++;
	}
	return (0);
}

static int	check_start(char const *s, char const *set)
{
	int	count;

	count = 0;
	while (s[count] && loopbreak(s[count], set) == 1)
		count++;
	return (count);
}

static int	check_end(char const *s, char const *set)
{
	int	count;
	int	i;

	count = 0;
	i = ft_strlen(s) - 1;
	while ((i > 0) && loopbreak(s[i], set) == 1)
	{
		count++;
		i--;
	}
	return (count);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	size_t	len;
	char	*res;
	size_t	i;

	if (!s1 || !set)
		return (NULL);
	start = check_start(s1, set);
	end = check_end(s1, set);
	len = 1;
	if ((int)ft_strlen(s1) - start - end > 0)
		len = ft_strlen(s1) - start - end;
	res = malloc((len + 1) * sizeof(char));
	if (!res)
		return (NULL);
	i = 0;
	while (s1[start] && (i < len))
	{
		res[i] = s1[start];
		i++;
		start++;
	}
	res[i] = '\0';
	return (res);
}
