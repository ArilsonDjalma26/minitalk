#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void handle_signal(int sig, siginfo_t *info, void *context)
{
	static unsigned char c;
	static int bit;
	(void)context;

	c |= (sig == SIGUSR1);
	bit++;
	if (bit == 8)
	{
		if (c == '\0')
			write(1, "\n", 1);
		else
			write(1, &c, 1);
		c = 0;
		bit = 0;
	}
	else
		c <<= 1;
	kill(info->si_pid, SIGUSR1);
}

int main(void)
{
    struct sigaction sa;
    sa.sa_sigaction = handle_signal;
    sa.sa_flags = SA_SIGINFO;
    sigemptyset(&sa.sa_mask);

	printf("Server PID: %d\n", getpid());

	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);

	while (1)
		pause();
}
