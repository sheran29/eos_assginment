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
		sem_wait(&sem_lock);
		sem_wait(&sem_lock);
		count++;
		printf("Inc: %d \n",count);
		sem_post(&sem_lock);
		sem_post(&sem_lock);
		sem_post(&sem_lock);
	}
}

void *dec(void *d)
{
	while(1)
	{
        sem_wait(&sem_lock);
        count--;
		printf("Dec:%d \n",count);
        sem_post(&sem_lock);
	}
}

int main()
{
	pthread_t id1,id2;
	
    printf("Main function\n");
    sem_init(&sem_lock,0,4);   
    
	pthread_create(&id1,NULL,inc,NULL);
	pthread_create(&id2,NULL,dec,NULL);
	
 	pthread_join(id1,NULL);
	pthread_join(id2,NULL);
	
	sem_destroy(&sem_lock);
	return 0;	
}
