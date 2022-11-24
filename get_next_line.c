/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmuesser <mmuesser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 17:58:02 by mmuesser          #+#    #+#             */
/*   Updated: 2022/11/24 19:26:17 by mmuesser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*str;
	char		*dest;
	char		*tmp;
	int			file;
	int			i;
	int			lenght;

	dest = NULL;
	if (fd > 1024 || fd <= 0)
		return (NULL);
	tmp = ft_calloc(sizeof(char) , (BUFFER_SIZE + 1));
	if (!tmp)
		return (NULL);
	if (!str)
		str = ft_calloc(sizeof(char) , 1);
	if (!str)
		return (NULL);
	file = 1;
	while ( file != 0 && ft_in_str(tmp, '\n') == -1)
	{
		file = read(fd, tmp, BUFFER_SIZE);
		if (file <= 0)
			return (NULL);
		tmp[file] = '\0';
		str = ft_strjoin(str, tmp);
		
	}
	free(tmp);
	lenght = ft_in_str(str, '\n');
	dest = ft_calloc(sizeof(char) , (lenght + 2));
	i = 0;
	while (str[i] != '\n' && str[i])
	{
		dest[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
	str = ft_strtrim(str, dest);
	return (dest);
}