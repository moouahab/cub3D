/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moouahab <mohamed.ouahab1999@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 22:19:37 by moouahab          #+#    #+#             */
/*   Updated: 2024/06/23 12:21:40 by moouahab         ###   ########.fr       */
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

char	*ft_strnchr(const char *s, int c, int n)
{
	int	i;

	i = 0;
	while (i < n && *s != '\0')
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
		i++;
	}
	if (c == '\0' && i < n)
		return ((char *)s);
	return (NULL);
}
