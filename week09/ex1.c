#include <stdio.h>
#include <stdlib.h>

#define number_of_frames 10
#define FALSE 0
#define TRUE 1
#define INITIAL_SIZE 100


typedef struct frame {
    unsigned char referenced;
    unsigned int lifespan;
    int number;
} frame;

typedef struct paging_system {
    frame **frames;
} paging_system;

int fill_page(paging_system *system, int number);

paging_system *initialise() {
    paging_system *system = (paging_system *) malloc(sizeof(paging_system));
    system->frames = (frame **) malloc(sizeof(frame) * number_of_frames);
    for (int i = 0; i < number_of_frames; ++i) {
        system->frames[i] = NULL;
    }
    return system;
}

int get_page(paging_system *system, int number) {
    int found = FALSE;
    for (int i = 0; i < number_of_frames; ++i) {
        frame *current_frame = system->frames[i];
        if (current_frame != NULL) {
            if (current_frame->number == number) {
                found = TRUE;
                current_frame->referenced = 1;
                current_frame->lifespan = (current_frame->lifespan >> 1u) + (1u << (sizeof(char) - 1));
            } else {
                current_frame->referenced = 0;
                current_frame->lifespan = current_frame->lifespan >> 1u;
            }
        }
    }
    if (!found) {
        fill_page(system, number);
    }
    return !found;
}

int fill_page(paging_system *system, int number) {
    frame *lowest = system->frames[0];
    for (int i = 0; i < number_of_frames; ++i) {
        if (system->frames[i] == NULL) {
            system->frames[i] = (frame *) malloc(sizeof(frame));
            system->frames[i]->number = number;
//TODO:bug
            system->frames[i]->lifespan = 1u << (sizeof(char) - 1);
            system->frames[i]->referenced = 1;
            return 0;
        } else {
            if (lowest->lifespan > system->frames[i]->lifespan) {
                lowest = system->frames[i];
            }
        }
    }
    lowest->number = number;
    lowest->lifespan = 0;
    lowest->referenced = 1;
    return 0;
}

int main(void) {
    paging_system *system = initialise();

    int size = INITIAL_SIZE;
    int *a = (int *) malloc(size * sizeof(int));
    int n = 0;
    FILE *fp;
    int c;
    fp = fopen("Lab 09 input.txt", "r");

    while (fscanf(fp, "%d", &c) == 1) {
        a[n] = c;
        n++;
        if (n >= size) {
            size += INITIAL_SIZE;
            a = (int *) realloc(a, size * sizeof(int));
        }
    }

    double miss = 0;
    for (int i = 0; i < n; ++i) {
        miss += get_page(system, a[i]);
    }
    printf("%f%%\n", ((n - miss) / n) * 100);

}