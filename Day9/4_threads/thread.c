#include<stdio.h>
#include<pthread.h>
#include<unistd.h>

void *add(void *ad)
{
    printf("Inside Addition\n");
    int a = 10, b = 5;
    int c = a + b;
    sleep(5);
    printf("Addition: %d\n",c);
}

void *sub(void *sb)
{
    printf("Inside Subtraction\n");
    int a = 10, b = 5;
    int c = a - b;
    printf("Subtraction: %d\n",c);
    sleep(5);

}

void *mul(void *ml)
{
    printf("Inside Multiplication\n");
    int a = 10, b = 5;
    sleep(5);
    int c = a * b;
    printf("Multiplication: %d\n",c);
}

void *div(void *dv)
{
    sleep(5);
    printf("Inside Division\n");
    int a = 10, b = 5;
    int c = a / b;
    printf("Division: %d\n",c);
}

int main(void)
{
    printf("\nInside main.\n");
    pthread_t p1,p2,p3,p4;
    sleep(5);
    pthread_create(&p1,NULL,add,NULL);
    pthread_create(&p2,NULL,sub,NULL);
    pthread_create(&p3,NULL,div,NULL);
    pthread_create(&p4,NULL,mul,NULL);

    pthread_join(p1,NULL);
    pthread_join(p2,NULL);
    pthread_join(p3,NULL);
    pthread_join(p4,NULL);

    return 0;
}