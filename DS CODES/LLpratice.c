

#include <stdio.h>
#include <stdlib.h>

// creating a struct for linked list

struct node {
    // all the data value will be assigned normally
    int data;
    // all the pointer values will be assigned in different way
    // all pointers will only be initialized
    struct node *next;
    struct node *prev;
};

// create a node with data
struct node *createNode(int val) {
    // how to create a temporary node
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}

// print entire linkedlist
void print(struct node *head) {
    // temp pointer
    struct node *temp = head;
    while (temp->next != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;  // increase the pointer to next position
    }
}

// insert node at beginning
void insert_begin(struct node **head, int val) {
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = val;
    temp->next = *head;
    *head = temp;
}

// insert at middle
void insert_middle(struct node **head, int val, int pos) {
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = val;
    newnode->next = NULL;

    struct node *ptr = *head;
    for (int i = 1; i < pos; i++) {
        ptr = ptr->next;
    }

    newnode->next = ptr->next;
    ptr->next = newnode;
}

// insert at end
void insert_end(struct node **head, int val) {
    struct node *ptr = *head;
    while (ptr->next != NULL) {
        ptr = ptr->next;
    }

    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = val;
    newnode->next = NULL;
    ptr->next = newnode;
}

// delete at beginning
void delete_beginning(struct node **head) {
    struct node *ptr = *head;
    *head = ptr->next;
    free(ptr);
}

// delete at end

void delete_end(struct node **head) {
    struct node *ptr = *head;
    while (ptr->next->next != NULL) {
        ptr = ptr->next;
    }
    struct node *temp = ptr->next;
    ptr->next = NULL;
    free(temp);
}

// delete at kth pos
void delete_random(struct node **head, int k) {
    struct node *ptr = *head;
    for (int i = 1; i < k; i++) {
        ptr = ptr->next;
    }

    struct node *temp = ptr->next;
    ptr = ptr->next->next;
    free(temp);
}

int main() {
    return 0;
}
