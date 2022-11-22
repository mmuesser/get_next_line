/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmuesser <mmuesser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 11:00:01 by mmuesser          #+#    #+#             */
/*   Updated: 2022/11/22 17:12:25 by mmuesser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read(char *tmp2, int fd)
{
	int		file;
	char	*tmp;

	tmp = ft_calloc(sizeof(char), BUFFER_SIZE + 1);
	if (!tmp)
		return (NULL);
	file = 1;
	while (ft_in_tmp(tmp, '\n') == -1 && file != 0)
	{
		file = read(fd, tmp, BUFFER_SIZE);
		if (file < 0)
			return (NULL);
		tmp[file] = '\0';
		tmp2 = ft_strjoin(tmp2, tmp);
	}
	free(tmp);
	return (tmp2);
}

char	*get_next_line(int fd)
{
	char		*dest;
	static char	*tmp2;
	int			i;
	int			lenght;

	if (!tmp2)
		tmp2 = ft_calloc(sizeof(char), 1);
	tmp2 = ft_read(tmp2, fd);
	lenght = ft_in_tmp(tmp2, '\n');
	dest = ft_calloc(sizeof(char), lenght + 2);
	if (!dest || !(*tmp2))
		return (NULL);
	i = 0;
	while (*tmp2 != '\n' && *tmp2)
	{
		dest[i] = *tmp2++;
		i++;
	}
	if (*tmp2 == '\n')
	{
		dest[i] = *tmp2++;
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
