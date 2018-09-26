#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct LinkedList {
    Node *head;
} LinkedList;

int insert_node(LinkedList *list, int data, int index);

LinkedList *create_linked_list();

int delete_node(LinkedList *list, int index);

Node *create_node(int data);

void print_list(LinkedList *);

Node *create_node(int data) {
    Node *new_node = (Node *) malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

LinkedList *create_linked_list() {
    LinkedList *new_list = (LinkedList *) malloc(sizeof(LinkedList));
    new_list->head = NULL;
    return new_list;
}


void print_list(LinkedList *list) {
    if (list->head == NULL) {
        printf("Empty list\n");
    } else {
        Node *current = list->head;
        while (current->next != NULL) {
            printf("%d ", current->data);
            current = current->next;
        }
        printf("%d\n", current->data);
    }
}

int insert_node(LinkedList *list, int data, int index) {
    // Will insert in the index position, or in the end, if index is bigger then the length of the array
    if (index < 0) {
        printf("Error. Index is negative\n");
        return -1;
    }
    Node *node = create_node(data);

    if (list->head == NULL) {
        list->head = node;
    } else {
        Node *current = list->head;
        Node *previous = NULL;
        int i = 0;
        while (current->next != NULL && i != index) {
            previous = current;
            current = current->next;
            i++;
        }
        if (index == 0) {
            node->next = list->head;
            list->head = node;
        } else if (i != index && current->next == NULL) {
            current->next = node;
        } else {
            node->next = current;
            previous->next = node;
        }
    }
    return 0;
}

int delete_node(LinkedList *list, int index) {
    //Delete node at index, if index > length do nothing
    if (index < 0) {
        printf("Error. Index is negative\n");
        return -1;
    }
    if (list->head == NULL) {
        printf("Error. List is empty\n");
        return -1;
    } else {
        Node *current = list->head;
        Node *previous = NULL;
        int i = 0;
        while (current->next != NULL && i != index) {
            previous = current;
            current = current->next;
            i++;
        }
        if (index == 0) {
            Node *to_remove = list->head;
            list->head = to_remove->next;
            free(to_remove);
        } else if (i == index) {
            previous->next = current->next;
            free(current);
        } else {
            printf("Error. Index out of range.\n");
            return -1;
        }

    }
    return 0;
}

int main() {
    LinkedList *list = create_linked_list();
    print_list(list);

    printf("Insert 5 position 0\n");
    insert_node(list, 5, 0);
    print_list(list);

    printf("Insert 1 position 0\n");
    insert_node(list, 1, 0);
    print_list(list);

    printf("Insert -1 position 1\n");
    insert_node(list, -1, 1);
    print_list(list);

    printf("Insert 100 position 3\n");
    insert_node(list, 100, 3);
    print_list(list);

    printf("Insert 500 position 500 (out of range, so inserted last)\n");
    insert_node(list, 500, 500);
    print_list(list);

    printf("Insert 50 position 50 (out of range, so inserted last)\n");
    insert_node(list, 50, 50);
    print_list(list);

    printf("Remove element on position 0\n");
    delete_node(list, 0);
    print_list(list);

    printf("Remove element on position 1\n");
    delete_node(list, 1);
    print_list(list);

    printf("Insert 2 position 1\n");
    insert_node(list, 2, 1);
    print_list(list);

    printf("Insert 9 position 1\n");
    insert_node(list, 9, 1);
    print_list(list);

    printf("Remove element on position 0\n");
    delete_node(list, 0);
    print_list(list);

    printf("Remove element on position 0\n");
    delete_node(list, 0);
    print_list(list);

    printf("Remove element on position 3\n");
    delete_node(list, 3);
    print_list(list);

    printf("Remove element on position 0\n");
    delete_node(list, 0);
    print_list(list);

    printf("Remove element on position 0\n");
    delete_node(list, 0);
    print_list(list);

    printf("Remove element on position 5 (out of range, nothing happens)\n");
    delete_node(list, 5);
    print_list(list);

    printf("Remove element on position 0\n");
    delete_node(list, 0);
    print_list(list);

    printf("Remove element on position 0(empty list, nothing happens)\n");
    delete_node(list, 0);

    return 0;
}