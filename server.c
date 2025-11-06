/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalbano <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 07:34:55 by aalbano           #+#    #+#             */
/*   Updated: 2025/10/31 07:34:58 by aalbano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include "libft/libft.h"
#include "printf/ft_printf.h"

void	handle_signal(int sig, siginfo_t *info, void *context)
{
	static int		bit;
	static char		c;

	(void)context;
	if (sig == SIGUSR2)
		c |= (1 << bit);
	bit++;
	if (bit ==  8)
	{
		if(c == '\0')
			write(1, "\n", 1);
		else
			write(1, &c, 1);
		kill(info -> si_pid, SIGUSR1);
		bit = 0;
		c = 0;
	}
}
int main()
{
	struct	sigaction sa;
	
	ft_printf("PID: %d\n", getpid());
	sa.sa_sigaction = handle_signal;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while(1)
		pause();
	return(0);
}
