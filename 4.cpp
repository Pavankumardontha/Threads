/*MUTEX*/

#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>


/*
Mutex is sort of a lock around a section of code. If one thread is running the code section that is bounded by mutex then no other thread can execute that section of
the code. Only one thread can execute this section at a time. All the other threads need to wait till the execution of one thread completes. Mutex is used to avoid 
race conditions. 
*/
int mails = 0;
pthread_mutex_t mutex; //declaring a mutex variable 

void* routine() 
{
    for (int i = 0; i < 10000000; i++) 
    {
        pthread_mutex_lock(&mutex);
        mails++;
        pthread_mutex_unlock(&mutex);
    }
}

int main(int argc, char* argv[]) 
{
    pthread_t p1, p2, p3, p4;
    pthread_mutex_init(&mutex, NULL); // initialising the mutex
    if (pthread_create(&p1, NULL, &routine, NULL) != 0) 
    {
        return 1;
    }
    if (pthread_create(&p2, NULL, &routine, NULL) != 0) 
    {
        return 2;
    }
    if (pthread_create(&p3, NULL, &routine, NULL) != 0) 
    {
        return 3;
    }
    if (pthread_create(&p4, NULL, &routine, NULL) != 0) 
    {
        return 4;
    }
    if (pthread_join(p1, NULL) != 0) 
    {
        return 5;
    }
    if (pthread_join(p2, NULL) != 0) 
    {
        return 6;
    }
    if (pthread_join(p3, NULL) != 0) 
    {
        return 7;
    }
    if (pthread_join(p4, NULL) != 0) 
    {
        return 8;
    }
    pthread_mutex_destroy(&mutex); //destroying the mutex
    printf("Number of mails: %d\n", mails);
    return 0;
}
