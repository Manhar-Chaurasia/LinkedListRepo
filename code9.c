#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};

struct Node *addToEmpty(int data)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = temp;
    return temp;
}

struct Node *addToBeg(struct Node *tail, int data)
{
    struct Node *newp = (struct Node *)malloc(sizeof(struct Node));
    newp->data = data;
    newp->next = tail->next;
    tail->next = newp;
    return tail;
}

void Print(struct Node *tail)
{
    struct Node *p = tail->next;
    do
    {
        printf("%d  ", p->data);
        p = p->next;
    } while (p != tail->next);
}
int main()
{
    struct Node *tail;
    tail = addToEmpty(45);
    tail = addToBeg(tail, 34);
    Print(tail);
    // to print node one by one use addToEmpty func, put value in it and call print func for every addToempty call
}
