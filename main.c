/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmuesser <mmuesser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 15:16:13 by mmuesser          #+#    #+#             */
/*   Updated: 2022/11/24 19:25:13 by mmuesser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>

int		main(void)
{
	char	*str;
	int 	fd;
	int		i = 0;

	fd = open("./files/empty", O_RDONLY);
	while ((str = get_next_line(fd)))
	{
		//str = get_next_line(fd); 
		if (!str)
		 	break ;
		printf("gnl : %s", str);
		printf("-----------------------------------------------------------\n");
		free (str);
		//i++;
	}
	return (0);
}