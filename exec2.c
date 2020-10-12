#include<stdio.h>
#include<unistd.h>

int num=25;	//this doesn't effect the num from exec1

int main(void)
{
	printf("pid of exec2:%d\n",getpid());
	char *arg_ls[]={"./exec1","hello","linux",NULL};	//NULL-terminated array of pointers to character strings
/*passing name of other program first then rest of arguments*/

/*when a program is invoked from the shell, the shell sets the first element of the argument list ( argv[0] ) to
the name of the program*/
	//execvp("./exec1",arg_ls);
	execvp(arg_ls[0],arg_ls);
/*after this it does't execute rest of program because this program is replaced by another program*/

	printf("hello,hi,bye,bye");
	return 0;
}
/*pid remains same even if program is replaced*/
/*THIS FILE IS IN ASSOCIATION WITH exec1.c */
