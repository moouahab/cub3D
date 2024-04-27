/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moouahab <moouahab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 18:31:25 by moouahab          #+#    #+#             */
/*   Updated: 2023/11/08 17:23:09 by moouahab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

/**
 * @param num_elements : est le nombre d'element de a alouer 
 * @param elements_size : taill des element
 * @return: ptr ou NULL si 
 * @details : allou est initialise un tableaux dynamiquement 
*/

void	*ft_calloc(size_t num_elements, size_t element_size)
{
	void	*ptr;

	if (element_size > 0 && SIZE_MAX / element_size < num_elements)
		return (NULL);
	ptr = malloc(num_elements * element_size);
	if (ptr == NULL)
		return (NULL);
	ft_memset(ptr, 0, num_elements * element_size);
	return (ptr);
}

// int	main()
// {
// 	char *test = ft_calloc(547608330240, 0);
// 	printf("%lu", strlen(test));
// }
