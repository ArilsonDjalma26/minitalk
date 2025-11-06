# include <signal.h>
# include <unistd.h>
# include <stdlib.h>
# include "ft_printf/ft_printf.h"
# include "libft/libft.h"

void handle_signal(int sig, siginfo_t *info, void *context)
{
    static char c;
    static int bit;

    (void)context;
    if (sig == SIGUSR2)
        c |= 1 << bit;
    bit++;
    if (bit == 8)
    {
        if (c == '\0')
            kill(info -> si_pid, SIGUSR1);
        ft_printf("%c", c);
        c = 0;
        bit = 0;
    }

}
int main()
{
    struct sigaction sa;

    ft_printf("PID: %d\n", getpid);
    sa.sa_sigaction = handle_signal;
    sa.sa_flags = SA_SIGINFO;
    sigemptyset(&sa.sa_mask);
    sigaction(SIGUSR1, &sa, NULL);
    sigaction(SIGUSR2, &sa, NULL);
    while (1)
        pause();
}