/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalbano <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 18:47:17 by aalbano           #+#    #+#             */
/*   Updated: 2025/07/22 12:31:53 by aalbano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	count_num(unsigned int num)
{
	int	count;

	count = 0;
	if (num != 0)
	{
		while (num != 0)
		{
			num /= 16;
			count++;
		}
	}
	else
	{
		count++;
	}
	return (count);
}

int	ft_print_hexa(int n, int ch)
{
	int				count;
	char			*base;
	unsigned int	nb;

	nb = (unsigned int)n;
	count = count_num(nb);
	if (ch == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	if (nb >= 16)
	{
		ft_print_hexa(nb / 16, ch);
		ft_print_hexa(nb % 16, ch);
	}
	else if (nb < 16)
	{
		ft_putchar(base[nb]);
	}
	return (count);
}
