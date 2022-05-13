//insert, delete, print node in doubly circular linked list
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
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    struct Node *temp = head;
    if (n == 1)
    {
        head = newNode;
        return;
    }
    else
    {
        for (int i = 0; i < n - 2; i++)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
        newNode->next = head;
        head->prev = newNode;
    }
}

void Delete(int n)
{
    struct Node *temp = head;
    struct Node *temp1 = head;
    if (n == 1)
    {
        while (temp->next != head)
        {
            temp = temp->next;
        }
        head = head->next;
        head->prev = temp;
        temp->next = head;
        free(temp1);
    }
    else
    {
        for (int i = 0; i < n - 2; i++)
        {
            temp1 = temp1->next;
        }
        struct Node *temp2 = temp1->next;
        temp1->next = temp2->next;
        temp2->next->prev = temp1;
        free(temp2);
    }
}

void Print()
{
    struct Node *temp = head;
    do
    {
        printf("%d  ", temp->data);
        temp = temp->next;
    } while (temp != head);
}
int main()
{
    head = NULL;
    Insert(2, 1);
    Insert(4, 2);
    Insert(6, 3);
    Insert(8, 4);
    Print();
    int n;
    printf("\nEnter position to delete:");
    scanf("%d", &n);
    if (n>4)
    {
        printf("Invalid position");
    }
    else
    {
        Delete(n);
        Print();
    }
}
