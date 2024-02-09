/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffleitas <ffleitas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 15:48:29 by ffleitas          #+#    #+#             */
/*   Updated: 2023/10/29 14:16:26 by ffleitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stdio.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*result;

	if (count == SIZE_MAX || size == SIZE_MAX)
		return (NULL);
	result = malloc (count * size);
	if (!result)
	{
		return (NULL);
	}
	else
	{
		ft_bzero (result, (count * size));
	}
	return (result);
}
// int main()
// {
// 	int *ptr;
// 	int i;

// 	// Testing ft_calloc
// 	ptr = ft_calloc(5, sizeof(int));

// 	i = 0;
// 	while (i < 5)
// 	{
// 		printf("%d ", ptr[i]);
// 		i ++;
// 	}
// 	printf("\n");
// 	// Freeing the allocated memory
// 	free(ptr);
// 	return 0;
// }