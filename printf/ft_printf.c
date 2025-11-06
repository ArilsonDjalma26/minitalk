/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalbano <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 10:59:39 by aalbano           #+#    #+#             */
/*   Updated: 2025/07/15 18:47:29 by aalbano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h" 

static int	ft_printf_help(int format, va_list args)
{
	int		return_func;

	return_func = 0;
	if ((format == 'd') || (format == 'i'))
		return_func += ft_putnbr(va_arg(args, int));
	else if (format == 'u')
		return_func += ft_putnbr_uns(va_arg(args, int));
	else if (format == 'c')
		return_func += ft_putchar((char)va_arg(args, int));
	else if (format == 's')
		return_func += ft_putstr(va_arg(args, char *));
	else if (format == 'x' || format == 'X')
		return_func += ft_print_hexa(va_arg(args, int), format);
	else if (format == 'p')
		return_func += ft_print_pointer((uintptr_t)va_arg(args, void *));
	else if (format == '%')
		return_func += write (1, "%", 1);
	return (return_func);
}

int	ft_printf(const char *format, ...)
{
	va_list		args;
	int			i;
	int			return_func;

	if (!format)
		return (-1);
	i = 0;
	return_func = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1]
			&& ft_strchr("cspuidxX%", format[i + 1]))
		{
			return_func += ft_printf_help(format[i + 1], args);
			i += 2;
		}
		else
		{
			write(1, &format[i++], 1);
			return_func++;
		}
	}
	va_end (args);
	return (return_func);
}
