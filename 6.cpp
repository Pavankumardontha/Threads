/*Get return value from a thread */


#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <time.h>

/* We use the join method to do this. We have passed the second argument as NULL in the previous programs. But this second argument is 
actually used to get the return value from the thread function. Here we will write a simple function to roll dice. it will roll the dice the 
return the result. The second argument in the join function takes double pointer void**. We have returned a void pointer void* from the function 
in the previous examples of our code. Lets say we have computed the value in our function.We need to pass this value to the main function 
thread. how to do this ? Here we will return the pointer of the value variable. But this is not correct because , after the function is 
completed its execution, the memory is deallocated and thus we cannot pass the pointer of the value variable to the main thread from the function.
Instead we have to allocate the memory manually to store this value, send it to the main funciton and then deallocate this in the main function.
This is the procedure we follow.The void pointer can be anything and we will cast it depending on the datatype we are trying to return from the
function. */

void* roll_dice() 
{
    int value = (rand() % 6) + 1;
    int* result = malloc(sizeof(int)); //to store the result 
    *result = value; //assigning the value to the result 
    // printf("%d\n", value);
    printf("Thread result: %p\n", result);
    return (void*) result; //returning the result to the main thread
}

int main(int argc, char* argv[]) 
{
    int* res; //to store the return value from the roll_dice function
    srand(time(NULL));
    pthread_t th;
    if (pthread_create(&th, NULL, &roll_dice, NULL) != 0) {
        return 1;
    }
    if (pthread_join(th, (void**) &res) != 0) {
        return 2;
    }
    printf("Main res: %p\n", res);
    printf("Result: %d\n", *res);
    free(res); //we have to deallocate the res memory. Both res(in main function) and result(in the roll_dice function) will point to the same location. !!!! 
    return 0;
}
/* We are deallocating a variable inside the main function that was cereated inside the roll_dice function. Usually we want to allocate and deallocate the same place
of memory in the same function. We dont want other functions to deallocate the memory allocated by one function. This practice is not good. */
