#include <pthread.h>
#include <stdio.h>

#define N 8
#define TRUE 1

pthread_t pr_cons[2];
char is_sleeping[2];
int count = 0;

void *producer(void *);

void *consumer(void *);

void *sleep_thread(void *);

void *wakeup_thread(void *);

void *producer(void *id) {
    while (TRUE) {
        if (count == N) {
            sleep_thread(id);
        }

        count++;
        printf("Count increased by producer: %d\n", count);

        if (count == 1 && is_sleeping[1 - (long) id] == 1) wakeup_thread((void *) 1);
    }
}

void *consumer(void *id) {
    while (TRUE) {
        if (count == 0) {
            sleep_thread(id);
        }
        count--;
        printf("Count decreased by consumer: %d\n", count);

        if (count == N - 1 && is_sleeping[1 - (long) id] == 1) wakeup_thread((void *) 0);
    }
}

void *sleep_thread(void *id) {
    if ((long) id) {
        printf("Consumer is sleeping\n");
    } else {
        printf("Producer is sleeping\n");
    }
    is_sleeping[(long) id] = 1;
    while (is_sleeping[(long) id] == 1) {
    }
}

void *wakeup_thread(void *id) {
    if ((long) id) {
        printf("Consumer awoke\n");
    } else {
        printf("Producer awoke\n");
    }
    is_sleeping[(long) id] = 0;
}

int main(void) {
    pthread_create(pr_cons, NULL, producer, (void *) 0);
    is_sleeping[0] = 0;
    pthread_create(pr_cons + 1, NULL, consumer, (void *) 1);
    is_sleeping[1] = 0;

    while (TRUE) {
        //Wait until race begins...
    }
}