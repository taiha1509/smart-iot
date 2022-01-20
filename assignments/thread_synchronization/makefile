CC=gcc

all: mutexDemo.c semaphore.c
	$(CC) mutexDemo.c -o mutex -lpthread
	$(CC) semaphore.c -o semaphore -lpthread

clear: 
	rm mutex
	rm semaphore