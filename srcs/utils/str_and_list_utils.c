/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_and_list_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moouahab <moouahab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 16:38:07 by moouahab          #+#    #+#             */
/*   Updated: 2024/06/24 13:39:31 by moouahab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	free_tab2(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

bool	witdh_and_heigth_map(t_map *map)
{
	t_line	*current;

	current = map->line;
	map->map_height = size_map(current);
	if (map->map_height < 3 || !map->map_height)
		return (false);
	map->map_width = size_max_line(current);
	if (map->map_width < 3 || !map->map_width)
		return (false);
	return (true);
}

static void	copy_with_tab_conversion(char *dest, const char *src, int width,
		int i)
{
	int	j;
	int	k;
	int	space_count;

	j = 0;
	while (src[i] && j < width)
	{
		if (src[i] == '\t')
		{
			k = -1;
			space_count = TAB_SIZE - (j % TAB_SIZE);
			while (++k < space_count && j < width)
				dest[j++] = ' ';
		}
		else
			dest[j++] = src[i];
		i++;
	}
	while (j < width)
		dest[j++] = ' ';
	dest[width] = '\0';
}

char	**list_to_array(t_line *head, int height, int width)
{
	int		i;
	t_line	*current;
	char	**array;

	i = 0;
	current = head;
	array = (char **)malloc((height + 1) * sizeof(char *));
	if (!array)
		exit(EXIT_FAILURE);
	while (current)
	{
		array[i] = (char *)malloc((width + 1) * sizeof(char));
		if (!array[i])
			exit(EXIT_FAILURE);
		copy_with_tab_conversion(array[i], current->line, width, 0);
		i++;
		current = current->next;
	}
	array[i] = NULL;
	return (array);
}
