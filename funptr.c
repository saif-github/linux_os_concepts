#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>

void func();
void display();

/*function pointer takes address of the function and call that function through it self */
main()
{
	void (*funptr)();
	funptr=display;
	funptr();				//insted of function we have call pointer which have address of that function
	funptr=func;
	funptr();
}

void func()
{
	int a=5;
	while(a!=0)
	{
	printf("hi i'm linux how can i help u\n");
	a--;
	}
}

void display()
{
	printf("hi linux, \n");
}

