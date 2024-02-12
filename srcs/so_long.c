/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffleitas <ffleitas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 19:16:36 by ffleitas          #+#    #+#             */
/*   Updated: 2024/02/12 17:36:03 by ffleitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_argument(char *argv)
{
	while(*argv)
	{
		if(*argv == '.' && *(argv + 1) == 'b' && *(argv + 2) == 'e'
			&& *(argv + 3) == 'r' && *(argv + 4) == '\0')
		{
			return (0);
		}
		argv ++;
	}
	if (*argv == '\0')
		handle_errors("The map type is INCORRECT");
	return (0);
}

int main(int argc, char **argv)
{
	t_game map;

    if (argc != 2)
	{
		printf("EXAMPLE OF USE: ./so_long + map.ber\n");
		return (0);
	}
	handle_argument(argv[1]);
	mapping(argv[1], &map);
	init_game(&map);
	// system("leaks -q so_long");
	return (0);
}
