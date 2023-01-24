#include<stdio.h>
#include<sys/types.h>
#include<pthread.h>
#include<unistd.h>
#include<stdlib.h>
#include<semaphore.h>

int count = 0;
sem_t sem_lock;
void *inc(void *i)
{
	while(1)
	{
        sem_wait(&sem_lock);
		printf("inc: %d \n",count++);
        sem_post(&sem_lock);
	}
}

void *dec(void *d)
{
	while(1)
	{
        sem_wait(&sem_lock);
		printf("dec: %d \n",count--);
        sem_post(&sem_lock);
	}
}

int main()
{
	pthread_t id1,id2;
    printf("Main function\n");
    sem_init(&sem_lock,0,1);   
	pthread_create(&id1,NULL,inc,NULL);
	sleep(0.5);
	pthread_create(&id2,NULL,dec,NULL);
	sleep(0.5);
 	pthread_join(id1,NULL);
	pthread_join(id2,NULL);
	pthread_exit(NULL);
	return 0;	
}