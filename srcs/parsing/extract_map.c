/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moouahab <mohamed.ouahab1999@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 22:07:54 by moouahab          #+#    #+#             */
/*   Updated: 2024/05/02 11:00:31 by moouahab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

bool	find_line_first_end_last_map(char *line)
{
	int			i;
	static bool	inside_map = false;

	i = 0;
	while (i < (int)ft_strlen(line) - 1)
	{
		if (line[i] == '1' || line[i] == ' ')
			inside_map = true;
		else
		{
			inside_map = false;
			break ;
		}
		i++;
	}
	return (inside_map);
}

bool	inside_map(char *line, t_map *map)
{
	static int	passage;

	if (!line)
		return (false);
	if (!passage && find_line_first_end_last_map(line))
	{
		passage = 1;
		map->beggin_map = true;
	}
	else if (passage == 1 && !find_line_first_end_last_map(line))
		passage = 2;
	return (map->beggin_map);
}

bool	check_line(char *line)
{
	int	i;

	i = 0;
	if (ft_strnstr(line, "NO", ft_strlen(line)) || ft_strnstr(line, "EA",
			ft_strlen(line)) || ft_strnstr(line, "SO", ft_strlen(line))
		|| ft_strnstr(line, "WE", ft_strlen(line)))
		return (true);
	while (line[i] && i < (int)ft_strlen(line))
	{
		if (line[i] != '0' && line[i] != '1' && line[i] != ' ' && line[i] != 'N'
			&& line[i] != '\n')
		{
			printf("je suis %s\n", line);
			free(line);
			return (false);
		}
		i++;
	}
	return (true);
}

/**
 * @param : line va est la line recupere par gnl
 * @param : map est une liste chaine qui va stoker
 * 			une line dans chaqu'une de ces noeud
 * @return : true si la line est bien recupere si non
 * 			false
 *
 * typedef struct s_line
 * {
 * 		char			*line;
 * 		size_t			line_len;
 * 		struct s_line	*next;
 * }					t_line;
 */
bool	add_map_line(t_line **head, char *line)
{
	t_line	*new_node;
	t_line	*current;

	if (!line)
		return (false);
	new_node = malloc(sizeof(t_line));
	if (!new_node)
		return (false);
	new_node->line = ft_strdup(line);
	if (!new_node->line)
	{
		free(new_node);
		return (false);
	}
	new_node->line_len = ft_strlen(line);
	new_node->next = NULL;
	if (*head == NULL)
		*head = new_node;
	else
	{
		current = *head;
		while (current->next != NULL)
			current = current->next;
		current->next = new_node;
	}
	free(line);
	return (true);
}

/**
 * Libère toute la mémoire utilisée par la liste chaînée de lignes de la carte.
 * @param head La tête de la liste chaînée.
 */
void	free_map_lines(t_line *head)
{
	t_line	*current;
	t_line	*next;
	
	current = head;
	while (current != NULL)
	{
		next = current->next;
		free(current->line);
		free(current);
		current = next;
	}
}