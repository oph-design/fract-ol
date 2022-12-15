/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oheinzel <oheinzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 16:42:29 by oheinzel          #+#    #+#             */
/*   Updated: 2022/10/20 12:57:43 by oheinzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	int					i;
	const unsigned char	*a;
	unsigned char		b;

	i = 0;
	a = (const unsigned char *) s;
	b = (unsigned char) c;
	while (a[i])
	{
		if (a[i] == b)
			return (&((char *)a)[i]);
		i++;
	}
	if (a[i] == b)
		return (&((char *)a)[i]);
	return (0);
}
