/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalbano <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 11:45:32 by aalbano           #+#    #+#             */
/*   Updated: 2025/06/20 12:11:19 by aalbano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//calloc aloca memória com size bytes de n elementos

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	if (nmemb != 0 && size > SIZE_MAX / nmemb)
		return (NULL);
	ptr = (void *) malloc (nmemb * size);
	if (!ptr)
		return (NULL);
	ft_memset (ptr, '\0', nmemb * size);
	return (ptr);
}
