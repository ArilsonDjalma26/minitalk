/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalbano <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 16:38:06 by aalbano           #+#    #+#             */
/*   Updated: 2025/06/20 17:19:23 by aalbano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{	
	size_t		i;
	size_t		j;
	char		*ptr;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	ptr = (char *) malloc ((ft_strlen(s1)) + (ft_strlen(s2) + 1));
	if (ptr != NULL)
	{
		while (s1[i])
		{
			ptr[i] = s1[i];
			i++;
		}
		while (s2[j])
		{
			ptr[i + j] = s2[j];
			j++;
		}
		ptr[i + j] = '\0';
	}
	return (ptr);
}
