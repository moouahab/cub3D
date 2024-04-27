/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moouahab <moouahab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 16:49:56 by moouahab          #+#    #+#             */
/*   Updated: 2023/11/01 19:21:33 by moouahab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/**
* @param lst :  adrress du pointeur vers le premier element de la list
* @param new : 	adresse du noeud a ajouter en debut de liste
* @return rien
* @details : ajoute l'element 'new' au debut de la liste 
*/

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst == NULL || new == NULL)
		return ;
	new->next = (*lst);
	*lst = new;
}
