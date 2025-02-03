/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mecauchy <mecauchy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 17:15:11 by mcauchy-          #+#    #+#             */
/*   Updated: 2025/01/28 18:38:59 by mecauchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst)
		return ;
	if (*lst == NULL)
		*lst = new;
	else if (lst)
	{
		if (*lst)
			new->next = *lst;
		*lst = new;
	}
}

// void	print_lst(t_list **lst)
// {
// 	t_list *temp;

// 	temp = *lst;
// 	while (temp)
// 	{
// 		printf("string is %s\n", (char *)temp->content);
// 		temp = temp->next;
// 	}
// 	printf("list printed \n\n");
// }

/*int main (int ac, char **av)
{
	t_list **lst;
	t_list *new1;
	t_list *new2;
	

	lst = malloc(sizeof(t_list *));
	new1 = malloc (sizeof(t_list));
	new2 = malloc (sizeof(t_list));

	print_lst(lst);

	new1->content = av[0];
	new1->next = NULL;
	ft_lstadd_front(lst, new1);
	printf("adding node 1\n");
	print_lst(lst);
	
	new2->content = av[1];
	new2->next = NULL;

	ft_lstadd_front(lst, new2);
	printf("adding node 2\n");
	print_lst(lst);
	return (0);
}*/