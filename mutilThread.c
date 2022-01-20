#include <pthread.h>
#include <stdio.h>
#include<unistd.h>
void *print_xs (void* unused)
{
while (1)
{
	printf("0");
}
return 0;
}
int main ()
{
pthread_t thread_id;
pthread_create (&thread_id, 0, &print_xs, 0);
while (1)
{
	printf("1");
}
return 0;
}
