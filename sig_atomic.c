#include <signal.h>
#include <stdio.h>
 
volatile sig_atomic_t gSignalStatus = 0;
 
void signal_handler(int signal)
{
    gSignalStatus = signal;
}
 
int main(void)
{
    /* Install a signal handler. */
/*signal(signum to handler, address of a  programmer-defined  function)  */
    signal(SIGINT, signal_handler);
 
    printf("SignalValue:   %d\n", gSignalStatus);
    printf("Sending signal %d\n", SIGINT);

	/*raise() -send a signal to the caller */
	//raise(2);
    raise(SIGINT);

    printf("SignalValue:   %d\n", gSignalStatus);
}

/*The behavior of signal() varies across different versions of Linux.
Avoid  its  use: use sigaction() instead. */

/* kill -l ---> to check lis of all signals */
