
#include<unistd.h>
#include<sys/types.h>
#include<signal.h>
#include<stdio.h>

int main() {
        pid_t pid = getpid();
        printf("Current pid: %d", (int)pid);
        kill(pid, SIGSTOP);
        printf("Done");

        return 0;

}



