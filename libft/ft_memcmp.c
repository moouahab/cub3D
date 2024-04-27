/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moouahab <mohamed.ouahab1999@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 18:11:33 by moouahab          #+#    #+#             */
/*   Updated: 2023/10/22 18:11:33 by moouahab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void	*ptr1, const void	*ptr2, size_t num)
{
	const unsigned char	*s1;
	const unsigned char	*s2;

	s1 = ptr1;
	s2 = ptr2;
	while (num-- > 0)
	{
		if (*s1 != *s2)
			return ((int)(*s1 - *s2));
		s1++;
		s2++;
	}
	return (0);
}
