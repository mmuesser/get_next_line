/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmuesser <mmuesser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 11:44:41 by mmuesser          #+#    #+#             */
/*   Updated: 2022/11/26 15:01:43 by mmuesser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		main(void)
{
	char	*str;
	int 	fd;

	fd = open("./files/test", O_RDONLY);
	while ((str = get_next_line(fd)))
	{
		if (!str)
		 	break ;
		printf("%s", str);
		printf("-----------------------------------------------------------\n");
		free (str);
	}
	close(fd);
	return (0);
}