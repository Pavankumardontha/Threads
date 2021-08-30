/*
Thread is used to execute a function. 
*/

#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void* routine()
{
    cout<<"Test from threads"<<endl;
}

int main()
{
    //define the thread variables where the API can store some information about the threads 
    pthread_t t1;
    
    //create a thread 
    if(pthread_create(&t1,NULL,&routine,NULL)!=0) //we have also passed the function address 
    return 1;
    //similar to processes,We will wait for the thread to complete its execution.We dont want the process to finish its execution before the threads inside it complete their execution  
    if(pthread_join(t1,NULL)!=0)//similar to wait() function but for threads we use join()
    return 2;
    /*Threads always execute in parallel.We cannot always create how many threads we want.*/
    return 0;
}
