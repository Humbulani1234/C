
#include <stdio.h>
#include <pthread.h>

void *thread_function(void *arg) {

    printf("Hello from the thread\n");
    sleep(30);
    return NULL;
}

int main() {

    // Multiple threads

    pthread_t thread_id1, thread_id2, thread_id3;

    pthread_create(&thread_id1, NULL, thread_function, NULL);
    pthread_create(&thread_id2, NULL, thread_function, NULL);
    pthread_create(&thread_id2, NULL, thread_function, NULL);

    printf("Hello from the main thread\n");

    pthread_join(thread_id1, NULL);
    pthread_join(thread_id2, NULL);
    pthread_join(thread_id3, NULL);

    // Single thread

    // pthread_t thread_id;

    // pthread_create(&thread_id, NULL, thread_function, NULL);

    // printf("Hello from the main thread\n");

    // pthread_join(thread_id, NULL);

    return 0;

}