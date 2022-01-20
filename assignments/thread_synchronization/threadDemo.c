#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

void *print_hello(void* unused) {
    printf("hello linux programming\n");
}

int main() {
    pthread_t thread_t;
    printf("Begining ...\n");
    pthread_create(&thread_t, 0, &print_hello, 0); 
    printf("Done\n");
    return 0;
}