/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalbano <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 14:05:40 by aalbano           #+#    #+#             */
/*   Updated: 2025/06/20 14:41:10 by aalbano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strcpy(char *dest, const char *src)
{
	size_t		i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
//Faz a copia exata de uma string em um novo bloco na memória

char	*ft_strdup(const char *s)
{
	char	*ptr;

	if (!s)
		return (NULL);
	ptr = (char *) malloc (ft_strlen (s) + 1);
	if (!ptr)
		return (NULL);
	ft_strcpy(ptr, s);
	return (ptr);
}
