#include <stdio.h>
#include <pthread.h>

#define NUM_INCREMENTS 50000

int counter = 0;
pthread_mutex_t lock;
void* increment(void* arg) {
    for (int i = 0; i < NUM_INCREMENTS; i++) {
        pthread_mutex_lock(&lock);
        counter++;
        pthread_mutex_unlock(&lock);
    }
    return NULL;
}

int main() {
    pthread_t t1, t2;
    pthread_mutex_init(&lock, NULL);
    pthread_create(&t1, NULL, increment, NULL);
    pthread_create(&t2, NULL, increment, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    printf("Expected Final Counter: 100000\n");
    printf("Actual Final Counter: %d\n", counter);

    return 0;
}
