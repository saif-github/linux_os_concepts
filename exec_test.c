#include<stdio.h>
#include<unistd.h>
#include <stdlib.h>
#include <sys/types.h>

main()
{

char* arg_list[] = {"ps","-o","pid",NULL};

if(fork()==0)
{
	printf("pid2:%d\n",getpid());
	execvp(arg_list[0],arg_list);
	fprintf (stderr, "an error occurred in execvp\n");
	abort();
}
printf("pid1:%d\n",getpid());
wait(NULL);

}
