/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moouahab <mohamed.ouahab1999@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 22:04:01 by moouahab          #+#    #+#             */
/*   Updated: 2024/04/27 18:18:55 by moouahab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while ((n > 0 && *s1) || (*s2 && n > 0))
	{
		if (*s1 != *s2)
			return ((int)((unsigned char)*s1 - (unsigned char)*s2));
		s1++;
		s2++;
		n--;
	}
	return (0);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (int)((unsigned char)*s1 - (unsigned char)*s2);
}
