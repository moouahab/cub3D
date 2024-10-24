/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moouahab <mohamed.ouahab1999@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 21:17:45 by moouahab          #+#    #+#             */
/*   Updated: 2024/04/29 18:33:18 by moouahab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

static int	ft_is_sp(char s, char c)
{
	if (s == c)
		return (1);
	return (0);
}

int	ft_count_word(char	*str, char c)
{
	int	inside_word;
	int	count;

	inside_word = 0;
	count = 0;
	while (*str)
	{
		if (ft_is_sp(*str, c))
			inside_word = 0;
		else if (!inside_word)
		{
			count++;
			inside_word = 1;
		}
		str++;
	}
	return (count);
}

/**
 * @param s : chaine de caractere 
 * @param c : le char de separation 
 * dans cette version de split nous utilisont 
 * une variable static qui va agir comme un 
 * curseur qui ce deplace tout au long de la string
 *
 * */

static char	*get_next_word(char	*s, char c)
{
	static int	cursor = 0;
	char		*next_word;
	int			len;
	int			i;

	len = 0;
	i = 0;
	while (s[cursor] == c)
		++cursor;
	while ((s[cursor + len] != c) && s[cursor + len])
		len++;
	next_word = malloc((size_t)len * sizeof (char) + 1);
	if (!next_word)
		return (NULL);
	while ((s[cursor] != c) && s[cursor])
		next_word[i++] = s[cursor++];
	next_word[i] = '\0';
	return (next_word);
}

char	**ft_split(char	*str, char c)
{
	int		i;
	char	**strs;
	int		count;

	count = ft_count_word(str, c);
	i = 0;
	if (!count)
		exit(1);
	strs = malloc(((size_t)count + 2) * sizeof(char *));
	if (!strs)
		return (NULL);
	while (count-- >= 0)
	{
		if (i == 0)
		{
			strs[i] = malloc(sizeof(char));
			if (!strs[i])
				return (NULL);
			strs[i++][0] = '\0';
			continue ;
		}
		strs[i++] = get_next_word(str, c);
	}
	strs[i] = NULL;
	return (strs);
}

/*
void	ft_free_tab(char	**strs)
{
	for (int i = 0; strs[i]; i++)
		free(strs[i]);
	free(strs);
}


int main(int ac, char *av[])
{
	char **strs = ft_split(av[1], ' ');
	for (int i = 0; strs[i]; i++)
		printf("la chaine decouper --> %s\n", strs[i]);
	ft_free_tab(strs);
	return (0);
}*/
