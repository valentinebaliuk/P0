
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
 
void* helloWorld1(void *args) {
    printf("Hello from thread1!\n");
    fflush(stdout);
    return 0;
}
void* helloWorld2(void *args) {
    printf("Hello from thread2!\n");
    fflush(stdout);
    return 0;
}
 
int main() {
    int status; 
    pthread_t thread1,thread2;
    printf("Hello from main!\n");
    fflush(stdout);
    status = pthread_create(&thread1, NULL, helloWorld1, NULL);
    if(status!=0){
    printf("Creating the first thread\n");
    return -1;
    }
    status = pthread_create(&thread2, NULL, helloWorld2, NULL);
    if(status!=0){
    printf("Creating the second thread\n");
    return -1;
    }
    status=pthread_join(thread1,NULL);
    if(status!=0){
    printf("Joining the first thread\n");
    return -1;
    }
    status=pthread_join(thread2,NULL);
    if(status!=0){
    printf("Joining the second thread\n");
    return -1;
    }
    printf("Hello from main!\n");
    fflush(stdout);
    getchar();
    return 0;
}
