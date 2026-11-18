#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};
struct Node *head = NULL;

struct Node *newNode(int x) {
    struct Node *n = (struct Node *)malloc(sizeof(struct Node) );
    n->data = x;
    n->next = NULL;
    return n;
}

void insertBegin(int x) {
    struct Node *n = newNode(x);
    n->next = head;
    head = n;
}
void insertEnd(int x) {
    struct Node *n = newNode(x), *t = head;
    if (head == NULL) { head = n; return; }
    while (t->next != NULL)
        t = t->next;
    t->next = n;
}

void deleteValue(int x) {
    struct Node *t = head, *prev = NULL;
    while (t != NULL && t->data !=x) {
        prev = t;
        t = t->next;
    }
    if (t == NULL) {printf("%d not found\n",x); return; }
    if (prev == NULL) head = t->next;
    else prev->next = t ->next;
    free(t);
}

void display() {
    struct Node *t = head;
    while (t != NULL) {
        printf("%d -> ", t->data);
        t = t->next;
    }
    printf("NULL\n");
}

int main() {
    insertBegin(20); insertBegin(10);
    insertEnd(30); insertEnd(40);
    printf("List        : "); display();
    deleteValue(30);
    printf("After del 30: "); display();
    deleteValue(10);
    printf("After del 10: "); display();
    deleteValue(99);
    return 0;
}