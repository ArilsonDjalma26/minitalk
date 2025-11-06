/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalbano <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 18:49:30 by aalbano           #+#    #+#             */
/*   Updated: 2025/07/22 12:06:44 by aalbano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_hexa(uintptr_t p, char *base)
{
	int	count;

	count = 0;
	if (p >= 16)
	{
		count += ft_hexa(p / 16, base);
		count += ft_hexa(p % 16, base);
	}
	else
	{
		count += ft_putchar(base[p]);
	}
	return (count);
}

int	ft_print_pointer(uintptr_t p)
{
	char	*base;
	int		count;

	base = "0123456789abcdef";
	count = 0;
	if (!p)
	{
		count = write (1, "(nil)", 5);
		return (count);
	}
	else
	{
		count += ft_putstr("0x");
		count += ft_hexa(p, base);
	}
	return (count);
}
