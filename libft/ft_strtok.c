/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtok.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moouahab <mohamed.ouahab1999@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 09:53:47 by moouahab          #+#    #+#             */
/*   Updated: 2024/04/29 09:55:32 by moouahab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * La fonction ft_strcspn() calcule la longueur du préfixe d'une chaîne
 * de caractères qui ne contient aucun des caractères spécifiés dans
 * une chaîne de recherche charset.
 */

size_t	ft_strcspn(const char *str, const char *charset)
{
	const char	*s;
	size_t		count;

	count = 0;
	s = str;
	while (*s != '\0')
	{
		if (ft_strchr(charset, *s) != NULL)
			return (count);
		++count;
		++s;
	}
	return (count);
}

/**
 * La fonction ft_strtok() découpe une chaîne de caractères str
 * en jetons en utilisant les délimiteurs spécifiés dans la
 * chaîne delim.
 */
char	*ft_strtok(char *str, const char *delim)
{
	static char	*nextToken;
	char		*token_start;
	int			pos;

	if (str != NULL)
		nextToken = str;
	while (*nextToken && ft_strchr(delim, *nextToken))
		nextToken++;
	if (*nextToken == '\0')
		return (NULL);
	token_start = nextToken;
	pos = ft_strcspn(nextToken, delim);
	nextToken += pos;
	if (*nextToken != '\0')
	{
		*nextToken = '\0';
		nextToken++;
	}
	return (token_start);
}