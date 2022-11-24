/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmuesser <mmuesser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 15:05:03 by mmuesser          #+#    #+#             */
/*   Updated: 2022/11/24 19:22:24 by mmuesser         ###   ########.fr       */
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

int	ft_in_str(const char *str, const char c)
{
	int	i;

	if (!str)
		return (-1);
	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	char	*dest;
	int		i;
	int		j;
	int		lenght;

	j = 0;
	while (ft_in_str(set, s1[j]) >= 0)
		j++;
	i = ft_strlen(s1);
	lenght = i - j;
	dest = (char *) ft_calloc(sizeof(char) , (lenght + 1));
	if (!dest)
		return (NULL);
	i = -1;
	while (++i < lenght)
	{
		dest[i] = s1[j];
		j++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	int		i;
	int		j;
	char	*dest;
	int		lenght;

	lenght = ft_strlen(s1) + ft_strlen(s2);
	dest = ft_calloc(sizeof(char) , (lenght + 1));
	if (!dest)
		return (NULL);
	i = 0;
	if (!s1)
		return ((char *) s2);
	while (s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		dest[i] = s2[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
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