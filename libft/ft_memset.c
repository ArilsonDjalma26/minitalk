/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalbano <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 12:18:13 by aalbano           #+#    #+#             */
/*   Updated: 2025/06/17 12:18:16 by aalbano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*buffer;
	size_t			i;

	if (!s)
		return (NULL);
	i = 0;
	buffer = (unsigned char *)s;
	while (i < n)
	{
		buffer[i] = (unsigned char)c;
		i++;
	}
	return (s);
}
