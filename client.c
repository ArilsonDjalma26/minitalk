# include <signal.h>
# include <unistd.h>
# include <stdlib.h>
# include "ft_printf/ft_printf.h"
# include "libft/libft.h"

void handle_ack(int sig);
void    send_signal(char c, int pid)
{
    int i = 0;
    while(i < 8)
    {
        if ((c >> i) & 1)
            kill(pid, SIGUSR2);
        else
            kill(pid, SIGUSR1);
        i++;
        usleep(300);
        i++;
    }
__attribute__((used))
    void handle_ack(int sig)
    {
        (void)sig;
        ft_printf("\nMensagem recebida pelo servidor!\n");
        exit(0);
    }
}
int main(int ac, char **av)
{
    int     pid;
    char    *msg;
    if (ac != 3)
    {
        ft_printf("Uso: %s <PID> <mensagem>\n", av[0]);
        return (1);
    }
    signal(SIGUSR1, handle_ack);
    pid = ft_atoi(av[1]);
    msg = av[2];
    while(*msg)
        send_signal(*msg++, pid);
    send_signal('\0', pid);
    while(1)
        pause();
}