/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalbano <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 12:19:05 by aalbano           #+#    #+#             */
/*   Updated: 2025/06/17 12:19:08 by aalbano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*buffer;

	if (!s)
		return ;
	i = 0;
	buffer = (unsigned char *)s;
	while (i < n)
	{
		buffer[i] = 0;
		i++;
	}
}
