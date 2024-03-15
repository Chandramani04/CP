#include <stdio.h>
#include <stdlib.h>
// implement a circular queue using linked list
// har jagah only last me rear->next = front krna hai 
struct node {
    int data;
    struct node *next;
};
//[front ..............rear ]
struct node *front = NULL, *rear = NULL;

// insert an element in the queue
void enqueue(int val) {
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = val;
    newnode->next = NULL;

    // check if queue is full or not
    if (front == NULL && rear == NULL) {
        front = rear = newnode;
    } else {
        rear->next = newnode;
        rear = newnode;
    }
    rear->next = front;
}
void dequeue() {
    struct node *temp = front;
    if (front == NULL) {
        printf("Queue is empty\n");
    } else {
        front = front->next;
        free(temp);
        rear->next = front;
    }
}
void display() {
    struct node *temp = front;
    if (front == NULL && rear == NULL) {
        printf("Queue is empty\n");
    } else {
        while (temp->next != front) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("%d ", temp->data);
    }
}

int main() {
    enqueue(5);
    enqueue(10);
    enqueue(15);
    display();
    printf("\n");
    dequeue();
    display();

    return 0;
}