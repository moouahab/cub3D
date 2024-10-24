/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moouahab <mohamed.ouahab1999@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 01:31:14 by moouahab          #+#    #+#             */
/*   Updated: 2024/04/29 20:55:31 by moouahab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strndup(char *s, int len)
{
	int		i;
	char	*tab;

	i = 0;
	if (!s || !len)
		return (NULL);
	tab = (char *)malloc(sizeof(char) * (len + 1));
	if (!tab)
		return (NULL);
	while (i < len)
	{
		tab[i] = s[i];
		i++;
	}
	tab[i] = '\0';
	return (tab);
}

char	*ft_join(char *s1, char *s2)
{
	size_t	i;
	int		len;
	char	*s;

	i = 0;
	len = ft_strlen(s2);
	if (!s1)
		return (ft_strndup(s2, len));
	len = len + ft_strlen(s1);
	s = (char *)malloc(sizeof(char) * (len + 1));
	if (!s)
		return (NULL);
	len = 0;
	while (s1[i])
		s[len++] = s1[i++];
	i = 0;
	while (s2[i])
		s[len++] = s2[i++];
	s[len] = '\0';
	free(s1);
	return (s);
}

int	is_n(char *temp)
{
	int	i;

	i = 0;
	if (!temp)
		return (0);
	while (temp[i])
	{
		if (temp[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*print_line(char **temp)
{
	char	*result;
	char	*copy;
	int		pos;

	pos = 0;
	if (!*temp)
		return (NULL);
	copy = *temp;
	while (copy[pos] && copy[pos] != '\n')
		pos++;
	if (copy[pos] == '\n')
		pos++;
	result = ft_strndup(copy, pos);
	*temp = ft_strndup(copy + pos, ft_strlen(copy + pos));
	if (copy)
		free(copy);
	copy = NULL;
	return (result);
}
