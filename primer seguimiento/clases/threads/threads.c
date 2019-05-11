#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *task1()
{
    printf("Hilo 1");
}

void *task2()
{
    printf("Hilo 2");
}

int main()
{
    pthread_t hilo1, hilo2;
    pthread_create(&hilo1, NULL, &task1, NULL);
    pthread_create(&hilo2, NULL, &task2, NULL);

    pthread_join(hilo1,NULL);
    pthread_join(hilo2,NULL);

    return 0;
}
