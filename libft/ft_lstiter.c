/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moouahab <moouahab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 22:16:13 by moouahab          #+#    #+#             */
/*   Updated: 2023/11/01 19:23:24 by moouahab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
* @param lst : l'adresse du pointeur vers un element;
* @param f   : l'adresse de la function a appliquer;
* @details 	itere sur la litse 'lst' et applisque 
*			la fonction f au contenue de chaque 
*			element
*/

void	ft_lstiter(t_list *lst, void (*f)(void*))
{
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}
