/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmuesser <mmuesser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 15:10:21 by mmuesser          #+#    #+#             */
/*   Updated: 2022/12/13 15:12:23 by mmuesser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	main(void)
{
	char	*str;
	int		fd;

	fd = open("./files/empty", O_RDONLY);
	while ((str = get_next_line(fd)))
	{
		if (!str)
			break ;
		printf("%s", str);
		printf("------------------------------------------------------------\n");
		free(str);
	}
	close(fd);
	return (0);
}

