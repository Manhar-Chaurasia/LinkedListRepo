//inserting node at nth position in doubly linked list
#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};
struct Node *head;
void Insert(int data, int n)
{
    struct Node *newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=data;
    newNode->prev=NULL;
    newNode->next=NULL;
    if (n==1)
    {
        head=newNode;
        return;
    }
    struct Node *temp=head;
    for (int i = 0; i < n-2; i++)
    {
        temp=temp->next;
    }
    newNode->next=temp->next;
    temp->next=newNode;
    newNode->prev=temp;
    temp->next->prev=newNode;
}

void Print()
{
    struct Node *temp=head;
    printf("Printing: ");
    while (temp!=NULL)
    {
        printf("%d  ",temp->data);
        temp=temp->next;
    }
}

int main()
{
    head=NULL;    
    Insert(2,1);
    Insert(3,2);
    Insert(4,3);
    Print();
}
