#include<stdio.h>// standard input / output functions
#include <unistd.h>
#include <time.h>
int main(int argc, char** argv)
{
	printf("\nMa tien trinh dang chay : %d", (int)getpid());
	printf("\nMa tien trinh cha : %d", (int)getppid());
	while (1)
	{
		printf("\nRunning…");
		sleep(2);
	}
}
