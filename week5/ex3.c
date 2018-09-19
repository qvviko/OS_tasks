#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>


#define N 8
#define TRUE 1

int buffer[N];
pthread_t pr_cons[2];
int status[2];
int count = 0;

void *producer(void *);

void *consumer(void *);

void *sleep_thread(void);

void *wakeup_thread(void *);

void *producer(void *id) {
    while (TRUE) {
        if (count == N) {
            sleep_thread();
        }
        count++;
        printf("count increased %d\n", count);

        if (count == 1) wakeup_thread((void *) 1);
    }
}

void *consumer(void *id) {
    while (TRUE) {
        if (count == 0) {
            sleep_thread();
        }
        count--;
        printf("count decresed %d\n", count);


        if (count == N - 1) wakeup_thread((void *) 0);
    }
}

void *sleep_thread(void) {
    printf("Sleep\n");
    pause();
}

void *wakeup_thread(void *id) {
    if ((long) id == 0) {
        printf("Continue %d\n", 0);
        pthread_kill(pr_cons[0], SIGCONT);
    } else {
        printf("Continue %d\n", 1);
        pthread_kill(pr_cons[1], SIGCONT);
    }
}

int main(void) {
    pthread_create(pr_cons, NULL, producer, NULL);
    pthread_create(pr_cons + 1, NULL, consumer, NULL);

    pthread_join(pr_cons[0], NULL);
    pthread_join(pr_cons[1], NULL);
}