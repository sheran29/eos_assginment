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
  	
    pthread_mutex_init(&lock,NULL);

	pthread_create(&id1,NULL,inc,NULL);
	pthread_create(&id2,NULL,dec,NULL);
	
   	pthread_join(id1,NULL);
	pthread_join(id2,NULL);
	
 	pthread_mutex_destroy(&lock);

	return 0;	
}
