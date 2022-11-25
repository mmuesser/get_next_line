/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmuesser <mmuesser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 11:17:01 by mmuesser          #+#    #+#             */
/*   Updated: 2022/11/25 15:12:30 by mmuesser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(const char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*ptr;
	size_t	i;

	if (nmemb != 0 && size != 0 && size > (size * nmemb) / nmemb)
		return (NULL);
	ptr = malloc(size * nmemb);
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < nmemb * size)
	{
		ptr[i] = 0;
		i++;
	}
	return (ptr);
}

char	*ft_strchr(const char *str, int c)
{
	int	i;

	if (c > 255)
		c -= 256;
	i = 0;
	while (str[i])
	{
		if (c == str[i])
			return ((char *) &str[i]);
		i++;
	}
	if (c == str[i])
		return ((char *) &str[i]);
	return (NULL);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	int		lenght;
	int		i;
	char	*dest;

	if (!s1)
		ft_calloc(sizeof(char), 1);
	lenght = ft_strlen(s1) + ft_strlen(s2);
	dest = ft_calloc(sizeof(char), lenght + 1);
	if (!dest)
		return (NULL);
	i = -1;
	while (++i < ft_strlen(s1))
		dest[i] = s1[i];
	i = -1;
	while (++i < ft_strlen(s2))
		dest[i + ft_strlen(s1)] = s2[i];
	dest[lenght] = '\0';
	free((char *) s1);
	return (dest);
}

char	*ft_strdup(const char *src, int start)
{
	char	*dest;
	int		lenght;
	int		i;

	lenght = ft_strlen(src) - start;
	dest = malloc(sizeof(char) * (lenght + 1));
	if (!dest)
		return (NULL);
	i = 0;
	while (i < lenght)
	{
		dest[i] = src[start];
		i++;
		start++;
	}
	dest[i] = '\0';
	return (dest);
}
