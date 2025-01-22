/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcauchy- <mcauchy-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 17:16:33 by mcauchy-          #+#    #+#             */
/*   Updated: 2024/11/08 17:16:35 by mcauchy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void	*b, int c, size_t n)
{
	unsigned char	*ptr;
	unsigned char	a;
	size_t			i;

	i = 0;
	ptr = (unsigned char *)b;
	a = (unsigned char)c;
	while (n)
	{
		ptr[i] = a;
		i++;
		n--;
	}
	return (ptr);
}
