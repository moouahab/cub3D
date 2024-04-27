/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moouahab <moouahab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 20:45:30 by moouahab          #+#    #+#             */
/*   Updated: 2023/11/01 19:21:36 by moouahab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
* @param lst : l'adresse du pointeur vers le premier element de list
* @param new : la valeur a ajouter au bout de la liste
* @return rien
* @details ajoute l'element 'new' a la fin de la liste
*/

void	ft_lstadd_back(t_list	**lst, t_list	*new)
{
	t_list	*current;

	current = *lst;
	if (!lst || !new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	while (current->next)
		current = current->next;
	current->next = new;
}
