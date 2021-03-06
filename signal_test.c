#include<stdio.h>
#include<signal.h>
#include<unistd.h>

void signal_test(int sig)
{

	//signal(SIGINT,SIG_IGN);	//SIG_IGN-->it ignores the signal and doesn't executes this function
	//signal(SIGINT,SIG_DFL);	// SIG_DFL-->it run default action of signal

	printf("see,i got signal %d \n",sig);
}

int main()
{
	signal(SIGINT,signal_test);
	while(1)
	{
		printf(" hi linux! pid=%d\n",getpid());
		sleep(1);
	}
}


/*signal() sets the disposition of the signal signum to handler, which is
either SIG_IGN, SIG_DFL, or the address of a  programmer-defined  function */

/* If  the signal signum is delivered to the process, then one of the fol‐
       lowing happens:

       *  If the disposition is set to SIG_IGN, then the signal is ignored.

       *  If the disposition is set to SIG_DFL, then the default action  asso‐
          ciated with the signal (see signal(7)) occurs.

       *  If  the disposition is set to a function, then first either the dis‐
          position is reset to SIG_DFL, or the signal is blocked  (see  Porta‐
          bility  below), and then handler is called with argument signum.  If
          invocation of the handler caused the signal to be blocked, then  the
          signal is unblocked upon return from the handler.  */

/*The signals SIGKILL(ctrl+z) and SIGSTOP cannot be caught or ignored.  */
