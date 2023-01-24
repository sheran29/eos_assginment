#include<stdio.h>
#include<sys/types.h>
#include<pthread.h>
#include<unistd.h>
#include<stdlib.h>

int count = 0;
pthread_mutex_t lock;
pthread_mutexattr_t mutexat;

void *inc(void *i)
{
	while(1)
	{
        pthread_mutex_lock(&lock);
        pthread_mutex_lock(&lock);
		printf("inc: %d \n",++count);
        pthread_mutex_unlock(&lock);
        pthread_mutex_unlock(&lock);
	}
}

void *dec(void *d)
{
	while(1)
	{
        pthread_mutex_lock(&lock);
		printf("dec: %d \n",--count);
        pthread_mutex_unlock(&lock);
	}
}

int main()
{
	pthread_t id1,id2;
    printf("Main function\n");
    
	pthread_mutexattr_init(&mutexat);
    pthread_mutexattr_settype(&mutexat,PTHREAD_MUTEX_RECURSIVE);
    pthread_mutex_init(&lock,&mutexat);
    
	pthread_create(&id1,NULL,inc,NULL);
	sleep(0.5);
	pthread_create(&id2,NULL,dec,NULL);
	sleep(0.5);
	
	pthread_join(id1,NULL);
	pthread_join(id2,NULL);
	
    pthread_mutex_destroy(&lock);
    
	pthread_exit(NULL);
	return 0;	
}
