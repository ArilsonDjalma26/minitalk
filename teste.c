#include <signal.h>
#include <unistd.h>
#include <stdio.h>

static void handler_signal(int sig, siginfo_t *info, void *context)
{
    static int bit;
    static unsigned char c;

    (void)context;

    c |= (sig == SIGUSR1);
    if(bit == 8)
    {
        if (c == '\0')
            write(1, "\n", 1);
        else
            write(1, &c, 1);
        bit = 0;
        c = 0;
    }
    else
        c <<= 1;
    kill(info -> si_pid, SIGUSR1);
}

int main(void)
{
    struct sigaction sa;

    sa.sa_sigaction = handler_signal;
    sa.sa_fags = SA_SIGINFO;
    sigemptyset(&sa.sa_mask);

    printf("PID: %d", getpid());

    sigaction(SIGUSR1, &sa, NULL);
    sigaction(SIGUSR2, &sa, NULL);

    while(1)
        pause();
    return (0);
}