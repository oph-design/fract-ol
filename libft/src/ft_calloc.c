/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oheinzel <oheinzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 09:12:41 by oheinzel          #+#    #+#             */
/*   Updated: 2022/10/19 14:55:29 by oheinzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	size_t	amount;

	amount = count * size;
	if (count && (amount) / count != size)
		return (NULL);
	ptr = malloc(amount);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, amount);
	return (ptr);
}
