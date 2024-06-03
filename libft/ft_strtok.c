/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtok.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moouahab <moouahab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 09:53:47 by moouahab          #+#    #+#             */
/*   Updated: 2024/06/03 14:27:19 by moouahab         ###   ########.fr       */
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
	static char	*next_token;
	char		*token_start;
	int			pos;

	if (str != NULL)
		next_token = str;
	while (*next_token && ft_strchr(delim, *next_token))
		next_token++;
	if (*next_token == '\0')
		return (NULL);
	token_start = next_token;
	pos = ft_strcspn(next_token, delim);
	next_token += pos;
	if (*next_token != '\0')
	{
		*next_token = '\0';
		next_token++;
	}
	return (token_start);
}
