/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalbano <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 07:35:14 by aalbano           #+#    #+#             */
/*   Updated: 2025/10/31 07:35:16 by aalbano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include "libft/libft.h"
#include "printf/ft_printf.h"

volatile sig_atomic_t	g_ack = 0;

void	handle_ack(int sig)
{
	(void)sig;
	g_ack = 1;
}

void	send_signal(int pid, char c)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		g_ack = 0;
		if (c & (1 << i))
			kill (pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		while (!g_ack)
			pause();
		usleep (800);
		i++;
	}
	
}

int	is_valid_pid(const char *s)
{
	int		i;

	i = 0;
	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	check_pid(int pid)
{
	if (pid <= 0)
		return (0);
	if (kill(pid, 0) == -1)
		return (0);
	return (1);
}
int	main(int ac, char **av)
{
	int		pid;
	char	*msg;

	if (ac != 3)
		return (write(2, "Uso: ./client <PID> <mensagem>\n", 32), 1);
	if (!is_valid_pid(av[1]))
	{
		write (2, "PID inválido!\n", 15);
		return (1);
	}
	signal (SIGUSR1, handle_ack);
	pid = atoi(av[1]);
	if (!check_pid(pid))
		return (ft_printf("Erro: PID inválido ou servidor inativo.\n"), 1);
	msg = av[2];
	while (*msg)
		send_signal(pid, *msg++);
	send_signal(pid, '\0');
}
