#include <stdio.h>
#include <stdlib.h>

// stack implementation in c

struct node {
    int data;
    struct node *next;
};
struct node *top = NULL;
void push(int val) {
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = val;
    if (top == NULL) {
        newnode->next = NULL;
    } else {
        newnode->next = top;
    }
    top = newnode;
}
int pop() {
    struct node *temp = top;
    int val = temp->data;
    top = top->next;
    free(temp);
    return val;
}
int main() {
    return 0;
}