/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmuesser <mmuesser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 11:07:36 by mmuesser          #+#    #+#             */
/*   Updated: 2022/11/25 15:12:15 by mmuesser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read(char *str, int fd)
{
	char	*tmp;
	int		file;

	tmp = ft_calloc(sizeof(char), (BUFFER_SIZE + 1));
	if (!tmp)
	{
		free(tmp);
		return (NULL);
	}
	file = 1;
	while (!ft_strchr(tmp, '\n') && file != 0)
	{
		file = read(fd, tmp, BUFFER_SIZE);
		if (file == -1)
		{
			free(tmp);
			return (NULL);
		}
		tmp[file] = '\0';
		str = ft_strjoin(str, tmp);
	}
	free(tmp);
	return (str);
}

void	ft_fill(char **str, char **s1)
{
	int		i;
	char	*tmp;
	char	*dest;

	tmp = *str;
	dest = *s1;
	i = 0;
	while (tmp[i] != '\n' && tmp[i])
	{
		dest[i] = tmp[i];
		i++;
	}
	if (tmp[i] == '\n')
	{
		dest[i] = tmp[i];
		i++;
	}
	dest[i] = '\0';
	tmp = ft_strdup(*str, i);
	free(*str);
	*str = tmp;
	if (!*str)
		free(*str);
}

char	*get_next_line(int fd)
{
	char		*dest;
	static char	*str;
	int			i;

	if (!str)
		str = ft_calloc(sizeof(char), 1);
	str = ft_read(str, fd);
	if (!str)
	{
		free(str);
		return (NULL);
	}
	i = 0;
	while (str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	dest = malloc(sizeof(char) * (i + 1));
	ft_fill(&str, &dest);
	return (dest);
}
