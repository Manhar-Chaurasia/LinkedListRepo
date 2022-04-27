#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node *head;
struct Node *GetNewNode(int x)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = x;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}
void InsertAtHead(int x)
{
    struct Node *newNode = GetNewNode(x);
    if (head == NULL)
    {
        head = newNode;
        return;
    }
    head->prev = newNode;
    newNode->next = head;
    head = newNode;
}

void ReversePrint()
{
    struct Node *temp = head;
    if (temp == NULL)
    {
        return; //empty list, exit
    }
    while (temp->next != NULL) //going to last node
    {
        temp = temp->next;
    }
    printf("Reverse: ");
    while (temp != NULL) //traversing backward using prev pointer
    {
        printf("%d  ", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}
void Print()
{
    struct Node *temp = head;
    printf("Forward: ");
    while (temp != NULL)
    {
        printf("%d  ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
int main()
{
    head = NULL;
    InsertAtHead(2); Print(); ReversePrint();
    InsertAtHead(4); Print(); ReversePrint();
    InsertAtHead(6); Print(); ReversePrint();
}