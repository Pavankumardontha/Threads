/* Passing arguments to threads.*/

/*
Problem :- create 10 threads , each taking a unique prime from the primes array and print on the screen.
*/




#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

int primes[10] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29 }; //primes array 

void* routine(void* arg) //passing void ointer argument 
{
    sleep(1);
    int index = *(int*)arg; //converting into integer pointer and calculating its value
    printf("%d ", primes[index]);
    free(arg);
}

int main(int argc, char* argv[]) 
{
    pthread_t th[10];
    int i;
    //creating 10 threads and executing it 
    for (i = 0; i < 10; i++) 
    {
        int* a = malloc(sizeof(int)); //we will allocate the space here and deallocate it in the thread function 
        *a = i;
        //we will pass the index to the create_function
        if (pthread_create(&th[i], NULL, &routine, a) != 0) 
        {
            perror("Failed to created thread");
        }
    }
    
    for (i = 0; i < 10; i++) 
    {
        if (pthread_join(th[i], NULL) != 0) 
        {
            perror("Failed to join thread");
        }
    }
    
    return 0;
}
