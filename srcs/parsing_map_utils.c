/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffleitas <ffleitas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 14:54:35 by ffleitas          #+#    #+#             */
/*   Updated: 2024/01/19 20:02:30 by ffleitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


//Manejar errores para mostrar los fallos por pantalla
void handle_errors(char *error)
{
	ft_printf("Error\n");
	ft_printf("%s\n",error);
	exit (1);
}

// Función que verifica el tamaño del mapa CHECK!
int map_size(int fd)
{
	int counter;
	char *map_line;

	counter = 0;
	map_line = get_next_line(fd);
	if (!map_line)
		return (0);
	while (map_line)
	{
		counter ++;
		free(map_line);
		map_line = get_next_line(fd);
	}
	free(map_line);
	close (fd);
	if (counter == 0 || counter < 3)
		handle_errors("Map is empty or need at least 3 rows"); 
	return (counter);
}


