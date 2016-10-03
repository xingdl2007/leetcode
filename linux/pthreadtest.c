#include <pthread.h>
#include <stdio.h>

#define NUM_OF_THREADS 10

void *print_hello_world(void *id) {
    printf("Hello world. Greeting from thread %p\n",id);
    pthread_exit(NULL);
}

int main(int argc, char*argv[]) {
    pthread_t threads[NUM_OF_THREADS];
    int status, i;
    
    for(i=0; i< NUM_OF_THREADS; i++) {
        status = pthread_create(&threads[i],NULL,print_hello_world,(void*)i);
        if(status !=0 ) {
            printf("Oops, pthread_create return error code %d\n",status);
            exit(-1);
        }
    }
    exit(NULL);
}
