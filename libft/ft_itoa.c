/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalbano <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 13:16:03 by aalbano           #+#    #+#             */
/*   Updated: 2025/06/25 15:38:28 by aalbano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	cont_digit(int n)
{
	int	count;

	if (n == 0)
		return (1);
	count = 0;
	if (n < 0)
	{
		count++;
	}
	while (n != 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char	*ptr;
	int		len;
	long	nb;

	nb = (long)n;
	len = cont_digit(n);
	ptr = (char *) malloc (sizeof(char) * (len + 1));
	if (!ptr)
		return (NULL);
	ptr[len] = '\0';
	if (nb < 0)
	{
		ptr[0] = '-';
		nb = -nb;
	}
	if (nb == 0)
		ptr[0] = '0';
	while (nb > 0)
	{
		ptr[--len] = (nb % 10) + '0';
		nb = nb / 10;
	}
	return (ptr);
}
