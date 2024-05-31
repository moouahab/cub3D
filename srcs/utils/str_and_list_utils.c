/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_and_list_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moouahab <mohamed.ouahab1999@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 16:38:07 by moouahab          #+#    #+#             */
/*   Updated: 2024/05/30 17:55:22 by moouahab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void    free_tab2(char **tab)
{
    int i;

    i = 0;
    while (tab[i])
    {
        free(tab[i]);
        i++;
    }
    free(tab);
}

static void	add_space(char **array, int width, int start, int i)
{
	int	j;

	j = start;
	while (j < width)
		array[i][j++] = ' ';
	array[i][width] = '\0';
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
		ft_strncpy(array[i], current->line, width);
		add_space(array, width, strlen(current->line), i);
		i++;
		current = current->next;
	}
    array[i] = NULL;
    free_map_lines(current);
	return (array);
}
