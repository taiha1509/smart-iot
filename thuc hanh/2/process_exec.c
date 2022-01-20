#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>

int main()
{
	printf("Hello\n");
	execlp("ps", "ps", "ax", 0);
	printf("Done\n");
}
