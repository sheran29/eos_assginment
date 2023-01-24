#include<stdio.h>
#include<sys/types.h>
#include<pthread.h>
#include<unistd.h>
#include<stdlib.h>

int count = 0;

void *inc()
{
	while(1)
	{
		printf("inc: %d \n",++count);
	}
}

void *dec()
{
	while(1)
	{
		printf("dec: %d \n",--count);
	}
}

int main()
{
	pthread_t id1,id2;
	pthread_attr_t thread_attr;
	pthread_attr_init(&thread_attr);
	pthread_attr_setdetachstate(&thread_attr,PTHREAD_CREATE_DETACHED);
	pthread_create(&id1,&thread_attr,inc,NULL);
	
	pthread_create(&id2,&thread_attr,dec,NULL);
	sleep(1);
	pthread_attr_destroy(&thread_attr);
 	pthread_join(id1,NULL);
	pthread_join(id2,NULL);
	pthread_exit(NULL);
//	return 0;	
}


