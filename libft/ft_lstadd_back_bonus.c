/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcauchy- <mcauchy-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 17:15:05 by mcauchy-          #+#    #+#             */
/*   Updated: 2024/11/11 15:12:54 by mcauchy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last_elm;

	last_elm = 0;
	if (lst)
	{
		if (*lst)
		{
			last_elm = ft_lstlast(*lst);
			last_elm->next = new;
		}
		else
			*lst = new;
	}
}
