/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalbano <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 09:07:37 by aalbano           #+#    #+#             */
/*   Updated: 2025/06/13 09:07:45 by aalbano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int	str_len;

	if (!str)
		return (NULL);
	str_len = ft_strlen (str);
	while (str_len >= 0)
	{
		if (str[str_len] == (char)c)
		{
			return ((char *)(str + str_len));
		}
		str_len--;
	}
	return (NULL);
}
