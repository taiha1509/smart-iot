#include<pthread.h>
#include<stdio.h>

struct char_print_params {
	char character;
	int count;
};

void* char_print(void *params) {
	struct char_print_params* p = (struct char_print_params*) params;
	printf("%d", p->count);
	
	for(int i = 0; i < p->count; ++i){
		printf("%c", p->character);
	}
	
	return 0;
}
 
int main()
{
	printf("run");
	pthread_t thread1_id;
	pthread_t thread2_id;
	struct char_print_params thread1_params;
	struct char_print_params thread2_params;
	
	thread1_params.character = '0';
	thread1_params.count = 10;
	
	pthread_create(&thread1_id, 0, &char_print, &thread1_params);

	// printf("%ld",thread1_id);
	
	// thread2_params.character = '1';
	// thread2_params.count = 11;
	
	// pthread_create(&thread2_id, 0, &char_print, &thread2_params);
	
	return 0;
}
 
 
