/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moouahab <mohamed.ouahab1999@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 22:19:37 by moouahab          #+#    #+#             */
/*   Updated: 2024/06/22 15:32:29 by moouahab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char	*s, int c)
{
	while (*s != '\0')
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (NULL);
}

char	*ft_strnchr(const char	*s, int c, int n)
{
	int    i;

	i = 0;
	while (i < n)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
		i++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (NULL);
}