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

volatile sig_atomic_t g_ack = 0;

void send_signal(int pid, char c)
{
	int		i;

	i = 0;
	while(i < 8)
	{
		if (c & (1 << i))
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		
		usleep(800);
		i++;
	}

 	while(!g_ack)
		pause();
	g_ack = 0;
}
void handle_ack(int sig)
{
	(void)sig;
	g_ack = 1;
}
int main(int ac, char **av)
{
	int		pid;
	char	*msg;

	if (ac != 3)
	{
		ft_printf("Uso: %s <PID> <mensagem>\n", av[0]);
		return(1);
	}
	signal(SIGUSR1, handle_ack);
	pid	= atoi(av[1]);
	msg = av[2];

	while (*msg)
		send_signal(pid, *msg++);
	send_signal(pid, '\0');
	return(0);
}