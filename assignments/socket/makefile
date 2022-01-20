CC=gcc
all: client2.c server2.c multi_thread_server.c
	$(CC) client2.c -o client2
	$(CC) server2.c -o server2
	$(CC) -pthread -o multi_thread_server multi_thread_server.c
clear:
	rm client2
	rm server2 
	rm multi_thread_server
