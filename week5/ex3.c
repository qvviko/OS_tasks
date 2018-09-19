#include <pthread.h>
#include <stdio.h>

#define N 8
#define TRUE 1
int buffer[N];
pthread_t pr_cons[2];
int status[2];
int count = 1;

void *producer(void *);

void *consumer(void *);

void *sleep(void);

void *wakeup(void *);

void *producer(void *id) {
    while (TRUE) {
        if (count == N) {
            status[0] = 0;
            printf("Status %d changed to %d, count = %d\n", 0, 0, count);
            sleep();
        }
        count++;
        printf("count increased %d\n", count);
        if (count == 1) wakeup((void *) 1);
    }
}

void *consumer(void *id) {
    while (TRUE) {
        if (count == 0) {
            status[1] = 0;
            printf("Status %d changed to %d, count = %d\n", 1, 0, count);
            sleep();
        }
        count--;
        printf("count decresed %d\n", count);
        if (count == N - 1) wakeup((void *) 0);
    }
}

void *sleep(void) {
    pthread_exit(NULL);
}

void *wakeup(void *id) {
    if ((long) id == 0 && status[0] == 0) {
        pthread_create(pr_cons, NULL, producer, NULL);
        status[0] = 1;
        printf("Status %d changed to %d, count = %d\n", 0, 1, count);
    } else if (status[1] == 0) {
        pthread_create(pr_cons + 1, NULL, consumer, NULL);
        status[1] = 1;
        printf("Status %d changed to %d, count = %d\n", 1, 1, count);
    }
}

int main(void) {
    pthread_create(pr_cons, NULL, producer, NULL);
    status[0] = 1;
    printf("Status %d changed to %d, count = %d\n", 0, 1, count);
    pthread_create(pr_cons + 1, NULL, consumer, NULL);
    status[1] = 1;
    printf("Status %d changed to %d, count = %d\n", 1, 1, count);
    while (TRUE) {
        pthread_join(pr_cons[0], NULL);
        pthread_join(pr_cons[1], NULL);
    }
}