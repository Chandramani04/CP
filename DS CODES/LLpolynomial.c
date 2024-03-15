#include <stdio.h>
#include <stdlib.h>

struct node {
    int c, p;
    struct node *next;
};

void create(int co, int pw, struct node **poly) {
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->c = co;
    newnode->p = pw;
    newnode->next = NULL;

    struct node *ptr = *poly;
    if (ptr == NULL) {
        *poly = newnode;
    } else {
        while (ptr->next != NULL) {
            ptr = ptr->next;
        }
        ptr->next = newnode;
    }
}

struct node *rec(struct node *p1, struct node *p2) {
    if (p1 == NULL) return p2;
    if (p2 == NULL) return p1;
    struct node *ans = (struct node *)malloc(sizeof(struct node));
    if (p1->p == p2->p) {
        ans->c = p1->c + p2->c;
        ans->p = p1->p;
        ans->next = rec(p1->next, p2->next);
    } else if (p1->p > p2->p) {
        ans->c = p1->c;
        ans->p = p1->p;
        ans->next = rec(p1->next, p2);
    } else {
        ans->c = p2->c;
        ans->p = p2->p;
        ans->next = rec(p1, p2->next);
    }
    return ans;
}
void print(struct node *head) {
    struct node *ptr = head;
    while (ptr != NULL) {
        printf("%dx^%d", ptr->c, ptr->p);
        if (ptr->next != NULL) {
            printf("+ ");
        }
        ptr = ptr->next;
    }
    printf("\n");
}
int main() {
    struct node *p1 = NULL, *p2 = NULL;

    create(5, 2, &p1);
    create(4, 1, &p1);
    create(2, 0, &p1);
    printf("First polynomial: ");
    print(p1);

    create(2, 2, &p2);
    create(3, 1, &p2);
    create(1, 0, &p2);
    printf("Second polynomial: ");
    print(p2);

    struct node *ans = rec(p1, p2);
    printf("Sum of the polynomials: ");
    print(ans);

    return 0;
}