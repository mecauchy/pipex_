/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcauchy- <mcauchy-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 17:16:14 by mcauchy-          #+#    #+#             */
/*   Updated: 2024/11/11 12:49:58 by mcauchy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*v_s1;
	unsigned char	*v_s2;
	unsigned int	i;

	v_s1 = (unsigned char *)s1;
	v_s2 = (unsigned char *)s2;
	i = 0;
	if (n == 0)
		return (0);
	while (v_s1[i] == v_s2[i] && n > 1)
	{
		i++;
		n--;
	}
	return ((int)(v_s1[i] - v_s2[i]));
}
