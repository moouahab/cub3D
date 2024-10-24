/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moouahab <mohamed.ouahab1999@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 23:20:46 by moouahab          #+#    #+#             */
/*   Updated: 2023/10/19 23:20:46 by moouahab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void	*dest, const void	*src, size_t n)
{
	char	*dst;
	char	*sc;

	dst = (char *)dest;
	sc = (char *)src;
	if (!dest && !src)
		return (NULL);
	while (n-- > 0)
		*dst++ = *sc++;
	return (dest);
}
