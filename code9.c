//inserting node at beginning, nth position and deletion
#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
struct Node *head;
void Insert(int data, int n)
{
    struct Node *new = (struct Node *)malloc(sizeof(struct Node));
    new->data = data;
    struct Node *temp = head;
    if (n == 1)
    {
        head = new;
        new->next = head;
        return;
    }
    else
    {
        for (int i = 0; i < n - 2; i++)
        {
            temp = temp->next;
        }
        new->next = temp->next;
        temp->next = new;
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
    printf("\nEnter a position to delete");
    scanf("%d", &n);
    Delete(n);
    Print();
}
