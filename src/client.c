#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

volatile sig_atomic_t g_ack = 0;

void ack_handler(int sig)
{
	(void)sig;
	g_ack = 1;
}

void send_signal(int pid, unsigned char c)
{
	int i;

	i = 8;
	while (i--)
	{
		g_ack = 0;
		if ((c >> i) & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		while (!g_ack)
			pause();
	}
}

int main(int argc, char **argv)
{
	int pid;
	int i;

	if (argc != 3)
	{
		printf("Uso: %s <PID> <mensagem>\n", argv[0]);
		return (1);
	}
	signal(SIGUSR1, ack_handler);
	pid = atoi(argv[1]);
	i = 0;
	while (argv[2][i])
	{
		send_signal(pid, argv[2][i]);
		i++;
	}
	send_signal(pid, '\0');
	return (0);
}
