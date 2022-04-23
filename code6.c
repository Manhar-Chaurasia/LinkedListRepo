// reversing linked list using recursion(actual reverse)
#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
struct Node *head;

void Insert(int data)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = head;
    head = temp;
}

void Print()
{
    struct Node *temp = head;
    while (temp != NULL)
    {
        printf("%d  ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void Reverse(struct Node *p)
{
    if (p->next == NULL)
    {
        head = p;
        return;
    }
    Reverse(p->next);
    struct Node *q = p->next;
    q->next = p;
    p->next = NULL;
}

int main()
{
    head = NULL;
    Insert(2);
    Insert(3);
    Insert(4);
    Insert(5);
    Print();
    Reverse(head);
    Print();
}