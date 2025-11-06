/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalbano <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 17:44:57 by aalbano           #+#    #+#             */
/*   Updated: 2025/07/15 17:52:24 by aalbano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *s)
{
	int		count;

	count = 0;
	if (!s)
		count += write(1, "(null)", 6);
	else
	{	
		count = 0;
		while (*s)
		{
			write(1, *(&s), 1);
			s++;
			count++;
		}
	}
	return (count);
}
