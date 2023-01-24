#include<stdio.h>
#include<pthread.h>
#include<unistd.h>


int count = 0;
pthread_mutex_t lock;

void *inc(void *i)
{
	while(1)
	{
        pthread_mutex_lock(&lock);
        count++;
		printf("inc: %d \n",count);
        pthread_mutex_unlock(&lock);
	}
}

void *dec(void *d)
{
	while(1)
	{
        pthread_mutex_lock(&lock);
        count--;
		printf("dec:%d \n",count);
        pthread_mutex_unlock(&lock);
	}
}

int main()
{
	pthread_t id1,id2;
	pthread_attr_t thread_attr;
	pthread_attr_t thread_attr1;
	
	pthread_mutex_init(&lock,NULL);
	pthread_attr_init(&thread_attr);
	pthread_attr_init(&thread_attr1);
	
	pthread_attr_setdetachstate(&thread_attr,PTHREAD_CREATE_DETACHED);
	pthread_create(&id1,&thread_attr,inc,NULL);

	pthread_attr_setdetachstate(&thread_attr1,PTHREAD_CREATE_DETACHED);
	pthread_create(&id2,&thread_attr1,dec,NULL);

	
 	pthread_mutex_destroy(&lock);
 	pthread_attr_destroy(&thread_attr);
 	pthread_attr_destroy(&thread_attr1);
 	
	return 0;	
}
