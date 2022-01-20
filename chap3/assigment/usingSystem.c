#include<stdlib.h>
#include<stdio.h>
int main()
{
	printf("Current process\n");
	printf("creating new process using system function\n");
	system("echo Hello world");
	printf("done\n");

	return 0;

}
