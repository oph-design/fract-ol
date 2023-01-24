/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oheinzel <oheinzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 12:34:01 by oheinzel          #+#    #+#             */
/*   Updated: 2023/01/05 14:18:01 by oheinzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*new_line(char *line)
{
	int		i;
	int		j;
	char	*new;

	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	if (!line[i])
		return (free(line), NULL);
	new = malloc(sizeof(char) * (ft_strlen(line) - i + 1));
	if (!line)
		return (NULL);
	i++;
	j = 0;
	while (line[i])
		new[j++] = line[i++];
	new[j] = '\0';
	free(line);
	return (new);
}

static char	*build_res(char *line)
{
	char	*res;
	size_t	len;
	size_t	i;

	i = 0;
	len = 0;
	if (line == NULL)
		return (NULL);
	while (line[len] != '\n' && line[len])
		len++;
	res = malloc((len + 2) * sizeof(char));
	if (!res)
		return (NULL);
	while (line[i] != '\n' && line[i])
	{
		res[i] = line[i];
		i++;
	}
	res[i] = line[i];
	res[++i] = '\0';
	return (res);
}

static char	*get_line(int fd, char *line)
{
	long	check;
	char	*buffer;

	check = 1;
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	while (check != 0)
	{
		check = read(fd, buffer, BUFFER_SIZE);
		if (check == -1)
			return (free(buffer), NULL);
		buffer[check] = '\0';
		if (line == NULL)
			line = ft_strdup(buffer);
		else
			line = ft_strjoin_alt(line, buffer);
		if (ft_strchr(line, '\n') != NULL)
			check = 0;
	}
	free(buffer);
	if (line[0] == 0)
		return (free(line), NULL);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*list[1024];
	char		*res;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	list[fd] = get_line(fd, list[fd]);
	if (!list[fd])
		return (NULL);
	res = build_res(list[fd]);
	list[fd] = new_line(list[fd]);
	return (res);
}
