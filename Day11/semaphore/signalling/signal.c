#include<stdio.h>
#include<sys/types.h>
#include<pthread.h>
#include<unistd.h>
#include<stdlib.h>
#include<semaphore.h>

int count = 0;

sem_t sem_lock;
sem_t sem_lockb;
int a,b;
void *inc(void *i)
{
	// while(1)
	// {
        sem_wait(&sem_lockb);
        printf("Enter value of a & b: ");
        scanf("%d%d",&a,&b);
        sem_post(&sem_lock);
        
	// }
}

void *dec(void *d)
{
	// while(1)
	// {
        sem_wait(&sem_lock);
        int res = a + b;
		printf("Addition: %d \n",res);
        sem_post(&sem_lockb);
	// }
}

int main()
{
	pthread_t id1,id2;
    printf("Main function\n");
    
    sem_init(&sem_lock,0,0);
    sem_init(&sem_lockb,0,1);   
    
	pthread_create(&id1,NULL,inc,NULL);
	pthread_create(&id2,NULL,dec,NULL);
	
 	pthread_join(id1,NULL);
	pthread_join(id2,NULL);
	
    sem_destroy(&sem_lock);
    sem_destroy(&sem_lockb);
    
	pthread_exit(NULL);
	return 0;	
}
