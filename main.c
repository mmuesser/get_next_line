/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmuesser <mmuesser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 13:46:55 by mmuesser          #+#    #+#             */
/*   Updated: 2022/11/22 17:03:26 by mmuesser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>

int		main(void)
{
	char	*str;
	int 	fd;
	fd = open("./files/test", O_RDONLY);
	while ((str = get_next_line(fd)))
	{
		if (!str)
			break;
		printf("str : %s", str);
		printf("-----------------------------------------------------------\n");
		free (str);
	}
	// str = get_next_line(fd);
	// printf("str : %s", str);
	// free (str);
	// str = get_next_line(fd);
	// printf("str : %s", str);
 	// free (str);
	return (0);
}