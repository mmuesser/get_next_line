/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmuesser <mmuesser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 11:09:08 by mmuesser          #+#    #+#             */
/*   Updated: 2022/11/28 16:24:58 by mmuesser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdint.h>

char	*get_next_line(int fd);
char	*ft_strchr(const char *str, int c);
char	*ft_read(char *str, int fd);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(const char *src, int start);
int		ft_strlen(const char *str);
void	ft_fill(char **str, char **s1);

#endif