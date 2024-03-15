#include <stdio.h>
#include <stdlib.h>

// queue implementation in c using linked list
// #define MAX_SIZE 10;
struct node {
    int data;
    struct node *next;
};
// insertion will be done from rear end , and deletion will be done from front end
struct node *front = NULL;
struct node *rear = NULL;

// [ front  ..............rear ]
void enqueue(int val) {
    // add val to the rear/last of the queue side of the queue
    struct node *newnode;
    newnode = (struct node *)(malloc(sizeof(struct node)));
    newnode->data = val;
    newnode->next = NULL;

    if (front == NULL && rear == NULL) {
        front = rear = newnode;
    } else {
        rear->next = newnode;
        rear = newnode;
    }
}

void dequeue() {
    struct node *newnode = front;
    // delete element from front and move front to next element
    // check if queue is empty or not
    if (front == NULL) {
        printf("Queue is empty\n");
    } else {
        front = front->next;
        free(newnode);
    }
}
void print() {
    struct node *ptr = front;
    while (ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
}

int main() {
    enqueue(5);
    enqueue(15);
    enqueue(10);
    print();
    dequeue();
    printf("\n");
    print();
    return 0;
}