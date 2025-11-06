/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_uns.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalbano <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 18:50:34 by aalbano           #+#    #+#             */
/*   Updated: 2025/07/21 19:31:28 by aalbano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	count_uns(unsigned int n)
{
	int	count;

	count = 0;
	if (n != 0)
	{
		while (n != 0)
		{
			n /= 10;
			count++;
		}
	}
	else
	{
		count++;
	}
	return (count);
}

int	ft_putnbr_uns(int n)
{
	unsigned int	nb;
	int				count;

	count = 0;
	nb = (unsigned int)n;
	count = count_uns(nb);
	if (nb >= 10)
	{
		ft_putnbr_uns(nb / 10);
		ft_putnbr_uns(nb % 10);
	}
	else
		ft_putchar (nb + '0');
	return (count);
}
