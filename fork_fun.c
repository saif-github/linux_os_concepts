#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>

int main()
{
	printf("one \n");
	fork();			//fork creats two process
	printf("two \n");
	return 0;
}
