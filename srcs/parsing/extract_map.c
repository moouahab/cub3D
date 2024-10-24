/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moouahab <moouahab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 22:07:54 by moouahab          #+#    #+#             */
/*   Updated: 2024/06/06 14:55:59 by moouahab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

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

t_line	*create_new_node(char *line)
{
	t_line	*new_node;

	if (!line)
		return (NULL);
	new_node = (t_line *)malloc(sizeof(t_line));
	if (!new_node)
		return (NULL);
	else if (ft_strchr(line, '\n'))
		new_node->line = ft_strndup(line, ft_strlen(line) - 1);
	else
		new_node->line = ft_strndup(line, ft_strlen(line));
	if (!new_node->line)
	{
		free(new_node);
		return (NULL);
	}
	new_node->line_len = ft_strlen(line);
	new_node->next = NULL;
	return (new_node);
}

bool	append_node_to_list(t_line **head, t_line *new_node)
{
	t_line	*current;

	if (new_node == NULL)
	{
		return (false);
	}
	if (*head == NULL)
		*head = new_node;
	else
	{
		current = *head;
		while (current->next != NULL)
			current = current->next;
		current->next = new_node;
	}
	return (true);
}

bool	add_map_line(t_line **head, char *line, t_map *line_map, int count)
{
	t_line		*new_node;
	static int	i;
	int			j;

	if (!i)
	{
		i = 0;
		line_map->line_map = count;
	}
	j = 0;
	while (line[j++])
		if (line[j] == '\t')
			return (free(line), false);
	new_node = create_new_node(line);
	if (!append_node_to_list(head, new_node))
	{
		free(line);
		return (false);
	}
	free(line);
	return (true);
}
