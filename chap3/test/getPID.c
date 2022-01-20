#include<stdio.h>
#include<unistd.h>
int main() {
	printf("Process ID is %d\n", (int) getpid());
	printf("Parent process id is %d\n", (int)getppid());
	
	return 0;
}
