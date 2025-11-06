/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalbano <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 11:23:49 by aalbano           #+#    #+#             */
/*   Updated: 2025/06/26 13:26:00 by aalbano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s, char const *set)
{
	char		*ptr;
	int			start;
	int			end;
	int			len;

	if (!s || !set)
		return (NULL);
	len = ft_strlen(s);
	start = 0;
	end = len;
	while (s[start] && ft_strchr(set, s[start]))
		start++;
	while (end > start && ft_strchr(set, s[end - 1]))
		end--;
	ptr = ft_substr(s, start, end - start);
	return (ptr);
}
