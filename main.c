/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmuesser <mmuesser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 11:44:41 by mmuesser          #+#    #+#             */
/*   Updated: 2022/11/25 15:11:12 by mmuesser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		main(void)
{
	char	*str;
	int 	fd;
	//int		i = 0;

	fd = open("./files/test", O_RDONLY);
	// while ((str = get_next_line(fd)))
	// {
	// 	str = get_next_line(fd); 
	// 	if (!str)
	// 	 	break ;
	// 	printf("gnl : %s", str);
	// 	printf("-----------------------------------------------------------\n");
	// 	free (str);
	// 	//i++;
	// }
	str = get_next_line(fd); 
	printf("%s", str);
	printf("-----------------------------------------------------------\n");
	free (str);
	str = get_next_line(fd); 
	printf("%s", str);
	printf("-----------------------------------------------------------\n");
	free (str);
	str = get_next_line(fd); 
	printf("%s", str);
	printf("-----------------------------------------------------------\n");
	free (str);
	str = get_next_line(fd); 
	printf("%s", str);
	printf("-----------------------------------------------------------\n");
	free (str);
	str = get_next_line(fd); 
	printf("%s", str);
	printf("-----------------------------------------------------------\n");
	free (str);
	str = get_next_line(fd); 
	printf("%s", str);
	printf("-----------------------------------------------------------\n");
	free (str);
	close(fd);
	return (0);
}