/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalbano <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 11:42:12 by aalbano           #+#    #+#             */
/*   Updated: 2025/07/22 12:05:30 by aalbano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdint.h>

int		ft_printf(const char *format, ...);
int		ft_putstr(char *s);
int		ft_putnbr(int n);
int		ft_putnbr_uns(int n);
int		ft_putchar(char ch);
int		ft_print_hexa(int n, int ch);
int		ft_print_pointer(uintptr_t p);
char	*ft_strchr(const char *str, int c);
#endif
