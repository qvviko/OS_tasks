#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define N_THREADS 10

void *print_thread(void *id) {
    printf("I'm thread №%d\n", (int) id);
    pthread_exit(NULL);
}

int main(int argc, char *argv[]) {
    pthread_t threads[N_THREADS];
    int status, i;
    printf("Main program begins parallel case\n");
    for (i = 0; i < N_THREADS; i++) {
        printf("Main program creates thread  №%d\n", i);
        status = pthread_create(&threads[i], NULL, print_thread, (void *) i);
        if (status != 0) {
            exit(EXIT_FAILURE);
        }
    }
    // Wait until previous threads are finished
    pthread_join(threads[N_THREADS - 1], NULL);
    printf("Main program begins sequential case\n");
    for (i = 0; i < N_THREADS; i++) {
        printf("Main program creates thread  №%d\n", i);
        status = pthread_create(&threads[i], NULL, print_thread, (void *) i);
        pthread_join(threads[i], NULL);
        if (status != 0) {
            exit(status);
        }
    }
}