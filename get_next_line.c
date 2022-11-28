/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmuesser <mmuesser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 11:07:36 by mmuesser          #+#    #+#             */
/*   Updated: 2022/11/28 16:46:10 by mmuesser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read(char *str, int fd)
{
	char	*tmp;
	int		file;

	tmp = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!tmp)
	{
		free(tmp);
		return (NULL);
	}
	tmp[0] = '\0';
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

void	ft_fill(char **str, char **dest)
{
	int		i;
	char	*tmp;
	char	*tmp2;

	tmp = *str;
	tmp2 = *dest;
	i = 0;
	while (tmp[i] != '\n' && tmp[i])
	{
		tmp2[i] = tmp[i];
		i++;
	}
	if (tmp[i] == '\n')
	{
		tmp2[i] = tmp[i];
		i++;
	}
	tmp2[i] = '\0';
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

	str = ft_read(str, fd);
	if (!str)
	{
		free(str);
		return (NULL);
	}
	i = 0;
	while (str[i] != '\n' && str[i])
		i++;
	if (str[i] == '\n')
		i++;
	dest = malloc(sizeof(char) * (i + 1));
	ft_fill(&str, &dest);
	if (dest[0] == '\0')
	{
		free(dest);
		return (NULL);
	}
	return (dest);
}
