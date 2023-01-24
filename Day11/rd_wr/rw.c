#include<stdio.h>
#include<pthread.h>
#include<unistd.h>

pthread_rwlock_t rw_lock;
int a,b;

void *inc(void *i)
{
//	while(1)
	{
        pthread_rwlock_wrlock(&rw_lock);
        printf("Enter value of a & b: ");
        scanf("%d%d",&a,&b);
        pthread_rwlock_unlock(&rw_lock);
        
	}
}

void *dec(void *d)
{
//	while(1)
	{
        pthread_rwlock_rdlock(&rw_lock);
        int res = a + b;
        sleep(1);
		printf("Addition: %d \n",res);
        pthread_rwlock_unlock(&rw_lock);
	}
}

void *thread(void *t)
{
//   while(1)
    {
    pthread_rwlock_rdlock(&rw_lock);
    printf("The values are: %d %d\n",a,b);
    sleep(1);
    pthread_rwlock_unlock(&rw_lock);
    }
}

int main()
{
	pthread_t id1,id2,id3;
    pthread_rwlock_init(&rw_lock,NULL);
	pthread_create(&id1,NULL,inc,NULL);
	pthread_create(&id2,NULL,dec,NULL);
    pthread_create(&id3,NULL,thread,NULL);
 	pthread_join(id1,NULL);
	pthread_join(id2,NULL);
    pthread_join(id3,NULL);
    pthread_rwlock_destroy(&rw_lock);
	pthread_exit(NULL);
	return 0;	
}
