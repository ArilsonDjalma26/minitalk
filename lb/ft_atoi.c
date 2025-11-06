/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalbano <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 10:07:08 by aalbano           #+#    #+#             */
/*   Updated: 2025/07/04 17:23:47 by aalbano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_overflow(long result, int sinal, char c)
{
	if (result > (LONG_MAX - (c - '0')) / 10)
	{
		if (sinal == 1)
			return (-1);
		return (0);
	}
	return (1);
}

int	ft_atoi(const char *nptr)
{
	long	i;
	int		sinal;
	long	result;
	int		status;

	if (!nptr)
		return (0);
	i = 0;
	sinal = 1;
	result = 0;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i++] == '-')
			sinal = -1;
	}
	while (nptr[i] != '\0' && nptr[i] >= '0' && nptr[i] <= '9')
	{
		status = check_overflow(result, sinal, nptr[i]);
		if (status != 1)
			return (status);
		result = result * 10 + (nptr[i++] - '0');
	}
	return ((int)(result * sinal));
}
