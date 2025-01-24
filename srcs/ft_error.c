/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mecauchy <mecauchy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 14:39:36 by mecauchy          #+#    #+#             */
/*   Updated: 2025/01/23 18:50:05 by mecauchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	ft_error(char *str)
{
	ft_putendl_fd(str, 2);
	exit(1);
}

void	ft_perror(char *str)
{
	perror(str);
	exit(EXIT_FAILURE);
}

void	free_split(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}